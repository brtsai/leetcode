class MyQueue {
private:
    std::vector<int> pusherStack, popperStack;

    void refillPopperStackIfNeeded() {
        if (this->popperStack.empty()) {
            while (not this->pusherStack.empty()) {
                this->popperStack.insert(this->popperStack.end(), this->pusherStack.back());
                this->pusherStack.pop_back();
            }
        }
    }
public:
    MyQueue() {}
    
    void push(int x) {
        this->pusherStack.insert(this->pusherStack.end(), x);
    }
    
    int pop() {
        refillPopperStackIfNeeded();

        int& back = this->popperStack.back();
        this->popperStack.pop_back();

        return back;
    }
    
    int peek() {
        refillPopperStackIfNeeded();

        return this->popperStack.back();
    }
    
    bool empty() {
        return this->pusherStack.empty() and this->popperStack.empty();
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
