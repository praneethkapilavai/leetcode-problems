class Solution {
public:
    int get(int l ,int r , vector<int> & w){
        auto up = upper_bound(w.begin() , w.end(), r);
        auto lo = lower_bound(w.begin() , w.end(), l);
        return up - lo;
    }

    int maxWalls(vector<int>& r, vector<int>& dis, vector<int>& w) {
        vector<array<int  , 2>> x(r.size());
        int n = r.size() , m = w.size();

        for(int i = 0 ; i < n ; ++i){
            x[i][0] = r[i];
            x[i][1] = dis[i];
        }

        sort(x.begin() , x.end());
        sort(w.begin() , w.end());

        x.push_back({(int)1e9 , 0});

        vector<vector<int>>dp(n , vector<int>(2));

        dp[0][0] = get(x[0][0] - x[0][1] , x[0][0] , w);
        dp[0][1] = get(x[0][0] + x[0][1] , x[0][0] , w);

        for(int  i = 1; i < n; ++i){
            int pos = x[i][0]  ,dist = x[i][1];

            dp[i][0] = dp[i - 1][0] + get(max(x[i - 1][0] , pos - dist) , pos, w);
            dp[i][1] = dp[i - 1][1] + get(pos , min(x[i + 1][0] , pos + dist ), w);

            int res = dp[i - 1][1] ;
            if(x[i - 1][0] + x[i - 1][1] >= pos - dist){
                res += (get(max(x[i - 1][0]  , pos - dist) , pos, w ) - get(x[i - 1][0] , min(pos  , x[i - 1][0] + x[i - 1][1]), w));
            }
            else {
                res += get(pos - dist , pos , w);
            }

            dp[i][0] = max(dp[i][0] , res);
        }
        return max(dp[n-1][0] , dp[n-1][1]);
    }
};