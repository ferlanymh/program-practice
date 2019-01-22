#include<iostream>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<stdio.h>
#include<arpa/inet.h>
//目标：实现一个简单的udp客户端
//通信步骤：
//1.创建socket套接字
//2.绑定地址信息（不推荐！因为绑定有可能失败，且我们只要数据能发送出去即可）
//3.向客户端发送数据
//4.接收客户端发来的数据
//5.关闭套接字
int main()
{
    //1.创建套接字
    int sockfd = socket(AF_INET,SOCK_DGRAM,0);
    if (sockfd <0)
    {
        std::cout<<"create socket error"<<std::endl;
    }

    //2.绑定客户端的地址信息,不做！！
    
    struct sockaddr_in serv_addr;//构建服务端的地址信息块,用于后面发送
    socklen_t size = sizeof(serv_addr);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(10000);
    serv_addr.sin_addr.s_addr = inet_addr("192.168.184.137");
    

    std::cout<<"udp_client is ready,let's chat!"<<std::endl;
    while(1)
    {
        //3.向服务端发送数据
        char buff[1024] = {0};
        std::cin >> buff;
        sendto(sockfd,buff, strlen(buff), 0 ,(struct sockaddr *)&serv_addr,size);
        
        //4.接收服务端发来的数据
        memset(buff,0x00,1024);
        size_t len =  recvfrom(sockfd, buff, 1023, 0,(struct sockaddr *)&serv_addr, &size);
        if (len < 0)
        {
            std::cout<<"no data to recv"<<std::endl;
            close(sockfd);
            return -1;
        }
        
        printf("client[%s %d]say: %s\n",inet_ntoa(serv_addr.sin_addr),ntohs(serv_addr.sin_port),buff);

    }
    close(sockfd);
    return 0;
}
