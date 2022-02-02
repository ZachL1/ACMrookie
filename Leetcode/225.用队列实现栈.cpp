/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
#include <queue>
using namespace std;
class MyStack {
public:
    MyStack() {

    }
    
    void push(int x) {
        topx = x;
        q.push(x);
    }
    
    int pop() {
        int i = 0;
        while (++i < q.size()) {
            topx = q.front();
            q.push(topx);
            q.pop();
        }
        int temp = q.front();
        q.pop();
        return temp;
    }
    
    int top() {
        return topx;
    }
    
    bool empty() {
        return q.empty();
    }
private:
    int topx;
    queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

