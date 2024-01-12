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
    bool isSame(TreeNode*p,TreeNode*q){
        if(p==nullptr && q==nullptr)
            return true;
        else if((p==nullptr && q!=nullptr) || (p!=nullptr && q==nullptr))
            return false;
        return (p->val==q->val && isSame(p->left,q->right) && isSame(p->right,q->left));
    }
    bool isSymmetric(TreeNode* root) {
        return isSame(root->left,root->right);
    }
};