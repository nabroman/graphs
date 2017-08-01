#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

void dfs(int v, vector <bool> & used, vector <int> graph[], vector <int> & ans){
    used[v] = true;
    for (auto u: graph[v - 1]){
        if (!used[u]){
            dfs(u, used, graph, ans);
        }
    }
    ans.push_back(v);
}

void top_sort(vector <bool> & used, vector <int> graph[], vector <int> & ans){
    for (int i = 1; i <= n; ++i){
        if (!used[i]){
            dfs(i, used, graph, ans);
        }
    }
    reverse(ans.begin(), ans.end());
}

int main(){
    cin >> n >> m;
    
    vector <bool> used(n+1, false);
    vector <int> graph[n];
    vector <int> ans;
    
    
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> u >> v;
        graph[u - 1].push_back(v);
    }
    
    top_sort(used, graph, ans);
    
    for (int i = 0; i < ans.size(); i ++){
        cout << ans[i];
    }
    
    return 0;
}
