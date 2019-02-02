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
	void Mirror(TreeNode *pRoot) {
		if (pRoot == nullptr)//为空则不需要转换
			return;

		if (pRoot->left == nullptr && pRoot->right == nullptr)//叶子结点
			return;

		TreeNode* tmp = pRoot->left;交换当前层
			pRoot->left = pRoot->right;
		pRoot->right = tmp;

		if (pRoot->left)//如果左子树不为空则递归左子树
			Mirror(pRoot->left);
		if (pRoot->right)//如果右子树不为空则递归右子树
			Mirror(pRoot->right);
	}
};