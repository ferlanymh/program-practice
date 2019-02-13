/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int count = 0;
    int countNodes(TreeNode* root) {
        if (root == nullptr)
            return count;
        
        queue<TreeNode*> q;
        q.push(root);
        count++;
        while (!q.empty())
        {
            TreeNode* top = q.front();
            if (top->left)
            {
                q.push(top->left);
                count++;
            }
            if (top->right)
            {
                q.push(top->right);
                count++;
            }
            q.pop();
        }
        return count;
    }
};