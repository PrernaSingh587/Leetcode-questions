class Solution {
public:
    int maxArea(vector<int>& ht) {
        int n=ht.size();
        int i=0,j=n-1;
        int maxi=0;
        while(i<j) {
            int dist = j-i;
            if(ht[i]<=ht[j]) {
                maxi=max(maxi,ht[i]*dist);
                i++;
            } else {
                 maxi=max(maxi,ht[j]*dist);
                j--;
            }
        }
        return maxi;
    }
};