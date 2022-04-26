#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode *CreateTree(vector<int> &nums)
{
    int n = nums.size();
    vector<TreeNode *> v(n);
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
            v[i] = nullptr;
        else
            v[i] = new TreeNode(nums[i]);
    }
    int i = 0, j = 0;
    while (j < n)
    {
        if (v[i] != nullptr)
        {
            if (j + 1 == n)
                break;
            v[i]->left = v[++j];
            if (j + 1 == n)
                break;
            v[i]->right = v[++j];
        }
        i++;
    }
    return v[0];
}
int main()
{
    vector<int> t{1, 3, 0, 0, 2};
    TreeNode *root = CreateTree(t);
}