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
		if (pRoot == NULL)//�����ǶԳƶ�����������true
			return true;
		return check(pRoot->left, pRoot->right);//��Ϊ��������ݹ�
	}

	bool check(TreeNode* left, TreeNode* right)//�ݹ�
	{
		if (left == NULL && right == NULL)//������Һ��Ӷ��ǿգ�����true���ڶ��㣩
			return true;
		if (left == NULL || right == NULL)//�������Һ��Ӷ������ǿգ������ߺ��ӱ��붼��ֵ�����ܰ��Ϊ��
			return false;
		if ((left->val) == (right->val))//������˵�����߶��к��ӣ�����Ҫ���еݹ���
		{
			return check(left->left, right->right) && check(left->right, right->left);//��ͼ�����㡣�Խڵ�����������ֵܽڵ��Һ��ӵ��ж��Լ��Խڵ��Һ��������ֵܽڵ����ӵ��жϡ�
		}
		return false;//���е����˵�������ߺ��ӵ�ֵ��ͬ���Ǿ�û�бȽϵı�Ҫ�ˣ�ֱ��return false
	}

};