struct Node {
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k,int v) {
        key=k;
        val = v;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
public:
unordered_map<int,Node*>cache; //(key,address)
int capacity;
Node *head;
Node *tail;

void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertAtFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    LRUCache(int capacity) {
       this->capacity=capacity;
       head=new Node(-1,-1);
       tail=new Node(-1,-1);
       head->next=tail;
       tail->prev=head;
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end()){
            Node *node=cache[key];
            removeNode(node);
            insertAtFront(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            Node *node=cache[key];
            node->val=value;
            removeNode(node);
            insertAtFront(node);
        }else {
            if (cache.size() == capacity) {
                // remove LRU from DLL and hashmap
                Node* lru = tail->prev;
                removeNode(lru);
                cache.erase(lru->key);
                //delete(lru);
            }
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            insertAtFront(newNode);
        }
    }
};