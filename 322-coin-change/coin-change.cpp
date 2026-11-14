// I solve this problem using Dynamic Programming. My DP state is dp[i][j], which represents the minimum number of coins needed to make sum j using coins from index 0 to i. I initialize every value with INF because initially I assume every sum is impossible to make. As I find valid combinations, I replace INF with the minimum number of coins. For every coin, I have two choices: skip it or take it. If I skip it, I use prev[j]. If I take it, I use 1 + cur[j-arr[i]] because the same coin can be used multiple times. I take the minimum of these two choices. If the final answer is still INF, I return -1 because the target cannot be formed. The time complexity is O(n × target) and the space complexity is O(target)."

// Common Follow-up Questions

// Q. Why initialize with INF instead of 0?

// Because 0 means the sum can be formed using zero coins, which is not true for most sums. INF represents an impossible state until we find a valid way to make that sum.

// Q. Why use cur instead of prev?

// Because this is an Unbounded Knapsack problem. I can use the same coin multiple times, so after taking it once, I stay in the current row.

// Q. Why use min()?

// Because the problem asks for the minimum number of coins required to make the target amount



class Solution {
public:
//  int fun(int ind,int tar,vector<int>&arr,vector<vector<int>>&dp)
//  {
//     if(ind<0)
//     {if(tar==0)return 0;
//     return 1e7;
//     }
//     if(dp[ind][tar]!=-1)return dp[ind][tar];

//     int take=1e7;int nottake=1e7;
//     if(arr[ind]<=tar)
//      take=1+fun(ind,tar-arr[ind],arr,dp);
//     nottake=0+fun(ind-1,tar,arr,dp);
//     return dp[ind][tar]=min(take,nottake);
//  }
    int coinChange(vector<int>& arr, int tar) 
    {
      int n=arr.size();
     vector<int>prev(tar+2,1e7),cur(tar+2,1e7);
     prev[0]=0;
     for(int i=0;i<n;i++)
     {
        for(int j=0;j<=tar;j++)
        {
           if(j>=arr[i])
            cur[j]=min(prev[j],1+cur[j-arr[i]]);
           else cur[j]=prev[j];
       }
       prev=cur;
     }
     if(prev[tar]>=1e7)return -1;
     return prev[tar];
    }
};