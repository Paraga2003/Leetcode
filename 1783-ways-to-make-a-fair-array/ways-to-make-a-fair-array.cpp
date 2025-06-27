class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int count = 0;
        int rightevenSum = 0;
        int rightoddSum = 0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                rightevenSum += nums[i];
            }else{
                rightoddSum+=nums[i];
            }
        }
        int lefteven =0 , leftodd =0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                rightevenSum -= nums[i];
            }else{
                rightoddSum -= nums[i];
            }

            if(lefteven + rightoddSum == leftodd + rightevenSum){
                ++count;
            }

            if(i%2==0){
                lefteven += nums[i];
            }else{
                leftodd+= nums[i];
            }
        }
        return count;
        
        
        
    }
};