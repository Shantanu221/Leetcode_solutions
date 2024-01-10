class Solution {
public:
    int lengthOfLastWord(string s) {
        // if(s.size()==0)
        //     return 0;
        int i,j=s.size()-1;
        while(s[j]==' ' && j>0)
            j--;
        if(j==0)
            return 1;
        i=j;
        while(s[i]!=' ' && i>0)
            i--;
        if(i==0 && s[i]!=' ')
            i--;
        return j-i;
    }
};