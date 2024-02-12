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
    void treemap(TreeNode*p,unordered_map<int,int> &mp){
        if(!p) return;
        mp[p->val]++;
        treemap(p->left,mp);
        treemap(p->right,mp);
    }
    vector<int> findMode(TreeNode* root) {
        if(!root->left && !root->right) return {root->val};
        unordered_map<int,int> mp;
        vector<int> ans;
        treemap(root,mp);
        int maxf=INT_MIN;
        for(auto x:mp){
            if(x.second>maxf){
                maxf=x.second;
            }
        }
        for(auto x:mp){
            if(x.second==maxf){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};