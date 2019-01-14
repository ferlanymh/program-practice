#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		//��ջ��ģ��ݹ�Ĳ���
		stack<TreeNode*> _stack;
		vector<int> ret;
		TreeNode* cur = root;
		while (cur || !_stack.empty())//ջ�ڻ���Ԫ��˵����Ԫ�ص���������û�б�����
		{
			while (cur)//��->������
			{
				_stack.push(cur);
				ret.push_back(cur->val);
				cur = cur->left;
			}

			//���꣬�������꣬����������

			TreeNode* _top = _stack.top();
			_stack.pop();
			cur = _top->right;
		}
		return ret;
	}
};