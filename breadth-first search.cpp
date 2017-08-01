#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int start, queue <int> Q, vector <int> & range, vector <vector<int>> & graph){
    Q.push(start);
    range[Q.front()] = 0;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (auto v : graph[u - 1])
            if (range[v] == -1)
            {
                range[v] = range[u] + 1;
                Q.push(v);
            }
    }
    
}

int main(){
    int n, m, start;
    cin >> n >> m >> start;
    
    vector<vector<int> > graph(n + 1);
    vector <int> range(n + 1, -1);
    queue <int> Q;
    
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> u >> v;
        graph[u-1].push_back(v);
    }
    
    bfs(start, Q, range, graph);
    
    for (int i = 1; i < range.size(); i++){
        cout << range[i];
    }
    
    return 0;
}
