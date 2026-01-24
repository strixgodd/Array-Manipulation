
//more improvement required
class LRUCache {
public:
    class node{
        public:
        int key_;
        int val_;
        node* next;
        node* prev;
        node(int key,int val){
            key_=key;
            val_=val;
        }
    };
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    int cap;
    unordered_map<int,node*> m;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addNodeInFront(node* newnode){
        node* temp=head->next;
        newnode->next=temp;
        head->next=newnode;
        newnode->prev=head;
        temp->prev=newnode;
    }
    void deleteNode(node* delnode){
        node* delprev=delnode->prev;
        node* delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    int get(int key) {
        if(m.find(key)!=m.end()){// the key is present in DLL
            node* resnode=m[key];// pointer to that node in DLL
            int res=resnode->val_;
            // m.erase(key);
            deleteNode(resnode);
            addNodeInFront(resnode);
            // m[key]=head->next;
            return res;
        }
        return -1;
    }
    void put(int key, int value){
        if(m.find(key)!=m.end() ){// if that key value pair is present inthe unordered_map
            node* existingnode=m[key];//get the location of the key value pair in DLL
            deleteNode(existingnode);
            addNodeInFront(existingnode);
            existingnode->val_=value;
        }
        else{//key not present
            if(m.size()==cap){
                m.erase(tail->prev->key_);
                deleteNode(tail->prev);
                addNodeInFront(new node(key,value));
                m[key]=head->next;
            }
            else{
                addNodeInFront(new node(key,value));
                m[key]=head->next;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */