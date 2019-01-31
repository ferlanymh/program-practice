template<class T>
class SharedPtr//模拟实现shared_ptr
{
public:
	SharedPtr(T* tmp = nullptr)
		:_ptr(tmp)
		,count(new int(1))
	{}

	~SharedPtr()
	{
		if (--(*count) == 0)
		{
			delete _ptr;
			delete count;
		}
			
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}
	
	SharedPtr(SharedPtr<T>& tmp)
		:_ptr(tmp._ptr)
		,count(tmp.count)
	{
		(*count)++;
	}


	SharedPtr<T>& operator=(SharedPtr<T>& tmp)
	{
		
		if (_ptr != tmp._ptr)//排除自己给自己赋值的可能
		{
			//先要判断原来的空间是否需要释放
			if (--(*count) == 0)
			{
				delete _ptr;
				delete count;
			}
			_ptr = tmp._ptr;
			count = tmp.count;
			(*count)++;
		}
		return *this;//考虑连等的可能
		
		
	}
private:
	
	T* _ptr;
	int* count;
};
