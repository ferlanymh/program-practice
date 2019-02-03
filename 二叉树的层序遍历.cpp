/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/


/*思路：设置一个队列，将根节点入队，
每次取到一个结点，都看一下他是否有左右结点，如果有，则入队。在将该结点置入result中。*/
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