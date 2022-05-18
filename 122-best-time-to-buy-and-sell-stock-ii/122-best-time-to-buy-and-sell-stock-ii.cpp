class Solution {
public:
    int maxProfit(vector<int>& A) {
        int n=A.size();
     int max=0,i=0;
    if(n==1) return 0;
    while(i<n) {
        while((i+1)<n && A[i]>=A[i+1]) {
            i++;
        }
        if(i==n-1) return max;
        int c=A[i],b=0;
        
        i++;
       
        while(i<n && A[i-1]<=A[i]) {
            i++;
        }
        b=A[i-1];
    cout<<c<<" "<<b<<"\n";
       
        max=(max+(b-c));;
    }
    return max;
        
    }
};