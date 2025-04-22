#pragma once

#include <stack>
#include <string>
using namespace std;

class BrowserHistory
{
    stack<string> p, n;

public:
    BrowserHistory(string homepage) { p.push(homepage); }

    void visit(string url) {
        p.push(url);
        while (!n.empty()) n.pop();
    }

    string back(int steps) {
        while (steps > 0) {
            if (p.size() != 1) {
                n.push(p.top());
                p.pop();
            }
            steps--;
        }
        return p.top();
    }

    string forward(int steps) {
        while (steps > 0) {
            if (!n.empty()) {
                p.push(n.top());
                n.pop();
            }
            steps--;
        }
        return p.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

// 通过 | 107ms | 93.17MB
