class Solution {
public:
   vector<vector<int>>dp;
    int fun(int ind, int state,vector<int>&prices){
        if(ind==prices.size())return 0;

        if(dp[ind][state]!=INT_MIN)return dp[ind][state];
        if(state==0)//buy
             return dp[ind][state]=max(-prices[ind]+fun(ind+1,1,prices),fun(ind+1,state,prices));
        // else if(state==1){//sell
            return dp[ind][state]=max(fun(ind+1,state,prices),prices[ind]+fun(ind+1,0,prices));
        }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.resize(n+1,vector<int>(2,INT_MIN));
        return fun(0,0,prices);
    }
};
//0 represents purchase
//1 represents sell