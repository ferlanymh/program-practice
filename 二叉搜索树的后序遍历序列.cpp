


//递归
class Solution {
public
    bool VerifySquenceOfBST(vectorint sequence) {
 
        int size = sequence.size();
        if(0==size)
        {
            return false;
        }
 
        return isLastOrder(sequence, 0, size-1);
    }
 
private
    bool isLastOrder(vectorint& sequece, int b, int e)
    {
        if(b==e)
        {
            return true;
        }
        int mid = b;
        while(sequece[mid++]sequece[e] && mide);
 
        int tmp = mid;
        while (sequece[tmp++]sequece[e] && tmpe);
        if(tmpe)
        {
            return false;
        }
 
        if(mid==b  mid==e)
        {
            return isLastOrder(sequece, b, e-1);
        }
        else
        {
            return (isLastOrder(sequece, b, mid-1) && isLastOrder(sequece, mid, e-1));
        }
    }
};
 
/*非递归 
非递归也是一个基于递归的思想：
左子树一定比右子树小，因此去掉根后，数字分为left，right两部分，right部分的
最后一个数字是右子树的根他也比左子树所有值大，因此我们可以每次只看有子树是否符合条件
即可，即使到达了左子树左子树也可以看出由左右子树组成的树还想右子树那样处理
 
对于左子树回到了原问题，对于右子树，左子树的所有值都比右子树的根小可以暂时把他看出右子树的左子树
只需看看右子树的右子树是否符合要求即可*/

class Solution {
public
    bool VerifySquenceOfBST(vectorint sequence) {
        int size = sequence.size();
        if(0==size)return false;
 
        int i = 0;
        while(--size)
        {
            while(sequence[i++]sequence[size]);
            while(sequence[i++]sequence[size]);
 
            if(isize)return false;
            i=0;
        }
        return true;
    }
};
