#include<iostream>
#include<stack>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//思路：
//		1.用两个栈分别记录到值a,b的路径
//      2.让两个栈当中多的那个栈出栈，直到两个栈size()相同
//      3.再同时出栈直到找到相同结点，相同结点即使最近祖先




class Solution {
public:
	bool makePath(TreeNode* root, stack<TreeNode*>& s, TreeNode* point)
	{
		if (root == nullptr)
			return false;

		s.push(root);
		if (root->val == point->val)
			return true;

		if (makePath(root->left, s, point) == true)
			return true;
		if (makePath(root->right, s, point) == true)
			return true;

		s.pop();
		return false;

	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

		stack<TreeNode*> s1;
		stack<TreeNode*> s2;

		makePath(root, s1, p);
		makePath(root, s2, q);

		if (s1.size() >= s2.size())
		{
			while (s1.size() > s2.size())
			{
				s1.pop();
			}
		}
		else
		{
			while (s2.size() > s1.size())
			{
				s2.pop();
			}
		}

		while (s1.top() != s2.top())
		{
			s1.pop();
			s2.pop();
		}

		return s1.top();



	}
};