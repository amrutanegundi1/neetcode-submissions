class Node {
   public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int k, int v) {
        key = k;
        val = v;
        prev = NULL;
        next = NULL;
    }
};
class LRUCache {
   private:
    int c;
    unordered_map<int, Node*> mp;
    Node *left, *right;

   public:
    LRUCache(int capacity) {
        c = capacity;
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }
    void remove(Node* node) {
        Node *prv = node->prev, *nxt = node->next;
        prv->next = nxt;
        nxt->prev = prv;
    }

    void insert(Node* node) {
        Node *prv = right->prev, *nxt = right;
        prv->next = node;
        node->prev = prv;
        node->next = nxt;
        nxt->prev = node;
    }
    int get(int key) {
        int val = -1;
        if (mp.find(key) != mp.end()) {
            val = mp[key]->val;
            remove(mp[key]);
            insert(mp[key]);
        }
        return val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            remove(mp[key]);
        }
        mp[key] = new Node(key, value);
        insert(mp[key]);

        if (mp.size() > c) {
            Node *prv = left, *nxt = left->next->next;
            Node* data = left->next;
            prv->next = nxt;
            nxt->prev = left;
            mp.erase(data->key);
        }
    }
};
