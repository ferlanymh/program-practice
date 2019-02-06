class Hungry
{
public:
	static Hungry* GetInstance()//对外提供一个静态的成员函数，返回我们的单例
	{
		return &onlyInstance;
	}

private:
	static Hungry onlyInstance;//定义一个静态的实例

private://将其他可能产生实例的函数都弄成私有，设置为删除函数是C++11的新写法
	Hungry() {};
	Hungry(const Hungry&) = delete;
	Hungry& operator=(const Hungry&) = delete;
	
};

Hungry Hungry::onlyInstance;//单例别忘了类外初始化

int main()
{
	Hungry* a = Hungry::GetInstance();
}