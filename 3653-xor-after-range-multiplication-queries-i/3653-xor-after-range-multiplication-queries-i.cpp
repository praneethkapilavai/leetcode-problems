class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        const int M = 1e9 + 7;
        for(auto x : queries){
            for(int i = x[0] ; i <= x[1] ; i += x[2]){
                nums[i] =  1LL * nums[i] * x[3] % M;
                // nums[i] %= M;
            }
        }

        int ans = 0;
        for(auto i : nums) ans ^= i;
        return ans;
    }
};