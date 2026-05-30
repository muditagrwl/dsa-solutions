class MyStack {
private:
    queue<int> q;

public:
    MyStack() {
        // Constructor
    }
    
    // Push element x onto stack
    void push(int x) {
        // Get the current size before adding the new element
        int current_size = q.size();
        
        // Add the new element to the back of the queue
        q.push(x);
        
        // Rotate the queue: Pop all previous elements and push them behind x
        for (int i = 0; i < current_size; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    // Removes the element on top of the stack and returns it
    int pop() {
        int top_val = q.front();
        q.pop();
        return top_val;
    }
    
    // Get the top element
    int top() {
        return q.front();
    }
    
    // Returns whether the stack is empty
    bool empty() {
        return q.empty();
    }
};