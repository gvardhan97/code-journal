class Solution {
public:
    int lengthOfLIS(vector<int>&nums) {
        vector<int>dp;
        dp.push_back(nums[0]);
         for(int i=1;i<nums.size();i++)
         {
         int ind=lower_bound(dp.begin(),dp.end(),nums[i])-dp.begin();
         if(ind>=dp.size())
         dp.push_back(nums[i]);
         else
         dp[ind]=nums[i];
         }
         return (int)dp.size();
    }
};