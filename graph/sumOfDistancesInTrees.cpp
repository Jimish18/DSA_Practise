/*
Question - Sum Of Distances In Trees

Link - https://leetcode.com/problems/sum-of-distances-in-tree/description/
*/

#include <bits/stdc++.h>
using namespace std;

vector<unordered_set<int>> tree;
vector<int> res, cnt;

vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
    tree.resize(N);
    res.assign(N, 0);
    cnt.assign(N, 1);
    for (auto e : edges) {
        tree[e[0]].insert(e[1]);
        tree[e[1]].insert(e[0]);
    }
    dfs(0, -1);
    dfs2(0, -1);
    return res;

}

void dfs(int root, int pre) {
    for (auto i : tree[root]) {
        if (i == pre) continue;
        dfs(i, root);
        cnt[root] += cnt[i];
        res[root] += res[i] + cnt[i];
    }
}

void dfs2(int root, int pre) {
    for (auto i : tree[root]) {
        if (i == pre) continue;
        res[i] = res[root] - cnt[i] + cnt.size() - cnt[i];
        dfs2(i, root);
    }
}