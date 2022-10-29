class Twitter {
public:
    unordered_map<int,unordered_set<int>>followers;
    unordered_map<int,vector<pair<int,int>>>mp;
    int time;
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        //cout<<tweetId<<endl;
        mp[userId].push_back({++time,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>q;
        for(int i=0;i<mp[userId].size();i++) {
            q.push(mp[userId][i]); //cout<<mp[userId][i].second<<" ";
            //if(q.size()>10) q.pop();
        }
        for(auto i=followers[userId].begin();i!=followers[userId].end();i++) {
            int k = (*i);
            for(int j=0;j<mp[k].size();j++) {
                q.push(mp[k][j]);
               // if(q.size()>10) q.pop();
            }
        }
        vector<int>ans;
        int x=0;
        while(!q.empty() && x<10) {
           pair<int,int>z=q.top();
            q.pop();
            x++;
            ans.push_back(z.second);
        }
        return ans;
        
    }
    
    void follow(int foId, int feId) {
         followers[foId].insert(feId);
    }
    
    void unfollow(int foId, int feId) {
        followers[foId].erase(feId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */