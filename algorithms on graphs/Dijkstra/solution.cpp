#include <fstream>
#include <vector>
#include <queue>

using namespace std;

struct edge{
    long long u;
    long long v;
};

bool operator >(const edge& a, const edge& b)
{
    return a.u > b.u;
}

long long distances(int N, vector<vector<edge>>& gr) {
    long long start = 1;
    long long end = N;
    long long n = gr.size();
    vector<bool> visited(n, false);
    vector<long long> dist(n, LLONG_MAX);
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
                if (dist[v] + cu <= dist[u]) {
                    dist[u] = dist[v] + cu;
                    pq.push({dist[u], u});
                }
            }
        }
    }
    return dist[end];
}


int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    long long n, m;
    //cin >> n >> m;
    fin >> n >> m;
    vector<vector<edge>> graph(n + 1);
    for (long long i = 0; i < m; i++) {
        long long u, v, w;
        //cin >> u >> v >> w;
        fin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    
    long long distance = distances(n, graph);
    
    //cout << distance;
    fout << distance;
    
    fin.close();
    fout.close();
}