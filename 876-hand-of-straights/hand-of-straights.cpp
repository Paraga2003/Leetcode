class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        int n = hand.size();
        if(n%groupSize!=0){
            return false;
        }
        map<int,int> cardmap;
        for(int i:hand){
            cardmap[i]++;
        }
        while(!cardmap.empty()){
            int curr = cardmap.begin()->first;

            for(int i=0;i<groupSize;i++){
                if(cardmap[curr+i]==0){
                    return false;
                }
                cardmap[curr+i]--;
                if(cardmap[curr+i]<1){
                    cardmap.erase(curr+i);
                }
            }
        }
        return true;
    }
};