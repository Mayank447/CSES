#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

bool comp(std::pair<int, int> &p1, std::pair<int, int> &p2){
    return p1.second < p2.second;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    std::cin >> n >> k;

    std::vector<std::pair<int, int>> movie(n);
    for (int i=0; i<n; i++) std::cin >> movie[i].first >> movie[i].second;

    // Main logic
    std::sort(movie.begin(), movie.end(), comp);

    int count = 0;
    std::multiset<int> free_time;
    for (int i = 0; i < k; i++) free_time.insert(0);

    for (int i=0; i<n; i++){
        auto it = free_time.upper_bound(movie[i].first);
        if (it == free_time.begin()) continue;
        
        it = std::prev(it);
        free_time.erase(it);
        free_time.insert(movie[i].second);
        count++;
    }

    std::cout << count << "\n";
    return 0;
}