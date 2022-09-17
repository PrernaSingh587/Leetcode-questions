class Solution {
public:

unordered_map<int, int> cnt;

int traverse(int x){
    if(cnt[x] || x == 1)
        return cnt[x] ;
    
    if(x % 2)
        cnt[x] = 1+traverse(3*x + 1);
    else
        cnt[x] = 1+traverse(x/2);
    
    return cnt[x] ;
}

int getKth(int lo, int hi, int k) {

    vector<pair<int,int>> arr;
	
    for(int i = lo; i <= hi; i++)
    {
        arr.push_back({traverse(i), i}) ;
    }
	
    sort(arr.begin(), arr.end()) ;
    return arr[k-1].second;
}
};