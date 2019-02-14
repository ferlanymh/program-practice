希尔排序：
选定一个间隔值gap，对隔gap的元素划为一组，分别进行插入排序，然后缩小gap
（gap = gap/3+1），当gap==1时，就相当于直接插入排序。此时的插入排序复杂度不是O（n^2）。

希尔排序是对直接插入排序的优化。
2. 当gap > 1时都是预排序，目的是让数组更接近于有序。当gap == 1时，数组已经接近有序的了，这样就
会很快。这样整体而言，可以达到优化的效果。我们实现后可以进行性能测试的对比。
3. 希尔排序的时间复杂度不好计算，需要进行推导，推导出来平均时间复杂度： O(N^1.3—N^2）
4. 稳定性：不稳定




template<typename T>
void ShellSort(T *arr, int size)
{

    int gap = size;
    while (gap > 1)
    {
     //注意这里的增量每次取除3+1。
        gap = gap / 3 + 1;
        int pos = 0;
        //在这里希尔排序实际操作是按照顺序方式操作，并不是预想的一个模块一个模块的。操作的时候是对gap中的每一个进行希尔排序完以后再到下一个gap进行希尔排序。
          for (int index = pos + gap; index < size; index++)
        {
            pos = index - gap;
            T tmp = arr[index];
            while (pos >= 0&&arr[pos] < tmp)
            {
                arr[pos+gap] = arr[pos];
                pos -= gap;
            }
            arr[pos+gap] = tmp;
        }

    }
}

