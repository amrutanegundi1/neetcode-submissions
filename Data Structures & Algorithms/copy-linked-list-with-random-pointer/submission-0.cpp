/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        unordered_map<Node*, Node*> mp;

        Node *temp = head;

        while(temp)
        {
            Node *node = new Node(temp->val);
            mp[temp] = node;
            temp = temp->next;
        }

        for(auto itr : mp)
        {
            if(itr.first->next != nullptr)
            {
                itr.second->next = mp[itr.first->next];
            }
            if(itr.first->random != nullptr)
            {
                itr.second->random = mp[itr.first->random];
            }
        }
        if(mp.size() > 0)
        {
            return mp[head];
        }
        return NULL;
        
    }
};
