class Solution {
public:
    bool checkString(string s) {
        int n = s.size() , f = 0;

        for(int i = n - 1; i >= 0 ; --i){
            if(s[i] == 'a') {f = 1; continue;}
            if(f && s[i] == 'b') return 0;
        }

        return 1;
    }
};