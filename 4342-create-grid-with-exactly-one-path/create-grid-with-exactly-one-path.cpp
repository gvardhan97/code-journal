class Solution {
public:
    vector<string> createGrid(int m, int n) {
       vector<string>grid;
       for(int i=0;i<m;i++){
        string str="";
        for(int j=0;j<n;j++)str.push_back('#');
        grid.push_back(str);
       }
       for(int i=0;i<m;i++)grid[i][0]='.';
       for(int j=0;j<n;j++)grid[m-1][j]='.';
       return grid;
    }
};