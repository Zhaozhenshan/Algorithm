#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
class Solution
{
public:
    vector<vector<int>> edges;
    vector<int> dist;
    vector<int> visit;

    void bfs(int s)
    {
        //广度优先遍历不需要递归
        dist[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty())
        {
            int p = q.front();
            q.pop();
            for (const auto &v : edges[p])
            {
                if (dist[v] == INF)
                {
                    dist[v] = dist[p] + 1;
                    q.push(v);
                }
            }
        }
    }
    void dfs(int s)
    {
        visit[s] = 1;
        cout << "Now is visiting " << s << endl;
        for (int i = 0; i < edges[s].size(); i++)
        {
            if (!visit[edges[s][i]])
                dfs(edges[s][i]);
        }
    }

    bool isValidPath(int n, vector<vector<int>> &sides, int start, int end)
    {
        edges = vector<vector<int>>(n);
        visit = vector<int>(n, 0);
        //这里已经是一个可以用的邻接表
        for (const auto &v : sides)
        {
            edges[v[0]].push_back(v[1]);
            edges[v[1]].push_back(v[0]);
        }
        dfs(start);
        return visit[end];
    }
};
/*
4,[[0,1],[1,2],[2,3],[3,0]],0,2
true
*/
int main()
{
    int n = 4;
    vector<vector<int>> sides{{0, 1}, {1, 2}, {2, 3}, {3, 0}};
    int start = 0, end = 2;
    Solution a;
    cout << a.isValidPath(n, sides, start, end);
}