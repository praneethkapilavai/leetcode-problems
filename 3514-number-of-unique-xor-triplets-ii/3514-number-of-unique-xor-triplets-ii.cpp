class Solution {
public:
    /*  
        we can do this in n3 
        but we have to optmise n2 logn or n2 ...
        the max val of xor == 1500..
    */
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>xors;

        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < n ; ++j){
                xors.insert(nums[i] ^ nums[j]);
            }
        }
        unordered_set<int>txors;
        for(int i = 0 ; i < n ; ++i){
            for(auto j : xors) txors.insert(j ^ nums[i]);
        }
        // for(auto i : txors) cout << i << " " ; 

        return (int)txors.size();
    }
};