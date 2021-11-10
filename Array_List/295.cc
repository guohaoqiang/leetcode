class MedianFinder {
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if (min_heap.size()==0){
            min_heap.push(num);
        }
        if (max_heap.size()==min_heap.size()){
            if (max_heap.top()<num){
                min_heap.push(num);
            }else{
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(num);
            }
        }
        
        if (max_heap.size()<min_heap.size()){
            if (min_heap.top()<num){
                max_heap.push(min_heap.top());
                min_heap.pop();
                
                min_heap.push(num);
            }else{
                max_heap.push(num);
                
            }
        }
    }
    
    double findMedian() {
        if ((max_heap.size()+min_heap.size())%2)    return (double)min_heap.top();
        return (double)(max_heap.top()+min_heap.top())/2;
    }
    priority_queue<int,vector<int>> max_heap;
    priority_queue<int,vector<int>,greater<int>> min_heap;
};
