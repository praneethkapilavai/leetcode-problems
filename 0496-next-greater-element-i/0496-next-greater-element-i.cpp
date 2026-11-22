class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        
        int n = nums1.size() , m = nums2.size();
        st.push(nums2[m - 1]);

        vector<int>ans(1e4 + 2);
        ans[nums2[m - 1]] = -1;

        for(int i = m - 2 ; i >= 0 ; --i){
            if(st.empty()){
                ans[nums2[i]] = -1;
                st.push(nums2[i]);
                continue;
            }
            while(!st.empty() && nums2[i] > st.top()){
                st.pop();
            }
            if(!st.empty()) ans[nums2[i]] = st.top();
            else ans[nums2[i]] = -1;
            st.push(nums2[i]);

            // else {
            //     ans[nums2[i]] = st.top();
            // }    
        }

        vector<int>fans(n);
        int i = 0;
        for(auto x : nums1){
            fans[i++] = ans[x];
        }
        return fans;

    }
};