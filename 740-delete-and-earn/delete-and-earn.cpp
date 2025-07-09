class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxVal=*max_element(nums.begin(), nums.end());
        vector<int> points(maxVal+1);
        for(auto num:nums) points[num] += num;
        int prev1=points[0],prev2=max(points[0],points[1]);
        for(int i=2;i<=maxVal;i++){
            int ans=max(points[i]+prev1,prev2);
            prev1=prev2;
            prev2=ans;
        }
        return prev2;
        
    }
};