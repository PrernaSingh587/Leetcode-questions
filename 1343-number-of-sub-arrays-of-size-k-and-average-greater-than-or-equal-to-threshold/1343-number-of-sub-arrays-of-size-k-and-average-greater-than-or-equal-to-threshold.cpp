class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int t) {
        int c=0;
        int sum=0,top=0;
        for(int i=0;i<k;i++) sum+=arr[i];
        if((sum/k)>=t) c++;
        for(int i=k;i<arr.size();i++) {
            sum-=arr[top++];
            sum+=arr[i];
             if((sum/k)>=t) c++;
        }
        return c;
    }
};