#include <iostream>
#include <vector>
#include <algorithm>

auto comp(const std::pair<int, int> &p1, const std::pair<int, int> &p2){
    return p1.first < p2.first;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> movie(n);
    for (int i=0; i<n; i++) std::cin >> movie[i].first >> movie[i].second;
    sort(movie.begin(), movie.end(), comp);

    int num[n] = {0};
    num[n-1] = 1;

    for (int i = n-2; i > -1; i--){
        auto it = lower_bound(movie.begin(), movie.end(), std::make_pair(movie[i].second, 0), comp);

        if (it == movie.end()){
            num[i] = 1;
        }
        else {
            int index = distance(movie.begin(), it);
            num[i] = 1 + num[index]; 
        }
    
        num[i] = std::max(num[i+1], num[i]);
    }

    std::cout << num[0] << std::endl;    
    return 0;
}