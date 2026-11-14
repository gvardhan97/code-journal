class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n=arr.size();
        vector<int>prev(n,0);
        for(int i=0;i<n;i++)
        {
            vector<int>cur(n,0);
            for(int j=0;j<n;j++)
            {
                cur[j]=arr[i][j];
                int curmin=INT_MAX;
                if(j-1>=0)curmin=min(curmin,prev[j-1]);//left
                curmin=min(curmin,prev[j]);//up
                if(j+1<n)curmin=min(curmin,prev[j+1]);//right
                 cur[j]+=curmin;
            }
            prev=cur;
        }
       int ans=INT_MAX;
       for(int i=0;i<n;i++)ans=min(ans,prev[i]);
       return ans;

    }
};