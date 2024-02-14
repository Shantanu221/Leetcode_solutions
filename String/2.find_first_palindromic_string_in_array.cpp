class Solution {
public:
    bool ispal(string s){
        for(int i=0;i<s.size()/2;i++){
            if(s[i]!=s[s.size()-i-1])
                return false;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        string s="";
        for(auto x:words){
            if(ispal(x)){
                s=x;
                break;
            }
        }
        return s;
    }
};