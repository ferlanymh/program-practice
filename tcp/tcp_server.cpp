//目标：创建一个基于tcp的简单聊天程序
#include<iostream>
#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
//思路：
//服务端：
//1.创建套接字listen_socket
//2.为套接字绑定服务器地址
//3.开始监听listen_socket
//4.接收链接成功，使用new_socket
//5.与new_socket收发数据
//6.关闭socket

//    /usr/include/netinet/in.h
int main(int argc,char* argv[])
{
  if (argc != 3)
  {
    perror("you should put more paramaters!");
    return -1;
  }

  //1.创建监听套接字listen_sock,参数依次为版本IPv4，流式套接字，默认tcp
  int listen_sock = socket(AF_INET,SOCK_STREAM,0);
  if (listen_sock < 0)
  {
    perror("create socket failed!");
    return -1;
  }

  //2.为服务器绑定地址信息,以后凡是向服务器发起连接请求，都会首先让listen_sock处理。

  struct sockaddr_in server_addr; //sockaddr_in仅用于IPv4
  socklen_t size = sizeof(server_addr);
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(atoi(argv[2]));//先将命令行第二个参数(端口号)转为整形再转为网络字节序。
  server_addr.sin_addr.s_addr = inet_addr(argv[1]);//将命令行第一个参数(ip地址)转为网络字节序。

  int ret = bind(listen_sock,(struct sockaddr*)&server_addr,size);
  if (ret < 0)
  {
    perror("bind error!");
    return -1;
  }

  //3.监听listen_sock套接字
  if (listen(listen_sock,5))
  {
    perror("listen error!");
    return -1;
  }

  while(1)
  {
    //4.接收新链接
    struct sockaddr_in client_addr;
    socklen_t size = sizeof(client_addr);
    int newsock = accept(listen_sock,(struct sockaddr*)&client_addr,&size);//阻塞等待式的接收新链接,client_addr接收客户端的地址信息
    if (newsock < 0)
    {
      perror("accept error!");//注意，此处说明该链接无效，但不影响别的链接，应该重新回到上面再次接收新链接
      continue;
    }
    //接收成功
    std::cout<<"get a new connection!"<<std::endl;
    //开始用newsock和客户端进行数据通信
    while(1)
    {
      //5.收发数据
      char buff[1024] = {0};

      int len = recv(newsock , buff , 1024 , 0);
      if (len < 0)//recv返回值小于0时，接收数据错误
      {
        perror("recv error!");
        close(newsock);
        continue;
      }
      else if (len == 0)//recv返回值等于0时，说明对端(客户端)关闭
      {
        perror("the opposite process is stopped!");
        close(newsock);
        continue;
      }
      //运行到此处说明接收成功，接受的数据存放在buff中

      printf("client[ %s %d] say: %s\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port),buff);
      //注意此处对数据要从网络字节序转化为主机字节序

      memset(buff,0x00,1024);
      std::cin >> buff; 
      send(newsock,buff,strlen(buff),0);

    }
  }
  close(listen_sock);
  return 0;
}
