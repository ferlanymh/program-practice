template<class T>
class UniquePtr//模拟实现unique_ptr
{
public:
	UniquePtr(T* tmp = nullptr)
		:_ptr(tmp)
	{}

	~UniquePtr()
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
	
	
private:
	UniquePtr(const UniquePtr<T>& tmp) = delete;
	UniquePtr<T>& operator=(const UniquePtr<T>& tmp) = delete;
	T* _ptr;
};
