#include<iostream>
#include<unistd.h>
#include<errno.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<sys/epoll.h>
int ServerInit(const char* ip,short port)
{
    int listen_sock = socket(AF_INET,SOCK_STREAM,0);
    if (listen_sock < 0)
    {
        perror("socket error");
        return -1;
    }

    sockaddr_in addr;
    socklen_t len = sizeof(addr);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip);
    addr.sin_port = htons(port);
    setsockopt(listen_sock, SOL_SOCKET, SO_REUSEPORT, (char*)&addr, sizeof(addr));
    int ret = bind(listen_sock,(struct sockaddr*)&addr,len);

    if (ret < 0)
    {
        perror("bind error");
        return -1;
    }

    ret = listen(listen_sock,5);
    if (ret < 0)
    {
        perror("listen error");
        return -1;
    }
    return listen_sock;
}



void ListenSocketProcess(int listen_sock,int epoll_fd)
{
    struct sockaddr_in client_addr;//存对端的地址信息
    socklen_t len = sizeof(client_addr);

    int newsock = accept(listen_sock,(struct sockaddr*)&client_addr,&len);
    if (newsock < 0)
    {
        perror("accept error!");
        return;
    }

    //将新的socket描述符插入epoll对象
    epoll_event new_ev;
    new_ev.data.fd = newsock;
    new_ev.events = EPOLLIN;//只关注新的socket的读就绪

    int ret = epoll_ctl(epoll_fd,EPOLL_CTL_ADD,newsock,&new_ev);
    if (ret < 0)
    {
        perror("epoll_ctl error!");
        return ;
    }

    std::cout<<"[client "<<newsock<<"]"<<"connected!"<<std::endl;
    return ;
}


void NewSocketProcess(int newsock,int epoll_fd)//进行一次读写操作
{
    //注意断开连接也会触发读就绪，所以要从epoll对象中删除
    char buff[1024] = {0};
    ssize_t size = read(newsock,buff,sizeof(buff) - 1);
    if (size < 0)//出错
    {
        perror("read error!");
        return;
    }
    else if (size ==0)//链接断开
    {
        close(newsock);
        epoll_ctl(epoll_fd , EPOLL_CTL_DEL , newsock , NULL);
        std::cout<<"[client "<< newsock <<"]"<<"disconnected!"<<std::endl;
        return;
    }
    else//read正常
    {
        buff[size]='\0';
        std::cout<<"[client "<<newsock<<"]"<<"say: "<<buff<<std::endl;
        memset(buff,0x00,1024);
        // strcpy(buff,"what are you f**king saying?");
        //int ret = write (newsock,buff,strlen(buff));
        int ret = write (newsock,"hello\n",6);
       
        if (ret < 0)
        {
            perror("write error!");
            return ;
        }
        return ;
    }
      
}
int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cout<<"usage: server [ip] [port]"<<std::endl;
        return -1;
    }
    //初始化服务器
    int listen_sock = ServerInit(argv[1],atoi(argv[2]));
    if (listen_sock < 0)
    {
        perror("Serverinit Failed!");
        return -1;
    }
    //初始化成功
    std::cout<<"Serverinit Success!"<<std::endl;

    //初始化epoll对象
    int epoll_fd = epoll_create(10);
    if (epoll_fd < 0)
    {
        perror("epoll create error!");
        return -1;
    }

    //添加listen_sock进入epoll对象
    struct epoll_event ev;
    ev.events = EPOLLIN;//关注监听socket的读就绪
    ev.data.fd = listen_sock;//这里将listen_sock置入ev.data.fd，供后面判断时用
    int ret = epoll_ctl(epoll_fd,EPOLL_CTL_ADD,listen_sock,&ev);
    
    if (ret < 0)
    {
        perror("epoll_ctl error!");
        return -1;
    }

    //使用epoll_wait等待文件描述符就绪。
    while (1)
    {
        //创建监听返回的结果集
        epoll_event output[100];
        int nfds = epoll_wait(epoll_fd,output,100,-1);//epoll_wait会返回读就绪的socket的epoll_event结构体，
                                                      //分类判断
        if (nfds < 0)
        {
            perror("epoll_wait error!");
            return -1;
        }

        //运行到这里说明已经返回了结果集，依次对output里面的socket描述符进行处理。
        
        int i = 0;
        for (;i < nfds;i++)
        {
            if (output[i].data.fd == listen_sock)
            {
                //说明这是一个建立链接的socket，我们需要调用accept函数。
                //在函数里要将新的newsocket插入epoll对象，所以传入
                ListenSocketProcess(listen_sock,epoll_fd);
            }
            else//说明这是一个正常的读写操作，属于newsocket
                //我们只在这里进行一次
            {
                NewSocketProcess(output[i].data.fd,epoll_fd);
            }
        }
    }
    return 0;
}
