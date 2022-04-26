#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool judgePoint24(vector<int> &nums)
    {
        vector<double> digits;
        for (int &x : nums)
            digits.push_back(x);
        return dfs(digits);
    }
    bool dfs(vector<double> &digits)
    {
        //每一次递归，digits中的数字就少两个
        int n = digits.size();
        if (n == 1)
            return abs(digits[0] - 24) < 1e-5;
        //任选两个数字进行合并
        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                vector<double> newDigits;
                //把不如选的那些数字放回新数组中
                for (int k = 0; k < n; ++k)
                    if (k != i && k != j)
                        newDigits.push_back(digits[k]);

                //把这两个数字进行合并，通过每一种方法
                for (int op = 0; op < 6; ++op)
                {
                    newDigits.push_back(calculate(op, digits[i], digits[j]));
                    //递归
                    if (dfs(newDigits))
                        return true;
                    newDigits.pop_back();
                }
            }
        }
        return false;
    }
    //定义每一种运算，一共有6中运算 op范围是[0,5]
    double calculate(int op, double a, double b)
    {
        if (op == 0)
            return a + b;
        else if (op == 1)
            return a - b;
        else if (op == 2)
            return b - a;
        else if (op == 3)
            return a * b;
        else if (op == 4)
            return a / b;
        return b / a;
    }
};