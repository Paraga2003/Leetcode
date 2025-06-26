class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n  = nums.size();
        int ans = 0;
        vector<int> prefix;
        int sum =0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            prefix.push_back(sum);
        }
        unordered_map<int,int> prefixSumCount;
        prefixSumCount[0] =1;
        for(int i=0;i<n;i++){
            if(prefixSumCount.find(prefix[i]-k)!=prefixSumCount.end()){
                ans+=prefixSumCount[prefix[i]-k];
            }
            prefixSumCount[prefix[i]]++;
            
        }
        return ans;
        
        
    }
};