class LRUCache {
public:
    struct node {
        int val;
        node *next,*prev;
        node(int val1) {
            val=val1;
        }
    }*head,*tail;
    int cap;
    unordered_map<int,pair<int,node*>>mp;
    
    LRUCache(int capacity) {
        cap=capacity;
        head=new node(-1);
        tail=new node(-1);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.count(key)==0) return -1;
        pair<int,node*>p=mp[key];
        node *x=p.second;
        node*prev = x->prev,*next=x->next;
        prev->next=next;
        next->prev=prev;
        node* head_next=head->next;
        head->next=x;
        x->prev=head;
        x->next=head_next;
        head_next->prev=x;
        
        return p.first;
    }
    
    void put(int key, int value) {
        if(mp.count(key)) {
            pair<int,node*>k=mp[key];
            mp[key]={value,k.second};
            node *x=k.second;
        node*prev = x->prev,*next=x->next;
        prev->next=next;
        next->prev=prev;
        node* head_next=head->next;
        head->next=x;
        x->prev=head;
        x->next=head_next;
        head_next->prev=x;
            return;
        }
       if(mp.size()==cap) {
            node *last=tail->prev;
            mp.erase(last->val);
         last->prev->next=last->next;
        last->next->prev=last->prev;
       }
            node *x=new node(key);
            mp[key]={value,x};
            node* head_next=head->next;
        head->next=x;
        x->prev=head;
        x->next=head_next;
        head_next->prev=x;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */