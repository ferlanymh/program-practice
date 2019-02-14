选择排序
每次从n个数据中选择最大/小的数据，与第一个数据进行交换。至此最大/小的数据已定
再从剩余的n-1个数据中找出最大/小的数据，与第二个数据进行交换。
...
直到排序完成

时间复杂度O(N^2).始终是O(N^2).所以是效率较低的排序,一般不怎么用.
空间复杂度O(1)
因为要交换,所以他不是一个稳定的排序算法


void choose_sort(int* a, int size)
{
    int i = 0;
    for (;i < size;i++)
    {
        int index = i;
        int max = i;//这次循环中最大值的下标
        for (;index < size;index++)
        {
            if (a[index] > a[max])
            {
                max = index;//更新最大值下标
            }
        }
        int tmp = a[max];
        a[max] = a[i];
        a[i] = tmp;

    }
}