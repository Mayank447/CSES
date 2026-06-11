#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long int

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> task(n);
    for (int i=0; i<n ; i++){
        std::cin >> task[i].first >> task[i].second;
    }
    
    // Main logic
    // Sum of d i.e. deadline is constant, need to minimized individual finishing time.
    // a < b then a + (a + b) < b + (a + b)

    ll deadline_sum = 0;
    ll finishing_sum = 0;
    ll timeline = 0;
    
    std::sort(task.begin(), task.end());
    for (int i=0; i<n; i++){
        deadline_sum += task[i].second;
        finishing_sum += (timeline + task[i].first);
        timeline += task[i].first;
    }

    std::cout << deadline_sum - finishing_sum << "\n";
    return 0;
}