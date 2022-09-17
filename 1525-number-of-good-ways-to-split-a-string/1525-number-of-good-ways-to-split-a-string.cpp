class Solution {
public:
    int numSplits(string s) {
        int n=s.size();
        int left[n],right[n];
        int a[26]={0},b[26]={0};
        
        int top=0;
        for(char c : s) {
            if(a[c-'a']==0) {
                if(top==0)
                left[top]=1;
                else left[top]=left[top-1]+1;
                a[c-'a']++;
            } else {
                a[c-'a']++;
                left[top]=left[top-1];
            }
            top++;
        }
         top=n-1;
        for(int i=n-1;i>=0;i--) {
            if(b[s[i]-'a']==0) {
                if(top==n-1)
                right[top]=1;
                else right[top]=right[top+1]+1;
                b[s[i]-'a']++;
            } else {
                b[s[i]-'a']++;
                right[top]=right[top+1];
            }
            top--;
        }
       
        int count=0;
        for(int i=0;i<n-1;i++) {
            
            if(left[i]==right[i+1]) {
                count++;
            }
        }
        
        return count;
    }
};