class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& arr) {
        vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
int m=arr.size();
int n=arr[0].size();
int fresh=0;
vector<vector<int>>vis(m,vector<int>(n,0));
  queue<pair<int,int>>q;
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        if(arr[i][j]==0){
            q.push({i,j});

        }
        else 
        fresh++;
    }
  }
  int ans=0;
  while(q.size()!=0 and fresh>0){
    ans++;
    int sz=q.size();
    while(sz--){
        auto it=q.front();q.pop();
        int i=it.first;
        int j=it.second;
        for(int k=0;k<4;k++){
          int newi=i+dir[k][0];
          int newj=j+dir[k][1];
          if(newi>=0 and newj>=0 and newi<m and newj<n and arr[newi][newj]==1 and vis[newi][newj]==0){
            fresh--;
            vis[newi][newj]=ans;
            q.push({newi,newj});
          }
        }
    }
  }
  return vis;
	    
	}
};   
   