#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
private:
    TreeNode *root;
    vector<vector<int>> ans; //层次遍历结果

public:
    //力扣形式创建二叉树
    void create(vector<int> &nums)
    {
        int INF = INT_MAX;
        int n = nums.size();
        vector<TreeNode *> t;
        for (auto &x : nums)
        {
            if (x == INF)
                t.push_back(nullptr);
            else
            {
                t.push_back(new TreeNode(x));
            }
        }
        int i = 0, j = 0;
        while (j < n)
        {
            if (t[i] != nullptr)
            {
                if (j + 1 == n)
                    break;
                t[i]->left = t[++j];
                if (j + 1 == n)
                    break;
                t[i]->right = t[++j];
            }
            i++;
        }
        root = t[0];
    }
    //获取树的深度
    int getDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return 1;
        return max(getDepth(root->left), getDepth(root->right)) + 1;
    }
    //检查是否平衡
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        return isBalanced(root->left) &&
               isBalanced(root->right) &&
               abs(getDepth(root->left) - getDepth(root->right)) <= 1;
    }
    //层次遍历
    void dfs(TreeNode *root, int depth)
    {
        if (root == nullptr)
            return;
        if (depth == ans.size())
        {
            vector<int> temp;
            temp.push_back(root->val);
            ans.push_back(temp);
        }
        else
        {
            ans[depth].push_back(root->val);
        }
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }
    //打印层次遍历
    void print()
    {
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
                cout << ans[i][j] << " ";
            cout << endl;
        }
    }
    TreeNode *getRoot()
    {
        return root;
    }
};
int main()
{
    vector<int> nums{3, 9, 20, INT_MAX, INT_MAX, 15, 7};
    Solution a;
    a.create(nums);
    cout << a.isBalanced(a.getRoot());
}
