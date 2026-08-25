class MyCircularQueue {
public:
int front = -1, rear = -1, noOfElements = 0, capacity;
        vector<int> que;

    MyCircularQueue(int k) {
        capacity = k;
        que.resize(k, -1);
    }
    
    bool enQueue(int value) {
        if(noOfElements == capacity)
        {
            return false;
        }
        rear = (rear + 1) % capacity;
        que[rear] = value;
        if(front == -1)
        {
            front = rear;
        }
        noOfElements++;
        return true;
    }
    
    bool deQueue() {
        if(noOfElements == 0)
        {
            return false;
        }
        noOfElements--;
        que[front] = -1;
        if(noOfElements == 0)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % capacity;
        }
        return true;
    }
    
    int Front() {
        if(noOfElements == 0)
            return -1;
        return que[front];
    }
    
    int Rear() {
        if(noOfElements == 0)
            return -1;
        return que[rear];
    }
    
    bool isEmpty() {
        return (noOfElements == 0);
    }
    
    bool isFull() {
        return (noOfElements == capacity);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */