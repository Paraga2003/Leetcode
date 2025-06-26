class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int n = nums.size();
        int prefix = 1;
        int suffix = 1;
        for(int i=0,j=n-1;i<n&j>=0;i++,j--){
            if(prefix==0 ){
                prefix=1;
            }
            if(suffix==0){
                suffix = 1;
            }
            prefix = prefix*nums[i];
            suffix = suffix*nums[j];
            ans = max(ans,max(prefix,suffix));
            

        }
        return ans;
        
    }
};