class MyQueue {
private:
    stack<int> input_st;
    stack<int> output_st;

    // Helper function to shift elements from the input stack to the output stack
    void shiftStacks() {
        // Only move elements if the output stack is completely empty
        if (output_st.empty()) {
            while (!input_st.empty()) {
                output_st.push(input_st.top());
                input_st.pop();
            }
        }
    }

public:
    MyQueue() {
        
    }
    
    // Push element x to the back of the queue
    void push(int x) {
        input_st.push(x);
    }
    
    // Removes the element from the front of the queue and returns it
    int pop() {
        shiftStacks();
        int front_val = output_st.top();
        output_st.pop();
        return front_val;
    }
    
    // Get the front element
    int peek() {
        shiftStacks();
        return output_st.top();
    }
    
    // Returns whether the queue is empty
    bool empty() {
        return input_st.empty() && output_st.empty();
    }
};