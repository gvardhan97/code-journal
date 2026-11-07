class Solution {
public:
vector<vector<int>>dp;
int n;
    int fun(int ind,int target, vector<int>&arr)
    {
        
        if(target==0)return 1; 
        if(ind<0)
        return 0;
        
       
        if(dp[ind][target]!=-1)return dp[ind][target];
        //take nottake
        int take=0; int nottake=0; 
        if(target>=arr[ind])
        take=fun(ind,target-arr[ind],arr);
        nottake=fun(ind-1,target,arr);
        return dp[ind][target]=take+nottake;
    }
    int change(int target, vector<int>& arr) 
    {
        n=arr.size(); 
        sort(arr.begin(),arr.end());
        dp.resize(n,vector<int>(target+1,-1));
        return fun(n-1,target,arr);
    }
};