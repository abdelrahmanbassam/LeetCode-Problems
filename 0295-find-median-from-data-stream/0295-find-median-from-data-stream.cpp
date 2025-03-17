class MedianFinder {
public:
    priority_queue<int> smallHeap;
    priority_queue<int, vector<int>, greater<int>> largeHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        smallHeap.push(num);
        if(largeHeap.size() && smallHeap.top() > largeHeap.top()){
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        if(smallHeap.size() > largeHeap.size()){
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        else if(smallHeap.size() < largeHeap.size()){
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
    }
    
    double findMedian() {
        if (smallHeap.size() == largeHeap.size()) {
            return (largeHeap.top() + smallHeap.top()) / 2.0;
        } else if (smallHeap.size() > largeHeap.size()) {
            return smallHeap.top();
        } else {
            return largeHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */