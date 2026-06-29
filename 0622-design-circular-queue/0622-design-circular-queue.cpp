class MyCircularQueue {
    private:
    vector<int>arr;
    int front;
    int rear;
    int capacity;
    int currentSize;
public:
    MyCircularQueue(int k) {
        capacity = k;
        arr.resize(k);
        front = 0;
        rear = 0;
        currentSize = 0;
    }
    
    bool enQueue(int value) {
        if(currentSize == capacity){
            return false;
        }
        arr[rear] = value;
        rear = (rear+1)%capacity;
        currentSize ++;
        return true;
    }
    
bool deQueue() {
    if(currentSize == 0){
        return false;
    }

    front = (front + 1) % capacity;
    currentSize--;

    return true;
}
    
    int Front() {
        if(currentSize==0) return -1;
        return arr[front];
    }
    
    int Rear() {
         if(currentSize==0) return -1;
         int last  = (rear-1+capacity)%capacity;
         return arr[last];
    }
    
    bool isEmpty() {
        return currentSize == 0;
    }
    
    bool isFull() {
        return currentSize == capacity; 
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