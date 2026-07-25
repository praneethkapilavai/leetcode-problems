class Solution {
public:
    // depends on the bits right  
    /*
        1
       1 0
       1 1
      1 0 0
      1 0 1
      1 1 0
      1 1 1 

      have to return the upperbound fo 2 pow ??
    */
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n == 2 || n == 1) return n;
        if((n & (n - 1)) == 0) return n * 2;

        // return nearest pow of n
        int i = 0;
        while(n){
            ++i;
            n /= 2;
        }
        return (1 << i);
    }
};