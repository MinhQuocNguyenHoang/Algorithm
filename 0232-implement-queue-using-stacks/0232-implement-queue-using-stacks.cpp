class MyQueue {
public:
    stack<int> q1;
    stack<int> q2;
    MyQueue() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        if(q2.empty()){
            while(!q1.empty()){
                q2.push(q1.top());
                q1.pop();
            }
        }
        int ans = q2.top();
        q2.pop();
        return ans;
    }
    
    int peek() {
        if(q2.empty()){
            while(!q1.empty()){
                q2.push(q1.top());
                q1.pop();
            }
        }
        return q2.top();
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */