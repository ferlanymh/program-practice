#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

using namespace std;


class String
{
public:
	String(const char* str = "")//���캯��
		:_str(new char[strlen(str) + 1])//����һ���str�ȳ��Ŀռ䣬���ڴ�Ŷ����_str,��Ҫ����'\0'
		, _size(strlen(str))//�ַ������ȣ������_size��_capacity������'\0'
		, _capacity(_size)//���ٵ����ռ䣬����������Ҫ�ж�
	{
		strcpy(_str, str);//��������
	}
	// s1.Swap(s2); 


	void show()//��ӡ����
	{
		cout << "_str:" << _str << endl;
		cout << "_size:" << _size << endl;
		cout << "_capcity" << _capacity << endl;

	}


	void Swap(String& s)//��������,���������󽻻����г�Ա����
	{
		if (s._str != _str)//��������ַ�����ͬ��û�п�����Ҫ��
		{
			//swap�ǿ⺯��������ֱ�����ڽ���
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}
	}


	//String s2(s1) 
	String(const String& s)//�������캯��
						   /*:_str(new char[strlen(s._str) + 1])
						   ,_size(s._size)
						   ,_capacity(s._capacity)*/
	{
		/*strcpy(_str, s._str);*/      //��ͳд��


									   //�ִ�д��
		String s1(s._str);   //����һ����ʱ����ֱ�����ڽ�������ʱ������������Զ�����
		Swap(s1);

	}


	// s1 = s2 
	String& operator=(const String &s)
	{

		if (_str != s._str)//��������Լ����Լ���ֵ�����
		{
			//��ͳд�����Լ��ͷţ��Լ����ռ�
			//	delete[] _str;
			//	_str = new char[strlen(s._str) + 1];
			//	strcpy(_str, s._str);
			//	_size = s._size;
			//	_capacity = s._capacity;


			//�ִ�д����������ʱ����
			String tmp(s._str);
			Swap(tmp);

		}

		return *this;   //����*this���������������
	}


	~String()//�����������ͷ�_str�ռ�
	{
		delete[] _str;
		_str = NULL;

	}

	const char* c_str()//��ȡ�ַ�������Ϊ_str��˽�г�Ա��ֻ�������ַ�������
	{
		return _str;
	}


	void Expand(size_t n)//���ݣ����ݵ�_size+n�ֽ�
	{
		_capacity += n;
		char *tmp = new char[_capacity + 1];
		strcpy(tmp, _str);
		swap(tmp, _str);
		delete[] tmp;
	}


	void PushBack(char ch)//��_strβ�ϲ����ַ�ch
	{
		Insert(_size, ch);
	}


	//void PushBack(const char* str)

	void PopBack()//ɾ��_str���һ���ַ�
	{
		Erase(_size - 1, 1);
	}


	void Insert(size_t pos, char ch)//��pos�������ַ�ch
	{
		assert(pos <= _size);

		if (_size + 1 >= _capacity)//����
		{
			Expand(5);
		}



		memmove(_str + pos + 1, _str + pos, _size - pos + 1);
		_str[pos] = ch;
		_size++;
	}


	void Insert(size_t pos, const char* str)//�����⴦����һ���ַ���str
	{
		assert(pos <= _size);
		if (_size + strlen(str) >= _capacity)//����
		{
			Expand(strlen(str));
		}

		memmove(_str + pos + strlen(str), _str + pos, _size - pos + 1);
		strncpy(_str + pos, str, strlen(str));

		_size += strlen(str);

	}


	void Erase(size_t pos, size_t n = 1)//ɾ����pos������n���ַ���Ĭ��ɾ��1���ַ�
	{
		assert(pos < _size);
		assert(n <= _size);
		if (_size == 0)//Ϊ�ղ���ɾ��
		{
			cout << "the string is empty!!" << endl;
			return;
		}

		memmove(_str + pos, _str + pos + n, _size - n + 1);
		_size -= n;
	}


	size_t Find(char ch)//��_str�в����ַ�ch�Ƿ���ڣ��������򷵻ص�һ�γ���ʱ���±꣬�����ڷ���-1
	{
		char *tmp = strchr(_str, ch);//strchr:�����ַ�ch��һ�γ��ֵ�λ�ã����ڷ���ָ�룬�����ڷ���NULL
		if (tmp == NULL)
		{
			printf("'ch' is not in this string!!\n");
			return -1;
		}
		return tmp - _str;
	}


	size_t Find(const char* str)//��_str�в����Ӵ�str�������ڷ��ص�һ�γ��ֵ��±꣬�������򷵻�-1
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

