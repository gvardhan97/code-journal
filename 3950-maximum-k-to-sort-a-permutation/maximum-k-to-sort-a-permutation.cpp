class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans=(1<<20)-1;
        // cout<<ans;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==i)continue;
            ans=ans & nums[i];
        }
        if(ans>1e5)return 0;
        return ans;
    }
};