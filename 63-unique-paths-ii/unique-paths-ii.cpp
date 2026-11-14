class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
     int m=arr.size()   ;
     int n=arr[0].size();
     vector<int>prev(n,0);
      prev[0]=1;
      

       for(int i=0;i<m;i++)
       {
        vector<int>cur(n,0);
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==1)
              {cur[j]=0;continue;}//stone;
            if(j==0)
              cur[j]+=prev[j];
            else
              cur[j]=prev[j]+cur[j-1];
        }
        prev=cur;
       }
       return prev[n-1];
    }
};