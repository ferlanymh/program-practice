class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        return bst(sequence,0,sequence.size()-1);
    }
    
    bool bst(vector<int> sequence,int begin,int end){
        if(sequence.empty()||begin>end)
            return false;
        int root=sequence[end];
        int i=begin;
        for(;i<end;++i)
            if(sequence[i]>root)//i坐标为右子树第一个节点
                break;
        for(int j=i;j<end;++j)//右子树如果出现小于root的结点，则序列出错。
            if(sequence[j]<root)
                return false;
        bool left=true;
        if(i>begin)//有左子树。递归遍历
            left=bst(sequence,begin,i-1);
        bool right=true;
        if(i<end-1)//有右子树，递归遍历
            right=bst(sequence,i,end-1);
        return left&&right;
    }
};
