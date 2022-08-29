class Solution {
public:
    int trap(vector<int>& ht) {
        int n=ht.size();
        vector<int>rt(n,0),lt(n,0);
        int sum=0;
        rt[n-1]=ht[n-1];
        lt[0]=ht[0];
        for(int i=1;i<n;i++) lt[i]=max(lt[i-1],ht[i]);
        for(int i=n-2;i>=0;i--) rt[i]=max(rt[i+1],ht[i]);
        for(int i=0;i<n;i++) {
            sum+=min(lt[i],rt[i])-ht[i];
        }
        return sum;
    }
};