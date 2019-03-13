#include<pthread.h>
#include<iostream>
#include<unistd.h>
using namespace std;

void* threadRun(void* arg)
{
  cout<<"i am new thread,my thread num is :"<<pthread_self()<<endl;

  return (void*)11;   
}


int main()
{
    pthread_t tid;
    void* status;
    pthread_create(&tid,NULL,threadRun,NULL);
    pthread_join(tid,&status);   
    cout<<"main thread is done,thread num is : "<<pthread_self()<<endl;
    cout<<"the exit num is :"<<(int)status<<endl;
    return 0;
}
