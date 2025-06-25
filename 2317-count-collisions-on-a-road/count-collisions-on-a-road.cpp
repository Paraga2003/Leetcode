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
        while (i < n) {
            while (i < n && directions[i] == 'R') {
                tempCount++;
                i++;
            }
            
            if (i < n && directions[i] == 'S') {
                ans += tempCount;
                tempCount = 0;
                i++;
            } else if (i < n && directions[i] == 'L') {
                
                ans += tempCount + 1; 
                tempCount = 0;
                i++;
                
                
                while (i < n && directions[i] == 'L') {
                    ans++;
                    i++;
                }
            } else {
                
                tempCount = 0;
                i++;
            }
        }
       
        // for (int k = i; k <= j; k++) {
        //     if (directions[k] != 'S') {
        //         ans++;
        //     }
        // }
        
        return ans;
        


        
    }
};