#include<iostream>
#include<unistd.h>
#include<pthread.h>

using namespace std;

pthread_mutex_t mylock;
pthread_cond_t mycond;
int count_  = 0;
int material = 10;
void* produce(void* arg)
{
    while (1)
    {
        //制作苹果派,解锁，睡眠一会儿，确保锁被eat拿到,否则当前进程刚释放锁又拿到锁
        pthread_mutex_lock(&mylock);
        material--;
        count_++;
        cout<<"[server say]: the pie is done, come and eat!"<<endl;
        pthread_cond_signal(&mycond);
        
        if (material == 0)
        {
            //没有原料了，释放锁后退出
            pthread_mutex_unlock(&mylock);
            cout<<"[server say]: there is no more material to make pie"<<endl;
            pthread_cond_broadcast(&mycond);//唤醒后的eat发现material为0，也退出。
            break;
        
        }
        pthread_mutex_unlock(&mylock);
        
        sleep(1);
        
    }
    return NULL;
}
void* eat(void* arg)
{
    while (1)
    {
        //先加锁，访问公共数据
        pthread_mutex_lock(&mylock);
        //没有苹果时需要等待
        if (count_ == 0)
        {
            pthread_cond_wait(&mycond,&mylock);
        }
        
        cout<<"[customer say]: woo,nice pie! eating..."<<endl;
        count_--;
        if (material == 0)
        {
            //没有原料了，没得吃
            cout<<"[customer say]: there is no pie,i have to go"<<endl;
            break;
        }
        
        pthread_mutex_unlock(&mylock);
        sleep(1);
    }
    
    pthread_mutex_unlock(&mylock);
    return NULL;
}
int main()
{
    pthread_t tid1,tid2;
    //初始化
    pthread_mutex_init(&mylock,NULL);
    pthread_cond_init(&mycond,NULL);
   
    //创建线程
    pthread_create(&tid1,NULL,produce,NULL);
    pthread_create(&tid2,NULL,eat,NULL);

    //等待线程
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    
    //销毁互斥量与条件变量
    pthread_mutex_destroy(&mylock);
    pthread_cond_destroy(&mycond);
    
    return 0;
}
