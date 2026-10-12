class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long int ans=0;
        long long int mod=1e9+7;

        int b[30]={0};
        for(int x: nums)
          for(int i=0;i<30;i++)
             if(x&(1<<i))b[i]++;

        while(k-->0){
            long long int x=0;
            for(int i=0;i<30;i++){
                if(b[i]>0){
                    x|=1LL<<i;
                    b[i]--;
                }
            }
            ans=(ans+x*x)%mod;
        }
        return (int)ans;
    }
};
