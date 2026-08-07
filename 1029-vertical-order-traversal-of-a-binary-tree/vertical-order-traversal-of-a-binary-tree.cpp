/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void dfs(TreeNode* root, int col, int level, map<int, map<int, multiset<int>>>& mp){
        if(root==nullptr){
            return;
        }

        mp[col][level].insert(root->val);
        dfs(root->left, col-1, level+1, mp);
        dfs(root->right, col+1, level+1, mp);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map<int, multiset<int>>> mp;

        dfs(root, 0,0,mp);
        for(auto x: mp){
            vector<int> current;
            for(auto y: x.second){
                for(int z : y.second)
                    current.push_back(z);
            }   
            ans.push_back(current);
        }
        return ans;
    }
};