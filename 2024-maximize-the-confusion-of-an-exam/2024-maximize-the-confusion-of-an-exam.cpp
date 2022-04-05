class Solution {
public:
    int maxConsecutiveAnswers(string ans, int k) {
        int count[2]={0},maxi=0,m=0,top=0;
        for(int i=0;i<ans.size();i++) {
            if(ans[i]=='T') count[0]++;
            else count[1]++;
            m=max(m,ans[i]=='T'?count[0]:count[1]);
            if(i-top+1-m>k) {
                if(ans[top]=='T') count[0]--;
                else count[1]--;
                top++;
                m=0;
                for(int kk=0;kk<2;kk++) m=max(m,count[kk]);
            }
            maxi=max(maxi,i-top+1);
        }
        return maxi;
    }
};