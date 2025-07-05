class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0){
            return false;
        }
        map<int,int> cardCtrMap;
        for(int &handno:hand){
            cardCtrMap[handno]++;
        }
        
        while(!cardCtrMap.empty()){
            
            int curr=cardCtrMap.begin()->first;
            
            for(int i=0;i<groupSize;i++){
                if(cardCtrMap[curr+i]==0){
                    return false;
                }
                cardCtrMap[curr+i]--;
                if(cardCtrMap[curr+i]<1){
                    cardCtrMap.erase(curr+i);
                }
            }
        }
        return true;

        
    }
};