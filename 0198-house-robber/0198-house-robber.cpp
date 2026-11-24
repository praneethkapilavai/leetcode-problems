class Solution {
public:
    int rob(vector<int>& nums) {
        int l0 = 0 , l1 = 0;
        int n = nums.size();

        for(int i = 0 ;i < n; ++i){
            int nl1 = max(l1 , l0);
            int nl0 = nums[i] + l1;
            l0 = nl0;
            l1 = nl1;
        }

        return max(l0 , l1);

    }
};