#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Determines if the given array can be split into two subsets
    // whose sums are equal using a tabulation DP approach
   
        
        bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1)return false;
        int target=sum/2;

        vector<int>prev(target+1,0);
         prev[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            vector<int>cur(target+1,0);
            for(int tar=0;tar<=target;tar++)
            {
                cur[tar]=prev[tar];
                if(tar>=nums[i])
                cur[tar]|=prev[tar-nums[i]];
            }
            prev=cur;
        }
        return prev[target];
    
    }
};


