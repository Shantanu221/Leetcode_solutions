class Solution {
public:
    int coinNum(vector<int>& coins,int amount,vector<int> &dp){
        if(amount<0) return INT_MAX;
        if(amount==0) return 0;
        if(dp[amount]!=-1) return dp[amount];
        int best=INT_MAX;
        for(auto x:coins){
            if(coinNum(coins,amount-x,dp)!=INT_MAX)
                best=min(best,1+coinNum(coins,amount-x,dp));
        }
        return dp[amount]=best;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(10001,-1);
        if(coinNum(coins,amount,dp)==INT_MAX)
            return -1;
        return coinNum(coins,amount,dp);
    }
};