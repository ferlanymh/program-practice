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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> result;
        if (root == nullptr)
            return result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty())
        {
            TreeNode* cur = q.front();
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
            result.push_back(cur->val);
            q.pop();
        }
        return result;
    }
};