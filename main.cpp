#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

vector<pii> adj[100005];
int dist[100005][2];

int dijkstra(int s, int d) {
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
    memset(dist, INF, sizeof(dist));
    dist[s][0] = 0;
    pq.push(make_pair(0, make_pair(s, 0)));
    while (!pq.empty()) {
        int u = pq.top().second.first;
        int p = pq.top().second.second;
        int d = pq.top().first;
        pq.pop();
        if (dist[u][p] < d) continue;
        for (auto v : adj[u]) {
            int to = v.first;
            int len = v.second;
            if (dist[to][p^1] > dist[u][p] + len) {
                dist[to][p^1] = dist[u][p] + len;
                pq.push(make_pair(dist[to][p^1], make_pair(to, p^1)));
            }
        }
    }
    return dist[d][0] == INF ? -1 : dist[d][0];
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if(w % 2 != 0)
            continue;
        u--; v--;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    int ans = dijkstra(0, n-1);
    cout << ans << endl;
    return 0;
}