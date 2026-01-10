class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        // 1,,,6
        // .......5---cannot occur more than rollmax[5] times consectively
        // ------
        // .......
        // dp[i][lastNumber] = 
        // the number of distinct sequences if ith number equals lastNumber and by respecting the constraints
        // dp[i][5] = "5" + 
        //             "55"
        //             "555"
        //              "5555"
        //              "555..rollmax(times)"
      vector<vector<int>> dp(n+2,vector<int>(7,0));
    //   cout<<rollMax[6]<<"\n";
    //   dp[1][1] = 1
     for(int last = 1;last<=6;last++) dp[1][last]=1;
      for(int i=2;i<=n;i++){
          for(int lastNumber = 1; lastNumber<=6;lastNumber++){
               dp[i][lastNumber] = 0;
               int possOcurence = min(i,rollMax[lastNumber - 1]);
               for(int j=1;j<=possOcurence;j++){
                    if(i==j){
                            dp[i][lastNumber] = (dp[i][lastNumber] + 1)%1000000007;
                            continue;

                     }
                     for(int prevLast = 1;prevLast<=6;prevLast++){
                          if(prevLast == lastNumber) continue;
                             dp[i][lastNumber] = (dp[i][lastNumber] + dp[i-j][prevLast])%(1000000007);
                         
                     }
               }
          }
      }
      int ans = 0;
      for(int last = 1;last<=6;last++){
        //  cout<<"last "<<last<<"--"<<" dp "<<dp[n][last]<<"\n";
         ans = (ans + dp[n][last])%(1000000007);
      }
      return (ans);

    }
};
