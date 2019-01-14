#include<iostream>
#include<stack>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//˼·��
//		1.������ջ�ֱ��¼��ֵa,b��·��
//      2.������ջ���ж���Ǹ�ջ��ջ��ֱ������ջsize()��ͬ
//      3.��ͬʱ��ջֱ���ҵ���ͬ��㣬��ͬ��㼴ʹ�������




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