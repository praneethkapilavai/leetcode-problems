class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums2) {
        stack<int>st;
        // vector<int>nums = nums2 + nums2;
        int  m = nums2.size();
        vector<int>ans(m);
        for(int i = 2 * m - 1; i >= 0 ; --i){
            int ele = nums2[i % m];

            while(!st.empty() && st.top() <= ele) st.pop();
            ans[i % m] = ((st.empty()) ? -1 : st.top());
            st.push(ele);
        }

        return ans;

    }
};