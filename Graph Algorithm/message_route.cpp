#include <bits/stdc++.h>
using namespace std;

int n, m;

void get_path(int *visited){
    vector<int> path;
    int x = n;
    while(x != 1){
        path.push_back(x);
        x = visited[x];
    }
    path.push_back(1);
    
    reverse(path.begin(), path.end());
    cout << path.size() << endl;
    for (int node : path){
        cout << node << " ";
    }
    cout << endl;
}

int main(){
    int f, s;
    cin >> n >> m;

    int visited[n+1] = {0};
    int distance[n+1] = {-1};
    vector<vector<int>> edge(n+1);
    for (int i=0; i<m; i++) {
        cin >> f >> s;
        edge[f].push_back(s);
        edge[s].push_back(f);
    }

    queue<int> bfs;
    bfs.push(1);
    distance[1] = 0;

    while (!bfs.empty()){
        f = bfs.front();
        bfs.pop();

        if(f == n) {
            get_path(visited);
            return 0;
        };

        for (int neighbor : edge[f]){
            if(!visited[neighbor]) {
                visited[neighbor] = f;
                distance[neighbor] = distance[f]+1;
                bfs.push(neighbor);
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}