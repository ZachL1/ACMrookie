/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> pushs;
    stack<int> pops;

    MyQueue() { }
    
    void push(int x) {
        pushs.push(x);
    }
    
    int pop() {
        if (pops.empty()) pushs2pops();
        int temp = pops.top();
        pops.pop();
        return temp;
    }
    
    int peek() {
        if (pops.empty()) pushs2pops();
        return pops.top();
    }
    
    bool empty() {
        return pops.empty() && pushs.empty();
    }

private:
    void pushs2pops() {
        while (!pushs.empty()) {
            pops.push(pushs.top());
            pushs.pop();
        }
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
// @lc code=end

