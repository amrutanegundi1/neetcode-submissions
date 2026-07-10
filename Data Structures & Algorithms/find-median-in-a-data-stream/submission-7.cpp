class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> smallHeap;
    priority_queue<int, vector<int>, greater<int>> largeHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(smallHeap.size() > 0 && largeHeap.size() > 0)
        {
            if(num < largeHeap.top())
            {
                smallHeap.push(num);
            }
            else
            {
                largeHeap.push(num);
            }
        }
        else
        {
            smallHeap.push(num);   
        }


        // smallHeap.push(num);
        // // small heap is less than large heap
        // if(smallHeap.size() > 0 && largeHeap.size() > 0)
        // {
        //     if(smallHeap.top() > largeHeap.top())
        //     {
        //         int temp = smallHeap.top();
        //         smallHeap.pop();
        //         largeHeap.push(temp);
        //     }
        // }

        // // maintain the size to be ~equal
        if(int(smallHeap.size() - largeHeap.size()) > 1)
        {
            int temp = smallHeap.top();
            smallHeap.pop();
            largeHeap.push(temp);
        }

        if(int(largeHeap.size() - smallHeap.size()) > 1)
        {
            int temp = largeHeap.top();
            largeHeap.pop();
            smallHeap.push(temp);
        }     
    }
    
    double findMedian() {
        if(smallHeap.size() > largeHeap.size())
        {
            return smallHeap.top();
        }
        if(largeHeap.size() > smallHeap.size())
        {
            return largeHeap.top();
        }
        return double(smallHeap.top() + largeHeap.top())/2;
    }
};