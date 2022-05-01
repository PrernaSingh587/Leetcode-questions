class LRUCache {
public:
    struct node {
        int key,val;
        node *next,*prev;
        node (int k,int v) {
            key=k;
            val=v;
            next=NULL;
            prev=NULL;
        }
    }*tail,*head;
    int cap;
    unordered_map<int,node*>mp;
    LRUCache(int capacity) {
        cap=capacity;
        tail=new node(-1,-1);
        head=new node(-1,-1);
        tail->prev=head;
        head->next=tail;
    }
    
    void add(node *newnode) {
        node *nextnode=head->next;
        newnode->next=nextnode;
        nextnode->prev=newnode;
        head->next=newnode;
        newnode->prev=head;
    }
    
    void delete_(node *newnode) {
        //cout<<newnode->val<<".\n";
        node *prevnode=newnode->prev;
        prevnode->next=newnode->next;
        newnode->next->prev=prevnode;
    }
    
    int get(int key) {
        //cout<<key<<"\n";
        if(mp.count(key)==0) return -1;
        node *k= mp[key];
        delete_(k);
        add(k);
       
        return k->val;
    }
    
    void put(int key, int val) {
       // cout<<key<<" "<<val<<endl; 
        if(mp.count(key)) {
            delete_(mp[key]);
            mp.erase(key);
        }
        if(mp.size()==cap) {
            mp.erase(tail->prev->key);
            delete_(tail->prev);
           
        }
        add(new node(key,val));
        mp[key]=head->next;
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */