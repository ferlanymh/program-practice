堆排序
顾名思义,用堆进行排序.

堆排序（适合记录较多的情况使用）：

升序----大堆（目的通过向下调整每次获得最大的数据放最后）
降序----小堆（目的通过向下调整每次获得最小的数据放最后）

拿升序举例，我们要对一个数组进行升序排序时，构建好大堆，此时堆顶是这些数据中最大的数据。
我们将这个数据与数组的最后一个数进行交换，然后对堆的size--。
这样最大的数据就已经被我们放到了最终位置。接着因为刚才的交换，此时堆顶已经不是最大的数据了，在进行一次向下调整，再次获取最大的数据。并与size - 1位置的数据进行交换。

所以时间复杂度是O（N*logN）N此选取最大值*logN向下调整
空间复杂度: O(1)
稳定性:不稳定



void adjustdown(int index,int size)
    {
        int parent = index;//父亲
        int child = parent * 2 + 1;//左孩子


        while (child < size)//向下调整直到堆的末尾
        {
            if (child + 1 < size && _a[child + 1] > _a[child])//取到左右孩子中的较大值
            {
                child++;
            }
            if (_a[parent] < _a[child])//与父亲进行比较
            {
                //说明要交换
                int tmp = _a[parent];
                _a[parent] = _a[child];
                _a[child] = tmp;
            }

            parent = child;
            child = parent * 2 + 1;

        }
    }
    


void heap_sort()
    {
        assert(_a);
        int size = _size;
        while (size > 1)
        {
            swap(_a[0], _a[size - 1]);
            size--;
            adjustdown(0,size);
            

        }
    }