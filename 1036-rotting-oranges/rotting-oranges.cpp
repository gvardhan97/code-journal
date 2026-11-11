// You are doing:

// Put all rotten oranges into the queue.
// Process the queue level by level.
// Each level represents 1 minute.
// Turn adjacent fresh oranges 1 → 2.
// At the end, if any 1 remains → return -1.
// Otherwise return ans - 1.

class Solution {
public:
    vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};

    int orangesRotting(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();

        queue<vector<int>> q;
        int fresh=0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(arr[i][j] == 2) {
                    q.push({i, j});
                }
                if(arr[i][j]==1)fresh++;
            }
        }

     int ans=0;
        while(!q.empty() and fresh>0) // fresh>0 needed : consider case when all are rotten , this ans variable still gives 1 which is wrong.
        {
            int sz=q.size();
            ans++;
         while(sz--)
         {
            auto it=q.front();q.pop();
            int i = it[0], j = it[1];

            for(int k = 0; k < 4; k++) {
                int newi = i + dir[k][0];
                int newj = j + dir[k][1];

                if(newi >= 0 && newj >= 0 && newi < m && newj < n &&
                   arr[newi][newj] == 1) {
                    arr[newi][newj] = 2;
                    q.push({newi, newj });
                    fresh--;
                }
            }
         }

        }

        if(fresh>0)return -1;

        return ans;
    }
};