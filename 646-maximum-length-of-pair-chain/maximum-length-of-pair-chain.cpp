class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];});
        int ans = 0;
        int currend = INT_MIN ;
        for(int i=0;i<pairs.size();i++){
            if(pairs[i][0]>currend){
                ans++;
                currend = pairs[i][1];
                    
            }
            
            
        }
        return ans;
        
    }
};