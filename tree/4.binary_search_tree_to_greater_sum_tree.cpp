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
    void inorder(TreeNode*p,int &t){
        if(p){
            inorder(p->right,t);
            t+=p->val;
            p->val=t;
            inorder(p->left,t);
        }
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(!root || (!root->left && !root->right))
            return root;
        int total=0;
        inorder(root,total);
        return root;
    }
};