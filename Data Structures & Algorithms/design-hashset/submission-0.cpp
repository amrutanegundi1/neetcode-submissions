class Node {
   public:
    Node(int k) {
        key = k;
        next = nullptr;
    }
    Node* next;
    int key;
};
class MyHashSet {
   public:
    vector<Node*> arr;
    MyHashSet() { arr.resize(10000, nullptr); }

    void add(int key) {
        int has = key % 10000;

        if (arr[has] == nullptr) {
            arr[has] = new Node(key);
        } else {
            Node* temp = arr[has];
            bool keyExists = false;
            while (temp->next) {
                if (temp->key == key) {
                    keyExists = true;
                    break;
                }
                temp = temp->next;
            }
            if (false == keyExists && temp->key != key) {
                temp->next = new Node(key);
            }
        }
    }

    void remove(int key) {
        int has = key % 10000;
        Node* prev = nullptr;
        Node* temp = arr[has];
        while (temp) {
            if (temp->key == key) {
                if (prev == nullptr) {
                    arr[has] = temp->next;
                } else {
                    prev->next = temp->next;
                    delete temp;
                }
            }
            prev = temp;
            temp = temp->next;
        }
    }

    bool contains(int key) {
        int has = key % 10000;
        Node* temp = arr[has];
        bool keyExists = false;
        while (temp) {
            if (temp->key == key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */