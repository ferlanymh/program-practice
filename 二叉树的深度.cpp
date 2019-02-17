

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/


//思路：一个二叉树倘若不为空，则他的深度是1 + 左子树和右子树中深度的较大值。递归实现即可。
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if (!pRoot)
            return 0;
        
        int left = TreeDepth(pRoot->left);
        int right = TreeDepth(pRoot->right);
        
        return 1+ (left > right ? left : right);
    }
};
