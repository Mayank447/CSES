// This is basically a Graph colouring problem w/ no. of colours = 2

#include <bits/stdc++.h>
using namespace std;

u_int n, m;

u_int complement(int x){
    if (x==1) return 2;
    return 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    u_int f, s, node, node_colour;
    cin >> n >> m;
    
    vector<vector<int>> edge(n+1);
    for (u_int i=0; i<m; i++){
        cin >> f >> s;
        edge[f].push_back(s);
        edge[s].push_back(f);
    }

    queue<int> bfs;

    u_int colour[n+1] = {0};
    u_int num_coloured = 0;
    u_int last_coloured = 0;
    
    while(num_coloured != n || !bfs.empty()){
        if (bfs.empty()){
            for (u_int i=last_coloured+1; i<=n; i++){
                if(!colour[i]){
                    colour[i] = 1;
                    num_coloured++;
                    bfs.push(i);
                    last_coloured = i;
                    break;
                }
            }
        }
        
        node = bfs.front();
        node_colour = colour[node];
        bfs.pop();

        for (u_int neighbour: edge[node]){
            if(node_colour == colour[neighbour]) {
                cout << "IMPOSSIBLE" << endl;
                return 0;   
            }
            else if (!colour[neighbour]){
                num_coloured++;
                colour[neighbour] = complement(node_colour);
                bfs.push(neighbour);
            }
        }
    }

    for (u_int i=1; i<=n; i++) cout << colour[i] << " ";
    cout << endl;
    return 0;
}