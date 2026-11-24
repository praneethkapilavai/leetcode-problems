class Solution {
public:
    int countSquares(vector<vector<int>>& a) {
        int n = a.size() , m = a[0].size();
        vector<int>dp(m);
        
        int sm = 0;
        for(int i = 0 ; i < m ; ++i) {
            dp[i] = a[0][i];
            sm += dp[i];
            // cout << dp[i] << " ";
        }
        // cout << endl;
        
        for(int i = 1  ; i < n ; ++i){
            vector<int>ndp(m);
            ndp[0] = a[i][0];
            sm += ndp[0];

            // cout << ndp[0] << " ";
            for(int j = 1 ; j < m ; ++j){
                if(a[i][j] == 0) {ndp[j] = 0; continue;}
                ndp[j] = 1 + min({dp[j] , dp[j - 1] , ndp[j - 1]});
                sm += ndp[j];
                // cout << ndp[j] << " ";
            }
            // cout << endl;

            dp = ndp;
        }

        // for(int i = 0 ; i < n; ++i){
        //     for(int j = 0 ; j < m ; ++j) cout << 
        // }

        return sm;


    }
};