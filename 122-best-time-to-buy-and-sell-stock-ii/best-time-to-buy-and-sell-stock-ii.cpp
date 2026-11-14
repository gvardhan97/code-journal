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
    
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        int prev_buy=INT_MIN;  //so on first index i cannot sell
        int prev_sell=0;       //so on first index i can buy
        for(int i=0;i<n;i++){
            int curbuy,cursell;
            //buy 2 options, take options, max(do nothing or (buy and add prevsell)
             curbuy=max(-arr[i]+prev_sell,prev_buy);//buy or skip
            //sell
            cursell=max(arr[i]+prev_buy,prev_sell);

            prev_buy=curbuy;
            prev_sell=cursell;
        }
        return max(prev_buy,prev_sell);
         dp.resize(n+1,vector<int>(2,INT_MIN));
        return fun(0,0,arr);
    }
};
//0 represents purchase
//1 represents sell