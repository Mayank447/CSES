#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Custom comparator: compares pairs ONLY by their .first value
auto comp (const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.first < p2.first;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> a(n);
    for (int i=0; i<n; i++){
        cin >> a[i].first;
        a[i].second = i+1;
    }
    sort(a.begin(), a.end());

    // Main logic
    for (int i=0; i<n; i++){
        int target = x - a[i].first;

        if (binary_search(a.begin(), a.end(), make_pair(target, 0), comp))
        {
            auto it = lower_bound(a.begin(), a.end(), make_pair(target, 0), comp);
            int index = distance(a.begin(), it);
            if (index == i) continue;
            
            cout << a[i].second << " " << a[index].second << endl;
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}