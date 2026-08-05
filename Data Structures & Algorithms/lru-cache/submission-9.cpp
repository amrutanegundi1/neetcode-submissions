class Node
{
public:
    int key;
    int val;
    Node(int k, int v)
    {
        key = k;
        val = v;
    }

};
class LRUCache {
public:
    list<Node> ls;
    map<int, list<Node>::iterator> mp;
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end())
        {
            list<Node>::iterator it = mp[key];
            int val = it->val;
            ls.erase(it);
            ls.push_front(Node(key, val));
            mp[key] = ls.begin();
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end())
        {
            list<Node>::iterator it = mp[key];
            ls.erase(it);
            ls.push_front(Node(key, value));
            mp[key] = ls.begin();
            return;

        }
        else if(ls.size() == capacity)
        {
            Node node = ls.back();
            ls.pop_back();
            mp.erase(node.key);
        }
        ls.push_front(Node(key, value));
        mp[key] = ls.begin();

    }
};
