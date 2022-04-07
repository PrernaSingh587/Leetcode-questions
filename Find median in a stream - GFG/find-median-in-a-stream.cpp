// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    priority_queue<int>q1;
    priority_queue<int,vector<int>,greater<int>>q2;
    public:
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(q1.empty() || q1.size()==q2.size()) {
            q1.push(x);
        } else {
            q2.push(x);
        }
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(q2.empty() || q1.empty()) return ;
        if(q1.top()>q2.top()) {
            int d=q1.top();
            q1.pop();
            q1.push(q2.top());
            q2.pop();
            q2.push(d);
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(q1.empty()) return 0;
        if(q1.size()>q2.size()) return q1.top();
        return (double)(q1.top()+q2.top())/2;
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends