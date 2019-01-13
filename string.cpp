#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

using namespace std;


class String
{
public:
	String(const char* str = "")//构造函数
		:_str(new char[strlen(str) + 1])//开辟一块和str等长的空间，用于存放对象的_str,需要算上'\0'
		, _size(strlen(str))//字符串长度，这里的_size和_capacity都不记'\0'
		, _capacity(_size)//开辟的最大空间，后面扩容需要判断
	{
		strcpy(_str, str);//拷贝即可
	}
	// s1.Swap(s2); 


	void show()//打印函数
	{
		cout << "_str:" << _str << endl;
		cout << "_size:" << _size << endl;
		cout << "_capcity" << _capacity << endl;

	}


	void Swap(String& s)//交换函数,另两个对象交换所有成员变量
	{
		if (s._str != _str)//如果两个字符串相同就没有拷贝必要了
		{
			//swap是库函数，可以直接用于交换
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}
	}


	//String s2(s1) 
	String(const String& s)//拷贝构造函数
						   /*:_str(new char[strlen(s._str) + 1])
						   ,_size(s._size)
						   ,_capacity(s._capacity)*/
	{
		/*strcpy(_str, s._str);*/      //传统写法


									   //现代写法
		String s1(s._str);   //创建一个临时对象，直接用于交换，临时对象出作用域自动析构
		Swap(s1);

	}


	// s1 = s2 
	String& operator=(const String &s)
	{

		if (_str != s._str)//避免出现自己给自己赋值的情况
		{
			//传统写法，自己释放，自己开空间
			//	delete[] _str;
			//	_str = new char[strlen(s._str) + 1];
			//	strcpy(_str, s._str);
			//	_size = s._size;
			//	_capacity = s._capacity;


			//现代写法，创建临时对象
			String tmp(s._str);
			Swap(tmp);

		}

		return *this;   //返回*this，适用于连等情况
	}


	~String()//析构函数，释放_str空间
	{
		delete[] _str;
		_str = NULL;

	}

	const char* c_str()//提取字符串，因为_str是私有成员，只能用这种方法返回
	{
		return _str;
	}


	void Expand(size_t n)//扩容，扩容到_size+n字节
	{
		_capacity += n;
		char *tmp = new char[_capacity + 1];
		strcpy(tmp, _str);
		swap(tmp, _str);
		delete[] tmp;
	}


	void PushBack(char ch)//在_str尾上插入字符ch
	{
		Insert(_size, ch);
	}


	//void PushBack(const char* str)

	void PopBack()//删除_str最后一个字符
	{
		Erase(_size - 1, 1);
	}


	void Insert(size_t pos, char ch)//在pos处插入字符ch
	{
		assert(pos <= _size);

		if (_size + 1 >= _capacity)//扩容
		{
			Expand(5);
		}



		memmove(_str + pos + 1, _str + pos, _size - pos + 1);
		_str[pos] = ch;
		_size++;
	}


	void Insert(size_t pos, const char* str)//在任意处插入一个字符串str
	{
		assert(pos <= _size);
		if (_size + strlen(str) >= _capacity)//扩容
		{
			Expand(strlen(str));
		}

		memmove(_str + pos + strlen(str), _str + pos, _size - pos + 1);
		strncpy(_str + pos, str, strlen(str));

		_size += strlen(str);

	}


	void Erase(size_t pos, size_t n = 1)//删除从pos处向后的n个字符，默认删除1个字符
	{
		assert(pos < _size);
		assert(n <= _size);
		if (_size == 0)//为空不能删除
		{
			cout << "the string is empty!!" << endl;
			return;
		}

		memmove(_str + pos, _str + pos + n, _size - n + 1);
		_size -= n;
	}


	size_t Find(char ch)//在_str中查找字符ch是否存在，若存在则返回第一次出现时的下标，不存在返回-1
	{
		char *tmp = strchr(_str, ch);//strchr:查找字符ch第一次出现的位置，存在返回指针，不存在返回NULL
		if (tmp == NULL)
		{
			printf("'ch' is not in this string!!\n");
			return -1;
		}
		return tmp - _str;
	}


	size_t Find(const char* str)//在_str中查找子串str，若存在返回第一次出现的下标，不存在则返回-1
	{
		assert(str);
		char *tmp = strstr(_str, str);

		if (tmp)
		{
			return tmp - _str;
		}
		return -1;
	}

	// s1 + 'a' 
	String operator+(char ch)
	{
		String s1(_str);
		s1.PushBack(ch);
		return s1;
	}


	String& operator+=(char ch)
	{
		PushBack(ch);
		return *this;
	}


	String operator+(const char* str)
	{
		String s1(_str);
		s1.Insert(strlen(_str), str);
		return s1;
	}


	String& operator+=(const char* str)
	{
		Insert(strlen(_str), str);
		return *this;
	}

	bool operator>(const String& s)
	{
		if (strcmp(_str, s._str) > 0)
		{
			return true;
		}
		return false;
	}


	bool operator>=(const String& s)
	{
		return (*this > s) | (*this == s);
	}

	bool operator<(const String& s)
	{
		return !(*this >= s);
	}


	bool operator<=(const String& s)
	{
		return !(*this > s);
	}


	bool operator==(const String& s)
	{
		if (strcmp(_str, s._str) == 0)
		{
			return true;
		}
		return false;
	}


	bool operator!=(const String& s)
	{
		return !(*this == s);
	}

private:
	char* _str;
	size_t _size;
	size_t _capacity;
};

