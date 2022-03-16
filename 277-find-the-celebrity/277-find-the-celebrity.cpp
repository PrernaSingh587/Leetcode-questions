/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    bool isCeleb(int ans,int n) {
        for(int i=0;i<n;i++) {
            if(i==ans) continue;
            if(knows(i,ans) && !knows(ans,i)) continue;
            return 0;
        }
        return 1;
    }
    int findCelebrity(int n) {
        int ans=0;
        for(int i=0;i<n;i++) {
            if(knows(ans,i)) ans=i;
        }
        if(isCeleb(ans,n)) return ans;
        return -1;
    }
    
};