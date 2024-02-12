class Solution {
public:
    int calc(int n,vector<int>&dp){
        if(n==0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        int minc=n;
        for(int i=1;i*i<=n;i++){
            minc=min(minc,1+calc(n-i*i,dp));
        }
        return dp[n]=minc;
    }
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return calc(n,dp);
    }
};