#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

#define N 5

struct Edge {
    int to;
    int weight;
};

vector<Edge> graph[N];
bool visited[N];
string kota[N] = {"Ikan Bakar Pak Harry (A)", "Gudang Kaleng Bekas (B)", "Sushi Kucing Alya (C)", "Kedai IKLC (D)", "Pasar Ikan Tengah Malam (E)"};

void DFS(int node) {
    visited[node] = true;
    cout << char('A' + node);
    for (auto &e : graph[node]) {
        if (!visited[e.to]) {
            cout << " -> ";
            DFS(e.to);
        }
    }
}

void BFS(int start, int goal) {
    queue<int> q;
    bool vis[N] = {false};
    int parent[N];
    for (int i = 0; i < N; ++i) parent[i] = -1;

    q.push(start);
    vis[start] = true;

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur == goal) break;
        for (auto &e : graph[cur]) {
            if (!vis[e.to]) {
                vis[e.to] = true;
                parent[e.to] = cur;
                q.push(e.to);
            }
        }
    }

    vector<int> path;
    int crawl = goal;
    if (parent[goal] == -1 && goal != start) {
        cout << "\nTidak ada jalur dari " << char('A' + start) << " ke " << char('A' + goal) << endl;
        return;
    }
    while (crawl != -1) {
        path.push_back(crawl);
        crawl = parent[crawl];
    }

    int totalJarak = 0;
    for (int i = (int)path.size() - 1; i > 0; --i) {
        int from = path[i];
        int to = path[i-1];
        for (auto &e : graph[from]) {
            if (e.to == to) {
                totalJarak += e.weight;
                break;
            }
        }
    }

    cout << endl;
    cout << "JALUR TERCEPAT PARUL (BFS):" << endl;
    for (int i = (int)path.size() - 1; i >= 0; --i) {
        cout << kota[path[i]] << endl;
        if (i > 0) {
            int from = path[i];
            int to = path[i-1];
            for (auto &e : graph[from]) {
                if (e.to == to) {
                    cout << e.weight << "m" << endl;
                    break;
                }
            }
        }
    }

    cout << endl;
    cout << "Jalur terpendek : ";
    for (int i = (int)path.size() - 1; i >= 0; --i) {
        cout << char('A' + path[i]);
        if (i > 0) cout << " -> ";
    }
    cout << endl;
    cout << "Total langkah  : " << (path.size() - 1) << " edge" << endl;
    cout << "Total jarak    : " << totalJarak << " meter" << endl;
}

int main() {

    graph[0].push_back({2, 2}); 
    graph[0].push_back({1, 5}); 

    graph[2].push_back({3, 1}); 
    graph[2].push_back({0, 2}); 

    graph[3].push_back({2, 1}); 
    graph[3].push_back({4, 3}); 
    graph[3].push_back({1, 4}); 

    graph[1].push_back({0, 5}); 
    graph[1].push_back({3, 4});

    graph[4].push_back({3, 3}); 

    for (int i = 0; i < N; ++i) visited[i] = false;
    cout << "PENJELAJAHAN PARUL (DFS dari A):" << endl;
    DFS(0);
    cout << endl << endl;

    BFS(0, 4);

    return 0;
}
