class Solution {
public:
    int findLucky(vector<int>& arr) {
        int ans = -1;
        map<int,int> mp;
        for(int i = 0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        for(auto &pair:mp){
            if(pair.first==pair.second){
                ans = pair.first;
            }
        }
        return ans;
        
    }
};