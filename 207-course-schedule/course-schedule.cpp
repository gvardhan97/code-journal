class Solution {
public:
vector<int>vis,pathvis;
unordered_map<int,vector<int>>adj;
  bool fun(int node){
    vis[node]=1;
    pathvis[node]=1;
    for(auto it:adj[node]){
        if(vis[it]==1 and pathvis[it]==1)return true;//found cycle
        else if(vis[it]==1)continue;
        // else if(vis[it]==0)
           if( fun(it) ==true)return true;
        
    }
    pathvis[node]=0;
    return false;
  }
    bool canFinish(int n, vector<vector<int>>& edg) {
        for(auto it:edg){
            adj[it[0]].push_back(it[1]);
        }
        vis.resize(n,0);pathvis.resize(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i])
              {
                if(fun(i))
                return false;
              }
        }
       return true;
    }
};