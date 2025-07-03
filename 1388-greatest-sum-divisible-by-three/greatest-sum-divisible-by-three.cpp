class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int total = 0;
        vector<int> rem1;
        vector<int> rem2;
        for(int i = 0;i<nums.size();i++){
            total += nums[i];
            if(nums[i]%3==1){
                rem1.push_back(nums[i]);
            }
            if(nums[i]%3==2){
                rem2.push_back(nums[i]);
            }
        }
        if(total%3==0) return total;
        sort(rem1.begin(),rem1.end());
        sort(rem2.begin(),rem2.end());
        int minremoval = INT_MAX;
        
        if(total%3 ==1){
            if(!rem1.empty()) minremoval = min(minremoval,rem1[0]);
            if(rem2.size()>=2) minremoval = min(minremoval,rem2[0]+rem2[1]);
        }else if(total%3==2){
            if(!rem2.empty()) minremoval = min(minremoval,rem2[0]);
            if(rem1.size()>=2) minremoval = min(minremoval,rem1[0]+rem1[1]);

        }
        return total - minremoval;
    }
};