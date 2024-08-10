#include <fstream>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct edge{
    long long u;
    long long v;
};

bool operator >(const edge& a, const edge& b)
{
    return a.u > b.u;
}
vector<long long> path;

long long distances(vector<long long>& deg, long long start, long long N, vector<vector<edge>>& gr) {
    //long long start = 1;
    long long end = N;
    long long n = gr.size();
    vector<bool> visited(n, false);
    vector<long long> dist(n, LLONG_MAX);
    vector<long long> parent(n, -1);
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while (!pq.empty()) {
        edge currEdge = pq.top();
        long long dv = currEdge.u;
        long long v = currEdge.v;
        pq.pop();
        
        if (!visited[v]) {
            visited[v] = true;
            for (const edge neighbour: gr[v]) {
                long long u = neighbour.u;
                long long cu = neighbour.v;
                if (dist[v] + cu + deg[v] <= dist[u]) {
                    parent[u] = v;
                    dist[u] = dist[v] + cu + deg[v];
                    pq.push({dist[u], u});
                }
            }
        }
    }
    long long curr = end;
    while (parent[curr] != -1) {
        path.push_back(curr);
        curr = parent[curr];
    }
    path.push_back(curr);
    reverse(path.begin(), path.end());
    return dist[end];
}


int main() {
    ifstream fin("input.in");
    ofstream fout("output.out");
    long long N, K, I, J;
    //cin >> N >> K;
    fin >> N >> K;
    //cin >> I >> J;
    fin >> I >> J;
    vector<vector<edge>> graph(N + 1);
    vector <long long> degrees(N + 1, 0);
    for (long long i = 0; i < K; i++) {
        long long u, v, w;
        //cin >> u >> v >> w;
        fin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
        degrees[u]++;
        degrees[v]++;
    }
    degrees[I] = 0;
    long long distance = distances(degrees, I, J, graph);
    
    //cout << distance << "\n";
    fout << distance << "\n";
    for (long long i = 0; i < path.size(); i++) {
        //cout << path[i] << ' ';
        fout << path[i] << ' ';
    }
    fin.close();
    fout.close();
}