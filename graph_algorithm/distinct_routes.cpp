#include <bits/stdc++.h>

using namespace std;
#define int long long
const int mod = 1e9 + 7;
void bfs(vector < vector < int >> & adj, vector < int > & parent, int src) {
    queue < int > q;
    q.push(src);
    parent[src] = src;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 1; i < adj.size(); i++) {
            if (adj[u][i] && parent[i] == -1) {
                parent[i] = u;
                q.push(i);
            }
        }
    }
}
int32_t main() {
    // your code goes here
    int n, m;
    cin >> n >> m;
    vector < vector < int >> adj(n + 1, vector < int > (n + 1, 0));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
        
    }
    bool set = true;
    vector < vector < int >> ans;
    while (true) {
        vector < int > parent(n + 1, -1);
        bfs(adj, parent, 1);

        if (parent[n] == -1)
            break;

        vector < int > path;
        int curr = n;

        while (curr != 1) {
            path.push_back(curr);
            curr = parent[curr];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        ans.push_back(path);

        curr = n;
        while (curr != 1) {
            int p = parent[curr];
            adj[p][curr]--;
            adj[curr][p]++;
            curr = p;
        }
    }
    cout << ans.size() << endl;
    for (auto & v: ans) {
        cout << v.size() << endl;
        for (auto & u: v) {
            cout << u << " ";
        }
        cout << endl;
    }
}