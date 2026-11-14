class Solution {
public:
    vector<vector<int>>dp;
    int n;
    int fun(int ind,int state, vector<int>&arr)
    {
        if(ind>=n)
        {
            if(state==1)
            return -1e9;
            return 0;
        }
        if(dp[ind][state]!=-1e9)return dp[ind][state];
        if(state==0)//buy
        {
            return dp[ind][state]=max(fun(ind+1,state,arr), -arr[ind]+fun(ind+1,state^1,arr));
        }
        //sell
        return dp[ind][state]=max(fun(ind+1,state,arr),arr[ind]+fun(ind+2,state^1,arr));
    }
    int maxProfit(vector<int>& arr) {
         n=arr.size();
         int prev_buy=INT_MIN;
         int prev_sell=0;
        //  int prev_prev_buy=0;
         int prev_prev_sell=0;
         for(int i=0;i<n;i++){
            int curbuy=0;
            int cursell=0;
            //buy
            curbuy=max(prev_buy,-arr[i]+prev_prev_sell);

            //sell
            cursell=max(arr[i]+prev_buy,prev_sell);

            prev_prev_sell=prev_sell;
            prev_buy=curbuy;
            prev_sell=cursell;
         }
         return max(prev_buy,prev_sell);
         
        dp.resize(n,vector<int>(2,-1e9));
        return fun(0,0,arr);
        
    }
};
//0 means should buy