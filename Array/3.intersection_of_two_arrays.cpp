class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1,s2;
        vector<int> v;
        for(auto x:nums1)
            s1.insert(x);
        for(auto x:nums2)
            s2.insert(x);
        for(auto x:s2){
            if(s1.find(x)!=s1.end())
                v.push_back(x);
        }
        return v; 
    }
};