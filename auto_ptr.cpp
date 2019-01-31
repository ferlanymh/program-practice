template<class T>
class AutoPtr//模拟实现auto_ptr
{
public:
	AutoPtr(T* tmp = nullptr)
		:_ptr(tmp)
	{}

	~AutoPtr()
	{
		if (_ptr)
			delete _ptr;
	}

	T& operator*()
	{
		return *_ptr;
	}
		
	T* operator->()
	{
		return _ptr;
	}

	AutoPtr(AutoPtr<T>& _tmp)//拷贝构造
		:_ptr(_tmp._ptr)
	{
		_tmp._ptr = nullptr;
	}

	AutoPtr<T>& operator=(AutoPtr<T>& _tmp)//赋值运算符重载，记得要释放原空间
	{
		if (_tmp._ptr != _ptr)
		{
			if (_ptr)
				delete _ptr;
			_ptr = _tmp._ptr;
			_tmp._ptr = nullptr;
		
		}
		return *this;
	}
private:
	T* _ptr;
};
