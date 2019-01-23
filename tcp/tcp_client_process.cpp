#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<signal.h>
//目标：创建一个简单的tcp聊天客户端
//
//1.创建套接字socket
//2.绑定地址信息(无需绑定，绑定可能出错，且我们在服务端可以用recv函数接收到客户端的地址信息)
//3.与服务端建立连接(connect)
//4.向服务端发送数据
//5.接收服务端发来的数据
//6.不聊了关闭套接字

//
//如何判断TCP连接断开?(重点)
//对于接收方来说----recv返回值为0,代表连接断开
//对于发送方来说----每次调用send都会触发连接断开异常,接收到系统发送的SIGPIPE信号,导致进程退出.
//如果不想要发送方退出,我们要在程序开始的时候对SIGPIPE做自定义/忽略处理
void sigcb(int signo)
{
  std::cout<<"the server is stopped"<<std::endl;
  exit(0);
}
int main(int argc , char* argv[])
{
    signal(SIGPIPE,sigcb);
    if (argc != 3)//检查是否缺少参数
    {
        perror("you should put more paramaters!");
        return -1;
    }
    //1创建套接字sockfd
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    if (sockfd < 0)
    {
        perror("create socket error!");
        return -1;
    }

    //2不绑定客户端的地址信息
    //
    //创建一个地址信息块，存储服务端的地址信息，后面connect，send用得上
    struct sockaddr_in server_addr;//仅用于IPv4
    socklen_t len = sizeof(server_addr);
    server_addr.sin_family = AF_INET;//类型
    server_addr.sin_port = htons(atoi(argv[2]));//端口是无符号short型，这里要先将参数转为int，再对低2个字节进行网络字节序的转换。
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);//inet_addr可以完成字符串的网络字节序转换。

    //3.申请与服务端建立连接。
   int ret =  connect(sockfd, (struct sockaddr *)&server_addr, len);
   if (ret < 0)
   {
        perror("connect error!");
        close(sockfd);
        return -1;
   }

   //至此，链接链接建立成功
   
   while (1)
   {
        //4.向服务端发送数据
        
        char buff[1024] = {0};
        scanf("%s",buff);
        send(sockfd,buff,strlen(buff),0);

        //5.从服务端接收数据
        memset(buff,0x00,1024);
        int ret = recv(sockfd,buff,1024,0);
        if (ret < 0)
        {
            //客户端接收数据失败
            perror("recv error!");
            close(sockfd);
            return -1;
        }
        else if (ret ==0)
        {
            //对端已经关闭
            perror("the tcp_server is closed!");
            close(sockfd);
            return -1;
        }
        //输出buff的内容,要注意ip和端口从网络字节序到主机字节序的转换
        printf("server say: %s\n",buff);


   }
    
    close(sockfd);
    return 0;
}
