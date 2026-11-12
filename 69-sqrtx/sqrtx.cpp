class Solution {
public:
    int mySqrt(int x) {
        long long lo=1;
        long long hi=x+0ll;
        long long ans=hi;
        while(lo<=hi){
            long long mid=(lo+hi)/(2+0ll);
            if(mid*mid<=x)
            {
                ans=mid;
                 lo=mid+1;
                // hi=mid-1;
            }
            else
            hi=mid-1;// lo=mid+1;
        }
        return (int)ans;
    }
};