class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        long maxSum = 0;
        long sum = 0;
        // Me phali window ke liye chala rha hu
        for(int i =0;i<k;i++){
            sum+=nums[i];
        }
        maxSum = sum;
        //baki bachi hui array se maximum nikal le
        for(int i=k;i<nums.size();i++){
            sum = sum + nums[i] - nums[i-k];
            maxSum = max(sum,maxSum);

        }
        return static_cast<double>(maxSum)/k;
        
    }
};