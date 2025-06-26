class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // int n= nums.size(); 
        // vector<int> ans(n,1);
        // vector<int> prefix(n,1);
        // prefix[0]=1;
        // for(int i=1;i<n;i++){
        //     prefix[i] = prefix[i-1]*nums[i-1];
        // }
        // vector<int> suffix(n,1);
        // suffix[n-1]=1;
        // for(int j= n-2;j>=0;j--){
        //     suffix[j]=suffix[j+1]*nums[j+1];
        // }
        // for(int k=0;k<n;k++){
        //     ans[k] = prefix[k]*suffix[k];
        // }
        // return ans;
        long long totalproduct = 1;
        int n = nums.size();
        int zerocount = 0;
        int zeroindex = 0;
        vector<int> ans(n,0); 
        for(int i=0;i<nums.size();i++){
             
             if(nums[i]==0){
                zerocount++;
                zeroindex = i;
                continue;
             }
             totalproduct *= nums[i];
        }
        if(zerocount==0){
            for(int i=0;i<n;i++){
                ans[i]=totalproduct/nums[i];
            }
            return ans;
        }
        if(zerocount==1){
            for(int i=0;i<n;i++){
                if(nums[i]==0){
                    ans[i]=totalproduct;
                }
                else{
                    ans[i]=0;
                }
                
            }
            return ans;

        }
        if(zerocount>0){
            return ans;
        }
        return ans;

        
    }
};