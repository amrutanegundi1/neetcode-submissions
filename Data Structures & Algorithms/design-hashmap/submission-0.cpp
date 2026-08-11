class Node
{
    public:
        int key, val;
        Node* next;
        Node(int key, int val)
        {
            this->key = key;
            this->val = val;
            this->next = nullptr;
        }

};
class MyHashMap {
public:
    vector<Node*> arr;
    MyHashMap() {
        arr.resize(10000, nullptr);
    }
    
    void put(int key, int value) {
        int hash = key % arr.size();
        if(arr[hash] == nullptr)
        {
            arr[hash] = new Node(key, value);
        }
        else
        {
            Node *node = arr[hash];
            while(node->next)
            {
                if(node->key == key)
                {
                    node->val = value;
                    return;
                }
                node = node->next;
            }
            if(node->key == key)
            {
                node->val = value;
            }
            else
            {
                node->next = new Node(key, value);
            }
        }
    }
    
    int get(int key) {
        int hash = key % arr.size();
        if(arr[hash] == nullptr)
        {
            return -1;
        }
        else
        {
            Node *node = arr[hash];
            while(node->next)
            {
                if(node->key == key)
                {
                    return node->val;
                }
                node = node->next;
            }
            if(node->key == key)
            {
                return node->val;
            }
            return -1;
        }
    }
    
    void remove(int key) {
        int hash = key % arr.size();
        if(arr[hash] == nullptr)
        {
            return;
        }
        else
        {
            Node *node = arr[hash];
            Node *prev = nullptr;
            while(node)
            {
                if(node->key == key)
                {
                    if(prev == nullptr)
                    {
                        arr[hash] = node->next;
                    }
                    else
                    {
                        prev->next = node->next;
                    }
                    delete node;
                    return;
                }
                node = node->next;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */