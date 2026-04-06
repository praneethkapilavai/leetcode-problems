class Solution {
public:
    int robotSim(vector<int>& c, vector<vector<int>>& o) {
        set<pair<int  , int>> ob;

        for(auto i : o) ob.insert({i[0] , i[1]});

        int n = c.size() , ans = 0;
        char dir = 'N';
        int ci = 0 , cj = 0 ; 

        for(int i = 0 ; i < n ; ++i){
            if(c[i] > 0){
                if(dir == 'E'){
                    while(c[i] -- ){
                        ci++;
                        if(ob.find({ci , cj}) != ob.end()) {ci--;break;}
                        ans = max(ans , ci * ci + cj * cj);
                    }
                }
                else if(dir == 'W'){
                     while(c[i] -- ){
                        ci--;
                        if(ob.find({ci , cj}) != ob.end()) {ci++;break;}
                        ans = max(ans , ci * ci + cj * cj);
                    }
                }
                else if(dir == 'N'){
                     while(c[i] -- ){
                        cj++;
                        if(ob.find({ci , cj}) != ob.end()) {cj--;break;}
                        ans = max(ans , ci * ci + cj * cj);
                    }
                }
                else{
                     while(c[i] -- ){
                        cj--;
                        if(ob.find({ci , cj}) != ob.end()) {cj++; break;}
                        ans = max(ans , ci * ci + cj * cj);
                    }
                }

            } 
            else if(c[i] == -2) {
                if(dir == 'N') dir = 'W';
                else if(dir == 'W') dir = 'S';
                else if(dir == 'S') dir = 'E';
                else  dir = 'N';
            }
            else {
                if(dir == 'N') dir = 'E';
                else if(dir == 'W') dir = 'N';
                else if(dir == 'S') dir = 'W';
                else  dir = 'S';
            }
        }
        return ans;

    }
};