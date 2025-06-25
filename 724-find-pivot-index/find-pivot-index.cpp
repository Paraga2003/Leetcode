class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        vector<int> prefixSum;
        int sum =0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            prefixSum.push_back(sum);

        }
        int n = prefixSum.size();
        if(prefixSum[n-1]==prefixSum[0]){
            return 0;
        }
        for(int i=1;i<prefixSum.size();i++){
            if(prefixSum[i]==prefixSum[n-1]-prefixSum[i-1]){
                return i;
            }
        }
        return -1;
        
    }
};