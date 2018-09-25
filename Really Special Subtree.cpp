// #include <bits/stdc++.h>
#include "stdc++.h"

using namespace std;

struct Edge {
    int u, v, w;
    Edge(int _u, int _v, int _w):u(_u),v(_v),w(_w) {}
};

int find(vector<int>& fa, int x) {
    return fa[x]==x ? x : fa[x]=find(fa, fa[x]);
}

int main()
{
    int g_nodes;
    int g_edges;

    cin >> g_nodes >> g_edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> g_from(g_edges);
    vector<int> g_to(g_edges);
    vector<int> g_weight(g_edges);

    for (int i = 0; i < g_edges; i++) {
        cin >> g_from[i] >> g_to[i] >> g_weight[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Write your code here.

    vector<Edge> e;
    for (int i=0; i<g_edges; ++i)
        e.emplace_back(g_from[i], g_to[i], g_weight[i]);

    sort(e.begin(), e.end(), [](const Edge& a, const Edge& b) {
        return a.w < b.w || (a.w==b.w && a.u+a.v<b.u+b.v);
    });

    vector<int> fa(g_nodes+1);
    iota(fa.begin(), fa.end(), 0);

    int ans = 0;
    for (auto& p : e) {
        int fx=find(fa, p.u), fy=find(fa, p.v);
        if (fx != fy) {
            fa[fx] = fy;
            ans += p.w;
        }
    }

    cout << ans << endl;

    return 0;
}

