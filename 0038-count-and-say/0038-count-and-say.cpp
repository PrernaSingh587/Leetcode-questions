class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        
        string h="1";
        for(int i=2;i<=n;i++) {
            int cnt=1; 
            string temp = "";
            for(int k=1;k<h.size();k++) {
                if(h[k]==h[k-1]) {
                    cnt++;
                } else {
                    temp += to_string(cnt) + h[k-1];
                    cnt = 1;
                }
            }
            temp += to_string(cnt) + h[h.size()-1];
            h=temp;
           // cout<<h<<" ";
        }
        return h;
    }
};