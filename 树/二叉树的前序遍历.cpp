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
		//用栈来模拟递归的操作
		stack<TreeNode*> _stack;
		vector<int> ret;
		TreeNode* cur = root;
		while (cur || !_stack.empty())//栈内还有元素说明该元素的右子树还没有被遍历
		{
			while (cur)//根->左子树
			{
				_stack.push(cur);
				ret.push_back(cur->val);
				cur = cur->left;
			}

			//根完，左子树完，该右子树了

			TreeNode* _top = _stack.top();
			_stack.pop();
			cur = _top->right;
		}
		return ret;
	}
};