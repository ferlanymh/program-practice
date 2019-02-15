
int quick_sort1(int* a,int left,int right)//左右指针法
{
	

	int key = a[right];
	int begin = left;
	int end = right;

	while (begin < end)
	{
		while (begin < end && a[begin] <= key)//从左向右找到第一个比key大的值
			begin++;
		while (begin < end && a[end] >= key)//从右向左找到第一个比key小的值
			end--;

		if (begin < end)//因为在移动过程中可能begin和end已经重合，我们要判断一下
		{
			swap(a[begin], a[end]);
		}
		else
			break;

	}
	swap(a[begin], a[right]);//此时将key放到begin/end重合处，这个值就已经到达了最终位置。
	return begin;//返回begin位置，对左右子序列再进行排序
}

int quick_sort2(int* a, int left, int right)//挖坑法
{
	int holl = right;//标记坑的位置
	int key = a[holl];//事先存储坑的值
	int begin = left;
	int end = right;

	while (begin < end)
	{
		while (begin < end && a[begin] <= key)//从左往右找第一个比holl大的值。
			begin++;

		if (begin < end)//代表在begin==end前找到我们要的比a[holl]大的值
		{
			a[holl] = a[begin];
			holl = begin;
		}

		while (begin < end && a[end] >= key)//从右向左找第一个比holl小的值
			end--;

		if (begin < end)//代表在begin==end前找到我们要的比a[holl]小的值
		{
			a[holl] = a[end];
			holl = end;//end处变成新的坑
		}
	}

	a[begin] = key;//此时begin和end都在holl处，直接将实现保存的key值放进坑内即可。
	return begin;
}

int quick_sort3(int* a, int left, int right)//前后指针法
{
	int key = a[right];
	int first = left;
	int second = first - 1;

	while (first < right)
	{
		if (a[first] < key)
		{
			++second;
			if (second != first)
				swap(a[first], a[second]);
		}
		++first;
	}

	swap(a[first], a[++second]);
	return second;
}



void quick_sort_NonR(int* a, int left, int right)//快速排序非递归（左右指针法）
{
	assert(a);
	stack<int> s;
	
	s.push(left);//注意此时我们先入左再入右，下面在取出时应该先取右后取左
	s.push(right);

	while (!s.empty())
	{
		int end = s.top();//先取右后取左
		s.pop();
		int begin = s.top();
		s.pop();
		
		int mid = quick_sort1(a, begin, end);//调用单趟的快排

		if (mid - 1 > begin)//说明左边有子序列
		{
			
			s.push(begin);
			s.push(mid - 1);
		}
		if (mid + 1 < end)//说明右边有子序列
		{
			s.push(mid + 1);
			s.push(end);
		}
	}	
}
