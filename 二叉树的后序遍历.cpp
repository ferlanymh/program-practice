/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 //二叉树的后序遍历   递归方法  
class Solution {
public:
    vector<int> result;
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr)
            return result;
        
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        result.push_back(root->val);
        
        return result;
    }

	
	
	//非递归方法
	

class Solution {
public:
    vector<int> result;
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr)//empty
            return result;
        
        stack<TreeNode*> s;
        TreeNode* cur = root;
        TreeNode* flag = nullptr;//标记是否有遍历过右子树
        while (cur || (!s.empty()) )
        {
            while (cur)
            {
                s.push(cur);
                cur = cur->left;
            }
            
            //已经到达最左结点，接下来应该判断是否要走右边结点还是输出根节点
            
            TreeNode* top = s.top();
            //如果已经右子树为空或者已经遍历过右子树，则可以访问根节点了。
            if ( (top->right == nullptr) || (flag == top->right))
            {
                result.push_back(top->val);
                s.pop();//根节点遍历过后不再需要这个结点
                flag = top;//将当前结点做好标记，等到取上层结点的时候通过flag得知右子树是否被遍历过。 
            }
            else//说明右子树存在且尚未被访问
            {
                cur = top->right;
            }
        }
            return result;
        
        
    }
};