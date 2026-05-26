#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

int find(int n){
    if(parent[n] == n){
        return n;
    }
    return parent[n] = find(parent[n]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, f, s, f_p, s_p;
    cin >> n >> m;
    
    for (int i=0; i<n; i++) parent.push_back(i);

    for (int i=0; i<m; i++){
        cin >> f >> s;
        f_p = find(f-1);
        s_p = find(s-1);
        if (f_p != s_p) parent[s_p] = f_p;
    }

    vector<int> representatives;
    for (int i = 0; i < n; i++) {
        if (parent[i] == i) representatives.push_back(i);
    }

    cout << representatives.size() - 1 << endl;
    for (size_t i = 1; i < representatives.size(); i++) {
        cout << representatives[0]+1 << " " << representatives[i]+1 << endl;
    }
    return 0;
}