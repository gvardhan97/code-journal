class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
       string ans="" ;
        if(sum==0)return ans;
      while(num--)
          {
              for(int i=9;i>=0;i--)
                  {
                      if(sum>=i)
                      {
                          sum-=i;
                          ans.push_back('0'+i);break;
                      }
                  }
          }
        if(sum>0 or ans[0]=='0')return "";
        return ans;
    }
};