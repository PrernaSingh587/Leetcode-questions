#define ll long long
class Solution {
public:
    int nthUglyNumber(int n) {
        unordered_set<ll>st;
        priority_queue<ll,vector<ll>,greater<ll>>q;
        q.push(1);
        q.push(2); q.push(3); q.push(5);
        st.insert(1);
        st.insert(2); st.insert(3); st.insert(5);
        
        while(!q.empty()) {
            
                ll k=q.top(); q.pop();
           //if(k==3) cout<<k<<" ";
                n--;
                if(n==0) return k;
                if(st.find(k*2)==st.end()) {
                    st.insert(k*2);
                    q.push(k*2);
                 // if(k==3)  cout<<k*2<<" ";
                }  if(st.find(k*3)==st.end()) {
                    st.insert(k*3);
                    q.push(k*3);
                   //if(k==3) cout<<k*3<<" ";
                }  if(st.find(k*5)==st.end()) {
                    st.insert(k*5);
                    q.push(k*5);
                   //if(k==3) cout<<k*5<<" ";
                }
         // if(k==3)  cout<<endl;
            
        }
        return 0;
    }
};