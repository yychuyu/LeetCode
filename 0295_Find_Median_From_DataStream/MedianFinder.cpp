class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(greater_heap.empty()){
            greater_heap.push(num);
        }
        else if(greater_heap.size() == less_heap.size()){
            if(num <= greater_heap.top()){
                greater_heap.push(num);
            }
            else{
                less_heap.push(num);
            }
        }
        else if(greater_heap.size() > less_heap.size()){
             if(num <= greater_heap.top()){
                less_heap.push(greater_heap.top());
                greater_heap.pop();
                greater_heap.push(num);
            }
            else{
                less_heap.push(num);
            }
        }
        else{
            if(num <= greater_heap.top()){
                greater_heap.push(num);
            }
            else{
                less_heap.push(num);
                greater_heap.push(less_heap.top());
                less_heap.pop();
            }
        }
    }
    
    double findMedian() {
        int greater_size = greater_heap.size();
        int less_size = less_heap.size();
        if((greater_size > less_size )){
            return greater_heap.top();
        }
        else if(greater_size < less_size){
            return less_heap.top();
        }
        else{
            return (greater_heap.top()+less_heap.top())/2.0;
        }
    }
private:
    priority_queue<int, vector<int>, less<int>> greater_heap;
    priority_queue<int, vector<int>, greater<int>> less_heap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */