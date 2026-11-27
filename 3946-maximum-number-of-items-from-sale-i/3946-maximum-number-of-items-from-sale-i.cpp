class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& a, int b) {
        int n = a.size();

        map<int , int>mp;
        int mini = 1600;
        for(auto x : a) {
            mini = min(mini , x[1]);
            mp[x[0]]++;
        }
        // for(auto [ x  , y] : mp){
        //     cout << x <<  " " << y << endl;
        // }
        // cout << endl;
        map<int , int>frq;

        for(int i = 1 ; i <= 1500; ++i){
            if(mp.find(i) == mp.end()) continue;
            for(int j = i ; j <= 1500 ; j += i){
                if(mp[j] == 0) continue;
                frq[i] += mp[j];
            }
        }

        // for(auto [x  , y] : frq) {
        //     // if()
        //     cout << x << " " << y << endl;
        // }
        // cout << endl;

        // vector<pair<double , int>>ans;
        // int idx = 0;
        // for(auto x : a){
        //     // cout << (((double)frq[x[0]]) / ((double)x[1])) << endl;
        //     ans.push_back({ (((double)frq[x[0]]) / ((double)x[1])) , idx });
        //     idx++;
        // }

        vector<int> dp(b + 1, 0);
        for (auto x : a) {
            int fac = x[0], cost = x[1];
            int val = frq[fac];
            for (int j = b; j >= cost; --j) {
                dp[j] = max(dp[j], dp[j - cost] + val);
            }
        }
        int fans = 0;
        for (int spent = 0; spent <= b; ++spent) {
            fans = max(fans, dp[spent] + (b - spent) / mini);
        }

        return fans;
        
    }
};