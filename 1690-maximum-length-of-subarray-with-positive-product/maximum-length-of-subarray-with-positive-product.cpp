class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        
        // vector<vector<int,int>> nonzeroRange;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]!=0){
        //         vector<int>temp;
        //         temp.push_back(i); 
        //         while(nums[i]!=0 && i<n){
        //             i++;
        //         }
        //         temp.push_back(i)l
        //     }
        //     nonzeroRange.pushback(temp);
        // }
        // for(int i=0;i<nonzeroRange.size();i++){
        //     int negativeCount = 0;
        //     int start = nonzeroRange[i][0];
        //     int end = nonzero[i][1];
        //     for(int i=start;i<end;i++){

        //     }
        // }
        int pos = 0; // Length of subarray with positive product
        int neg = 0; // Length of subarray with negative product
        int res = 0; // Result to store max length of positive product subarray

        for (int num : nums) {
            if (num == 0) {
                pos = 0;
                neg = 0;
            } else if (num > 0) {
                pos += 1;
                neg = (neg > 0) ? neg + 1 : 0;
            } else { // num < 0
                int temp = pos;
                pos = (neg > 0) ? neg + 1 : 0;
                neg = temp + 1;
            }
            res = max(res, pos);
        }

        return res;

        
    }
};