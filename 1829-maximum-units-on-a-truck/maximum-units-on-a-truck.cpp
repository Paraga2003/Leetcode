class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](const vector<int>&a , const vector<int> &b){
            return a[1]>b[1];
        });
        int ans  =0;
        for(int i = 0;i<boxTypes.size();i++){
            int noOfBox = boxTypes[i][0];
            int units = boxTypes[i][1];
            if(truckSize!=0){
                if(noOfBox<=truckSize){
                    ans+=(noOfBox*units);
                    truckSize-=noOfBox;
                }else{
                    ans+=(truckSize*units);
                    truckSize = 0;
                }
            }
        }
        return ans ;
        
    }
};