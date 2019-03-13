#include<iostream>
#include<mutex>
#include<thread>
using namespace std;
class Lazy
{
public:

	class gc//内嵌垃圾回收类
	{
	public:
		~gc()
		{
			if (Lazy::OnlyInstance)
				delete Lazy::OnlyInstance;
		}
	};

	static gc g;//定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象

	static Lazy* GetInstance()//返回单例
	{
		if (OnlyInstance == nullptr)
		{
			m_mutex.lock();
			if (OnlyInstance == nullptr)//？为什么要双层检查
			{
				OnlyInstance = new Lazy();
			}
			m_mutex.unlock();
		}
		return OnlyInstance;
	}

private:
	static Lazy* OnlyInstance;//单例指针
	static mutex m_mutex;//互斥量
private:
	Lazy() {};
	Lazy(const Lazy&) {};
	Lazy& operator=(const Lazy&) {};
};

Lazy* Lazy::OnlyInstance = nullptr;//初始化
mutex Lazy::m_mutex;
Lazy::gc g;
