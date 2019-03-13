class String
{
public:
	
	int& GetRefCount()//取到头部的4个字节，方便赋值
	{
		return (*(int*)(str - 4));
	}

	String(const char *_str="")//构造函数，str头部多开4个字节来存储引用计数，
		:str(new char [strlen(_str)+5])//5中  4个字节存引用计数，1个字节存'\0'
	{
		str += 4;
		strcpy(str, _str);
		GetRefCount() = 1;

	}

	String(const String &s)//拷贝构造，只需让新对象的指针指向被拷对象的str，并让引用计数+1即可
		:str(s.str)
	{
		GetRefCount()++;
	}

	String& operator=(const String& s)//赋值运算符重载，返回值为string&可以连等
	{
		if (str != s.str)//防止出现s1=s1的情况
		{
			if (--GetRefCount() == 0)
			{
				delete[](str - 4);
			}
			str = s.str;
			GetRefCount()++;
		}
		return *this;

	}

	
	void copy_on_write()//判断修改对象字符串时会不会影响到其他对象
	{
		if (GetRefCount() > 1)//如果有不止1个对象指向该字符串，那么就要另外开辟空间
		{
			String tmp(str);//剥削手段
			swap(str, tmp.str);
			GetRefCount() = 1;
		}//对象tmp析构，不会影响s1对象
	}
		
	char* c_str()
	{
		return str;
	}
	
	char& operator[](size_t pos)
	{
		copy_on_write();
		return str[pos];
	}

	~String()
	{
		if (--GetRefCount() == 0)//说明当前析构的对象是最后一个指向该串的对象
		{
			delete[](str - 4);
		}
	}
private:
	char *str;
};
int main()
{
	String s1("hello");
	String s2(s1);
	s2[0] = 'x';
	String s3("world");
	s3 = s1;


	return 0;
}s