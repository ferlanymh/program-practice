//目标：实现一个生产者消费者模型，使用队列作为双方通信的缓冲区，线程耦合度低
#include<iostream>
#include<unistd.h>
#include<pthread.h>
#include<queue>
#include<stdlib.h>
#include<time.h>
using namespace std;



class BlockQueue
{
  private:
    queue<int> q;//缓冲队列
    pthread_mutex_t mylock;//互斥量
    pthread_cond_t mycond;//条件变量

  public:
    BlockQueue()
    {
      //init mylock and mycond 
      pthread_mutex_init(&mylock,NULL);
      pthread_cond_init(&mycond,NULL);

    }

    void LockQueue()
    {
      pthread_mutex_lock(&mylock);
    }

    void UnlockQueue()
    {
      pthread_mutex_unlock(&mylock);
    }


    void WakeOneThread()
    {
      pthread_cond_signal(&mycond);
    }
    void PushData(const int& data)
    {
      //操作队列前加锁，操作后解锁
      LockQueue();
      q.push(data);
      UnlockQueue();
      cout<<"the data has been pushed,the num is "<<data<<endl;
      sleep(1);  
      WakeOneThread();

    }

    bool IsEmpty()
    {
      return q.size();
    }


    void PopData(int &data)
    {
      LockQueue();
      while (IsEmpty())
      {
        pthread_cond_wait(&mycond,&mylock);
      }
      data = q.front();
      q.pop();
      UnlockQueue();
      cout<< "the data has been poped,the value is "<< data <<endl;
    }

    ~BlockQueue()
    {
      pthread_mutex_destroy(&mylock);
      pthread_cond_destroy(&mycond);
    }
};

void *Produce(void *arg)
{
  BlockQueue* bq = (BlockQueue*)arg;
  srand((unsigned long)time(NULL));
  while (1)
  {
      int data = rand()%100 + 1;
      bq->PushData(data);
      sleep(1);
  }
  return NULL;
}



void *Customer(void *arg)
{
  BlockQueue* bq = (BlockQueue*)arg;
  while (1)
  {
      int data;
      bq->PopData(data);
  }
  return NULL;
}

int main()
{
  pthread_t tid1,tid2;

  BlockQueue bq;
  pthread_create(&tid1,NULL,Produce,(void*)&bq);
  pthread_create(&tid2,NULL,Customer,(void*)&bq);

  pthread_join(tid1,NULL);
  pthread_join(tid2,NULL);




  return 0;
}
