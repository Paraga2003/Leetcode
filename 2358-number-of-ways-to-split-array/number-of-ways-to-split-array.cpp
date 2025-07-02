class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int ans =0;
        long totalSum = 0;
        for(int i:nums){
            totalSum+=i;
        }
        long prefixSum = 0;
        for(int i=0;i<nums.size()-1;i++){
            prefixSum+=nums[i];
            if(prefixSum >=(totalSum - prefixSum)){
                ans++;
            }
        }
        return ans;
        
    }
};