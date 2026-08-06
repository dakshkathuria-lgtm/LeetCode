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

    void f(TreeNode* root, vector<int>& ans, int x){
        if(root->left==nullptr and root->right == nullptr){
            ans.push_back(x);
            return;
        }

        if(root->left!=nullptr){
            f(root->left, ans, x*10 + root->left->val);
        }

        if(root->right!=nullptr){
            f(root->right, ans, x*10 + root->right->val);
        }

    }

    int sumNumbers(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }

        vector<int> ans;
        f(root, ans, root->val);
        int sum =0;
        for(int x:ans){
            sum+=x;
        }
        return sum;
    }
};