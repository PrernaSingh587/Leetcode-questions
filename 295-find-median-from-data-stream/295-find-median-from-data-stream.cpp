class MedianFinder {
public:
    priority_queue<int>q1;
    priority_queue<int,vector<int>,greater<int>>q2;
    MedianFinder() {
        
    }
    
    void addNum(int x) {
        //cout<<q1.size()<<" "<<q2.size()<<". ";
      if(q1.empty() || (q1.size()==q2.size())) {
            q1.push(x);
        } else {
            q2.push(x);
        }
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {  
        if(q2.empty() || q1.empty()) {
           // cout<<q1.size()<<" "<<q2.size()<<endl; 
            return ;
        }
        
        if(q1.top()>q2.top()) {
           // cout<<q1.top()<<" "<<q2.top()<<" ";
            int d=q1.top(),dd=q2.top();
            q1.pop();
            q2.pop();
            q1.push(dd);
            q2.push(d);
        }
       //  cout<<q1.size()<<" "<<q2.size()<<endl;
    }
    
    double findMedian() {
        if(q1.empty()) return 0;
        cout<<q1.size()<<" "<<q2.size()<<endl;
        if(q1.size()>q2.size()) return q1.top();
       // cout<<q1.top()<<" "<<q2.top()<<endl;
        return (double)(q1.top()+q2.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */