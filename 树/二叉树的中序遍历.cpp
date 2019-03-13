二叉树的中序遍历  递归版

class Solution {
public:
    vector<int> result;
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr)
            return result;
        
        inorderTraversal(root->left);
        result.push_back(root->val);
        inorderTraversal(root->right);
        
        
        return result;
    }
};

非递归版
用栈模拟实现

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//思路与前序非递归类似，遇到一个节点时，先入栈，然后一直进入左子树
class Solution {
public:
    vector<int> result;
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr)
            return result;
        
        stack <TreeNode*> s;
        TreeNode* cur = root;
        
        while (cur || (!s.empty()) )//cur不为空说明当前节点还可以遍历
	{	                         //stack不为空说明栈内元素可能还有孩子没有被遍历
        {
            while (cur)//一直入左结点
            {
                s.push(cur);
                cur = cur->left;
            }
            
            //已经最左，现在访问根节点
            TreeNode* top = s.top();
            result.push_back(top->val);
            
            cur = top->right;
            s.pop();//这里要把根pop出来，已经没有他的事儿了
        }
        return result;
    }
};