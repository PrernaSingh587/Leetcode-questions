class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>v(n+1);
        if(n==0) return {0};
        if(n==1) return {0,1};
        v[0]=0; v[1]=1;
        int f=1,top=0;
        for(int i=2;i<=n;i++) {
            
            if(i==pow(2,(int)log2(i))) {
                top=0;
            }
                v[i]=1+v[top++];
        
        }
        return v;
    }
};