/* × 🀆 -      Notice
 * ---------------------Toolbox v25.1-
 * |Basic plugin for toolbox.        |
 * |This plugin is created by 潘莫凡  |
 * |This plugin includes many        |
 * |useful functions. They can be use|
 * |by toolbox. But the user must    |
 * |edit the main program of toolbox.|
 * -----------------------------------
 */
#ifndef TEST_PROGP_BASIC_PLUGIN_H
#define TEST_PROGP_BASIC_PLUGIN_H

#include <iostream>
#include <cstdio>
#include <cmath>
#include <stack>
#include <string>
#include "basics.h"


using namespace std;

/*
 * [double] dis
 * double x1, double y1, double x2, double y2
 * x1:Point 1 [x] y1: Point 1 [y]
 * x2:Point 2 [x] y2: Point 2 [y]
 * Get distance.
 */
double dis(double x1, double y1, double x2, double y2) {
    return sqrt(abs((x1 - x2) * (x1 - x2)) + abs((y1 - y2) * (y1 - y2)));
}

/*
 * [long long] factorial
 * int n
 * n:number
 * Factorial.
 */
long long factorial(int n) {
    if (n == 1) return 1;
    return n * factorial(n - 1);
}

/*
 * [bool] is_prime
 * int x
 * x: number
 * Is the number a prime.
 */
bool is_prime(int x) {//判断是否素数
    if (x <= 1) return false;//如果小于2，一定不是素数
    for (int i = 2; i <= sqrt(x); i++) {//为什么要到sqrt(x)呢，因为如果有一个大于sqrt(n)的数可以被n整除，那么必有一个数n/i也可以被n整除且小于i
        if (x % i == 0) return false;//如果可以整除，那么不是素数
    }
    return true;//是素数
}


/*
 * [stack--int] collatzConjecture
 * int b
 * b: number to use
 * Run Collatz Conjecture with number 'b' and return steps from end to start.
 */
stack<int> collatzConjecture(int b) {
    stack<int> a;
    a.push(b);
    for (; b != 1;) {
        if (b % 2 != 0) {
            b = b * 3 + 1;
            a.push(b);
        } else {
            b = b / 2;
            a.push(b);
        }
    }
    return a;
}



/* |-------------------------|
 * |高精度运算部分，不支持负数运算|
 * |-------------------------|
 */
//compare比较函数：相等返回0，大于返回1，小于返回-1
int compare(string str1, string str2) {
    if (str1.length() > str2.length()) return 1;
    else if (str1.length() < str2.length()) return -1;
    else return str1.compare(str2);
}

//高精度加法
//只能是两个正数相加
string add(string str1, string str2)//高精度加法
{
    string str;
    int len1 = str1.length();
    int len2 = str2.length();
    //前面补0，长度相同
    if (len1 < len2) {
        for (int i = 1; i <= len2 - len1; i++)
            str1 = "0" + str1;
    } else {
        for (int i = 1; i <= len1 - len2; i++)
            str2 = "0" + str2;
    }
    len1 = str1.length();
    int cf = 0;
    int temp;
    for (int i = len1 - 1; i >= 0; i--) {
        temp = str1[i] - '0' + str2[i] - '0' + cf;
        cf = temp / 10;
        temp %= 10;
        str = char(temp + '0') + str;
    }
    if (cf != 0) str = char(cf + '0') + str;
    return str;
}

//高精度减法
//只能是两个正数相减，而且要大减小
string sub(string str1, string str2)//高精度减法
{
    string str;
    int tmp = str1.length() - str2.length();
    int cf = 0;
    for (int i = str2.length() - 1; i >= 0; i--) {
        if (str1[tmp + i] < str2[i] + cf) {
            str = char(str1[tmp + i] - str2[i] - cf + '0' + 10) + str;
            cf = 1;
        } else {
            str = char(str1[tmp + i] - str2[i] - cf + '0') + str;
            cf = 0;
        }
    }
    for (int i = tmp - 1; i >= 0; i--) {
        if (str1[i] - cf >= '0') {
            str = char(str1[i] - cf) + str;
            cf = 0;
        } else {
            str = char(str1[i] - cf + 10) + str;
            cf = 1;
        }
    }
    str.erase(0, str.find_first_not_of('0'));//去除结果中多余的前导0
    return str;
}

//高精度乘法
//只能是两个正数相乘
string mul(string str1, string str2) {
    string str;
    int len1 = str1.length();
    int len2 = str2.length();
    string tempstr;
    for (int i = len2 - 1; i >= 0; i--) {
        tempstr = "";
        int temp = str2[i] - '0';
        int t = 0;
        int cf = 0;
        if (temp != 0) {
            for (int j = 1; j <= len2 - 1 - i; j++)
                tempstr += "0";
            for (int j = len1 - 1; j >= 0; j--) {
                t = (temp * (str1[j] - '0') + cf) % 10;
                cf = (temp * (str1[j] - '0') + cf) / 10;
                tempstr = char(t + '0') + tempstr;
            }
            if (cf != 0) tempstr = char(cf + '0') + tempstr;
        }
        str = add(str, tempstr);
    }
    str.erase(0, str.find_first_not_of('0'));
    return str;
}

/*入参：
	begin 要排列的起始位置
	end   要排列的结束位置
	a[]	 要排列的数组
*/
void permutate(int begin, int end, int a[]) {
    if (begin == end)//已经到了最后一个位置，进行输出
    {
        for (int i = 0; i < end; i++) {
            cout << a[i];
        }
        cout << endl;
    }
    for (int i = begin; i < end; i++) {
        swap(a[begin], a[i]);
        permutate(begin + 1, end, a);//递归下一个位置
        swap(a[i], a[begin]);//回溯
    }
}
/*
int main()
{
    int a[5] = {1,2,3,4,5};
    permutate(0,3,a);//对数组中前三个数进行排列
    return 0;
}
*/

#endif //TEST_PROGP_BASIC_PLUGIN_H
