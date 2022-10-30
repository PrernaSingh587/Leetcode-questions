class SmallestInfiniteSet {
public:
    //vector<int>v(1001);
    int top;
    set<int>st;
    SmallestInfiniteSet() {
        //for(int i=1;i<=1000;i++) v[i]=1;
        top=1;
    }
    
    int popSmallest() {
        if(st.size()==0) {
             int r = top;
        top++;
        return r;
        } else {
            int it=(*(st.begin()));
            st.erase(it);
            return it;
        }
       return -1;
    }
    
    void addBack(int num) {
       if(top<=num || st.find(num)!=st.end()) return ;
        st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */