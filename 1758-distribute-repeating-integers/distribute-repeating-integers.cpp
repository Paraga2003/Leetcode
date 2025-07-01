class Solution {
public:
    bool backtrack(vector<int>& quantity, vector<int>& freq, int index) {
        if (index == quantity.size()) return true;

        for (int i = 0; i < freq.size(); ++i) {
            if (freq[i] >= quantity[index]) {
                freq[i] -= quantity[index];
                if (backtrack(quantity, freq, index + 1)) return true;
                freq[i] += quantity[index]; // backtrack
            }
        }
        return false;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        map<int,int> mp;
        for(int x:nums){
            mp[x]++;
        }
        vector<int> freq;
        sort(freq.begin(),freq.end());
        for (auto& [num, count] : mp) {
            freq.push_back(count);
        }
        sort(quantity.rbegin(), quantity.rend()); 
        return backtrack(quantity, freq, 0);
    }
};