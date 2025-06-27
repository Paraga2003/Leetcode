class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        
       
        for(int i= left;i<=right;i++){
            bool covered = false;
            
            for(int k = 0;k<ranges.size();k++){
                if(i>=ranges[k][0] && i<=ranges[k][1]){
                    covered= true;
                    break;
                }
            }
            if(!covered){
                return false;
            }
        }
        return true;
        
    }
};