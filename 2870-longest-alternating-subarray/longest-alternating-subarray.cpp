class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int maxLen = -1;
        int n = nums.size();

        for (int start = 0; start < n - 1; ++start) {
            if (nums[start + 1] - nums[start] != 1) continue;

            int len = 2;
            int diff = -1;
            for (int i = start + 2; i < n; ++i) {
                if (nums[i] - nums[i - 1] == diff) {
                    len++;
                    diff *= -1; 
                } else {
                    break;
                }
            }
            maxLen = max(maxLen, len);
        }

        return maxLen;
    }
};