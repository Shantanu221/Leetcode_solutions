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
    void pro(TreeNode*p,vector<int>&v){
        if(p){
            v.push_back(p->val);
            pro(p->left,v);
            pro(p->right,v);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> a;
        pro(root,a);
        return a;
    }
};