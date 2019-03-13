/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

/*思路：
每条路径的起始都是根节点，所以我们必须首先遍历根节点，选择前序遍历
没遍历到一个结点，就将它计入路径序列，并且查看他是否是叶子结点及是否总值达到预期，达到则将当前路径计入最终结果。
如果不满足条件，则去递归得遍历他的左右子树，符合前序遍历

遇到叶子结点，在返回上层结点时，要将叶子节点踢出路径
*/
class Solution {
public:
    vector<vector <int>> allpath;//最终结果
    
    
    void findnode(TreeNode*root,int expectNumber,vector<int> path,int sum){
        path.push_back(root->val);
        sum+=root->val;
        
        if(root->left==nullptr&&root->right==nullptr){
            if(sum==expectNumber)
                allpath.push_back(path);
                return;
        }

        if(root->left!=nullptr)
            findnode(root->left,expectNumber,path,sum);
        if(root->right!=nullptr)
            findnode(root->right,expectNumber,path,sum);
        
        if (!path.empty())
            path.pop_back();
        
        return;
    }
    
    
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root==nullptr)
            return allpath;
        
        vector<int>path;//存储路径的各个值
        int sum=0;//总数
        findnode(root,expectNumber,path,sum);
        return allpath;
 
    }
};
