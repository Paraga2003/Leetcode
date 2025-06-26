class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // int totalpss =0;
        // for(int i=1;i<trips.size();i++){

        //     if(trips[i][0]>capacity) return false;
        //     if(trips[i][1]<=trips[i-1][2] ){
        //         totalpss++;
        //     }else{
        //         totalpss = 0;
        //     }
        //     if(totalpss>capacity) return false;
        // }
        // return true;
        map<int,int> changes;
        for(int i=0;i<trips.size();i++){
            int numPassengers = trips[i][0];
            int from = trips[i][1];
            int to = trips[i][2];

            changes[from] += numPassengers;   
            changes[to] -= numPassengers; 
        }
        int currpassenger =0;
        for(auto &[loc,chng]:changes){
            currpassenger+=chng;
            if(currpassenger>capacity){
                return false;
            }
        }
        return true;
        
    }
};