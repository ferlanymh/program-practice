输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）


/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* p1, TreeNode* p2)
    {
        bool result = false;
        if (p1 != nullptr && p2 !=nullptr)//只有两个都不为空才比较
        {
            if (p1->val == p2->val)// 如果找到了对应Tree2的根节点的点
            {
                result = doestree1hastree2(p1,p2); 、 //以这个根节点为为起点判断是否包含Tree2

            }

            if (!result)//如果p1和p2当前值不同，则递归的去p1的左子树查找是否有和p2相同值的起点
            {
                result = HasSubtree(p1->left,p2);
            }

            if (!result)//如果还不相同，则进入p1的右子树查找起点
            {
                result = HasSubtree(p1->right,p2);
            }

       
        
        }   
        
        return result;
        
       
    }
    bool doestree1hastree2(TreeNode* p1, TreeNode* p2)
    {
       
        if (p2 == nullptr)//说明p2对应完毕且都对应上了，p2是p1的子结构
            return true;
        if (p1 == nullptr)//说明p2没对应完，p1就完了，则p2不是p1的子结构
            return false;
        
        if (p1->val != p2->val)//只要有一个结点对应不上，那么p2就不是p1的子结构
            return false;
            
        return (doestree1hastree2(p1->left,p2->left) && doestree1hastree2(p1->right,p2->right));//递归的比较两个树的左右结点
    }
};
