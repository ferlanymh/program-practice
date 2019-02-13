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

//倘若要将各层的数据分开存放，我们要知道每层数据的个数。

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr)//empty
            return result;
        
        queue<TreeNode*> q;//put root in queue first
        q.push(root);
        
        while (!q.empty())
        {
            vector<int> tmp;
            tmp.clear();
            int size = q.size();//put this level's data into tmp
            
            while (size--)
            {
                TreeNode* top = q.front();
                tmp.push_back(top->val);
                
                if (top->left)
                    q.push(top->left);
                if (top->right)
                    q.push(top->right);
                
                q.pop();
            }
            
            //now tmp has all data in this level ,put them in result
            result.push_back(tmp);
        }
        return result;
        
    }
};
