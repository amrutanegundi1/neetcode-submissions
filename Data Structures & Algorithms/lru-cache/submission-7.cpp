class Node {
   public:
    int val;
    int key;
    Node* prev;
    Node* next;

    Node(int key = 0, int val = 0) {
        prev = nullptr;
        next = nullptr;
        this->val = val;
        this->key = key;
    }
};
class LRUCache {
   public:
    Node *left, *right;
    unordered_map<int, Node*> mp;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
        left = new Node();
        right = new Node();
        left->next = right;
        right->prev = left;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            removeAndAddNode(mp[key]);
            return mp[key]->val;
        }
        return -1;
    }

    void removeAndAddNode(Node* node) {
        Node *nxt = node->next, *prv = node->prev;
        nxt->prev = prv;
        prv->next = nxt;

        nxt = left->next;
        left->next = node;
        node->prev = left;
        node->next = nxt;
        nxt->prev = node;
    }

    void removeNode() {
        Node* node = right->prev;
        Node* prev = node->prev;
        prev->next = right;
        right->prev = prev;
        mp.erase(node->key);
        delete node;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key]->val = value;
            removeAndAddNode(mp[key]);
            return;
        } else if (mp.size() == cap) {
            removeNode();
        }
        Node* node = new Node(key, value);

        Node* temp = left->next;
        left->next = node;
        node->prev = left;
        node->next = temp;
        temp->prev = node;
        mp[key] = node;
    }
};
