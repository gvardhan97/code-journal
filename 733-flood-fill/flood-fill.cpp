class Solution {
public:
vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
    vector<vector<int>> floodFill(vector<vector<int>>& arr, int sr, int sc, int color) {
        int orgclr=arr[sr][sc];
        if(orgclr==color)return arr;

        
        int m=arr.size();
        int n=arr[0].size();

        queue<pair<int,int>>q;
        q.push({sr,sc});
        arr[sr][sc]=color;


        while(q.size()!=0)
        {
           // cout<<"HI"<<endl;
            auto it=q.front();
            q.pop();
            int i=it.first;int j=it.second;
            for(int k=0;k<4;k++)
            {
                int newi=i+dir[k][0];
                int newj=j+dir[k][1];
                if(newi>=0 and newj>=0 and newi<m and newj<n and arr[newi][newj]==orgclr ){
                    arr[newi][newj]=color;
                    q.push({newi,newj});
                }
            }
        }
      return arr;

    }
};