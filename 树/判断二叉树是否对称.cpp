/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};
*/
class Solution {
public:
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (pRoot == NULL)//空树是对称二叉树，返回true
			return true;
		return check(pRoot->left, pRoot->right);//不为空树进入递归
	}

	bool check(TreeNode* left, TreeNode* right)//递归
	{
		if (left == NULL && right == NULL)//如果左右孩子都是空，返回true（第二层）
			return true;
		if (left == NULL || right == NULL)//倘若左右孩子都不都是空，则两边孩子必须都有值，不能半边为空
			return false;
		if ((left->val) == (right->val))//到这里说明两边都有孩子，就需要进行递归了
		{
			return check(left->left, right->right) && check(left->right, right->left);//如图第三层。对节点的左孩子与其兄弟节点右孩子的判断以及对节点右孩子与其兄弟节点左孩子的判断。
		}
		return false;//运行到这里，说明是两边孩子的值不同，那就没有比较的必要了，直接return false
	}

};