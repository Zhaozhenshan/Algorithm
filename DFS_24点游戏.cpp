#include <bits/stdc++.h>
using namespace std;
class Solution
{
    constexpr static double eps = 1e-5;

public:
    bool dfs(vector<int> &nums, double res)
    { // init : dfs(nums, nums[0/1/2]
        for (int &i : nums)
        {
            if (i == -1)
                continue;
            int pre = i;
            i = -1;
            if (dfs(nums, res + pre) || dfs(nums, res - pre) || dfs(nums, res * pre) || dfs(nums, res / pre))
                return true;
            i = pre;
        }
        if (count(begin(nums), end(nums), -1) == 4 && abs(res - 24.0) < eps)
            return true;
        return false;
    }

    bool compute24(vector<int> &inputNumbers)
    {
        for (int i = 0; i < inputNumbers.size(); i++)
        {
            int pre = inputNumbers[i];
            inputNumbers[i] = -1;
            if (dfs(inputNumbers, pre))
                return true;
            inputNumbers[i] = pre;
        }
        return false;
    }
};
int main()
{
    vector<int> nums{1, 3, 4, 6};
    Solution a;
    cout << a.compute24(nums);
}