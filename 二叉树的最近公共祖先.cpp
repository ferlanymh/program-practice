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
//	1.用两个栈分别记录到值a,b的路径
//      2.让两个栈当中多的那个栈出栈，直到两个栈size()相同
//      3.再同时出栈直到找到相同结点，相同结点即使最近祖先




class Solution {
public:
	bool makePath(TreeNode* root, stack<TreeNode*>& s, TreeNode* point)//和前序遍历类似，递归的寻找point，并吧沿途结点都入栈
	{
		if (root == nullptr)
			return false;

		s.push(root);
		if (root->val == point->val)
			return true;

		if (makePath(root->left, s, point) == true)//左找到了就不用在往右找了
			return true;
		if (makePath(root->right, s, point) == true)//右找到了直接退出
			return true;

		s.pop();//一个结点的左右都没有找到目标值，那么这个结点已经不在去往该结点的路径上
		return false;

	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

		stack<TreeNode*> s1;
		stack<TreeNode*> s2;

		makePath(root, s1, p);
		makePath(root, s2, q);

		if (s1.size() >= s2.size())//让两个栈的大小变得相等
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

		while (s1.top() != s2.top())//同时出栈，直到结点的值相等，该节点就是最近的公共祖先
		{
			s1.pop();
			s2.pop();
		}

		return s1.top();



	}
};
