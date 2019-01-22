#include <iostream>
#include <unistd.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
//目标；实现一个udp的简单聊天程序，本文件为服务端
//udp_server通信步骤：
//1.创建socket套接字

//2.给套接字绑定地址信息
//3.接收客户端的数据
//4.向客户端回复数据
//5.通信结束，关闭socket
int main()
{
  //1.创建socket套接字
  int sockfd =  socket(AF_INET,SOCK_DGRAM ,0);
  if (sockfd < 0)
  {
    std:: cout<<"create socket error!!"<<std::endl;
    return -1;
  }

  //2.构建sockaddr_in结构存储地址信息，注意sockaddr_in只能用于IPv4
  //
  struct sockaddr_in serv_addr;
  socklen_t len = sizeof(serv_addr);
  serv_addr.sin_port = htons(10000);//端口号  sin_port为无符号短整型2个字节
  serv_addr.sin_family = AF_INET;//类型
  serv_addr.sin_addr.s_addr = inet_addr("192.168.184.137");//ip地址  typedef uint32_t in_addr_t 32位无符号整数
  int ret = bind(sockfd,(struct sockaddr*)&serv_addr,len);//倘若绑定，就将绑定的地址作为自己的ip地址和端口号
  if (ret < 0)
  {
    std::cout<<"bind error!!"<<std::endl;
    return -1;
  }

  std::cout<<"udp_server is ready,let's chat"<<std::endl;
  while (1)
  {
    //3接收客户端的数据
    char buff[1024] = {0};//用来接收客户端发来的数据
    sockaddr_in cli_addr;//用于
    len = sizeof(cli_addr);//地址信息长度
    ssize_t size = recvfrom(sockfd, buff, 1023,0,(struct sockaddr*)&cli_addr,&len);//cli_addr接收对端地址信息
    if (size < 0)
    {
      std::cout<<"no data to recv"<<std::endl;
      return -1;
    
    }
    printf("client[%s %d]say: %s\n",inet_ntoa(cli_addr.sin_addr),ntohs(cli_addr.sin_port),buff);
    //4.向客户端发送数据
    memset(buff,0x00,len);
    std::cin >> buff;
    sendto(sockfd,buff, strlen(buff), 0,  (struct sockaddr *)&cli_addr, len);
    //sendto第五个参数存储对端的地址信息

  }
  close(sockfd);



  return 0;
}
