//
// Created by 潘莫凡 on 2024/4/26.
//

#ifndef TEST_PROGP_BASICS_H
#define TEST_PROGP_BASICS_H

#include <iostream>
#include <string>
#include <fstream>


using namespace std;
string about_tb;
string Act;
string file_editor;


//交换函数
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

//Print stack
void printStack(const stack<int> &s) {
    stack<int> temp(s);  // 复制一份栈以保留原栈状态
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}




#endif //TEST_PROGP_BASICS_H
