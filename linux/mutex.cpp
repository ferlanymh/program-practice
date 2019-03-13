#include<iostream>
#include<unistd.h>
#include<pthread.h>

using namespace std;
int tickets = 1000;
pthread_mutex_t mylock;
void* buytickets(void* arg)
{
    int i = (int)arg;
    for(;;)
    {
        //访问临界资源前加锁
        usleep(1000);
        pthread_mutex_lock(&mylock);
        if (tickets > 0)
        {
            tickets--;
            usleep(1000);
            cout<<i <<"号窗口正在售票，剩余票数为"<<tickets<<endl;
            pthread_mutex_unlock(&mylock);
           //访问完毕解锁，让别的线程能够再次竞争锁 
        }
        else
        {
            //这里也要解锁
            pthread_mutex_unlock(&mylock);
            cout<<"票已售罄，"<<i<<"号窗口关闭"<<endl;
            return NULL;
        }
    }
}


int main()
{
    int i = 0;
    pthread_t tid[5];
    cout<<"there is "<<tickets<<"tickets left";
    //对互斥锁进行初始化
    pthread_mutex_init(&mylock,NULL);
    for (i = 0;i < 5 ;i++)
    {
        pthread_create(&tid[i],NULL,buytickets,(void*)i);
    }
    for (i = 0; i < 5;i++)
    {
        pthread_join(tid[i],NULL);
    }
    pthread_mutex_destroy(&mylock);
    return 0;
}
