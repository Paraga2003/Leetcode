class Solution {
public:
    int countCollisions(string directions) {
        int ans = 0;
        //for no collision
        int i=0;
        int n = directions.size();
        while(i<n && directions[i]=='L'){
            i++;
        }
        int tempCount=0;
        int j = n - 1;
        while (j >= 0 && directions[j] == 'R') {
            j--;
        }
        // while(i<n){
        //     while(directions[i]=='R'){
        //         tempCount++;
        //         i++;
        //         continue;
        //     }
        //     if(directions[i]=='S'){
        //             ans+=tempCount;
        //     }else{
        //             ans= ans+ tempCount+1;
        //     }
        //     tempCount = 0;
        //     i++;

        // }
        // return ans;
        for (int k = i; k <= j; k++) {
            if (directions[k] != 'S') {
                ans++;
            }
        }
        
        return ans;
        


        
    }
};