
//守护进程进化史：
//1.创建一个孤儿进程
//2.在孤儿进程内创建一个新会话
//3.修改默认工作路径为"/"
//4.重定向文件描述符到"/dev/null"
//5.设置文件的默认权限掩码
//6.确保自身不是会话首进程，从而不和任何终端建立联系(不是必须)
//7，成功逆袭成为守护进程
#include<iostream>
#include<unistd.h>
#include<stdlib.h>
#include<error.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
void MyDaemon()
{
    int pid = fork();
    if (pid < 0)
    {
        exit(-1);
    }
    else if (pid > 0)
    {
        exit(0);
    }
        //创建孤儿进程完成
        int sid = setsid();
        if (sid < 0)
        {
            exit(-1);
        }
        //创建会话完成
        
        chdir("/");//修改默认工作路径

        int fd = open("/dev/null",O_RDWR);
        dup2(fd,0);
        dup2(fd,1);
        dup2(fd,2);//文件描述符重定向

        umask(0);//修改默认权限

        pid = fork();
        if (pid < 0)
        {
            exit(-1);
        }
        else if (pid > 0)
        {
            exit(0);
        }
        //创建孙子进程，孙子进程不是该会话的首进程（受进程是刚才退出的孤儿进程，）。
        //这样做能保证该进程不和任何终端建立联系。

}//创建成功


int main()
{
    MyDaemon();
    while(1)
    {
      sleep(1);
    }
    return 0;
}
