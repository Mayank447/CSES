#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

bool comp(std::vector<int> &p1, std::vector<int> &p2){
    if (p1[0] == p2[0]) return p1[1] < p2[1];
    return p1[0] < p2[0];
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, a, b;
    std::cin >> n;

    std::vector<std::vector<int>> timings;
    for (int i=0; i<n; i++){
        std::cin >> a >> b;
        timings.push_back(std::vector<int>{a, 0, i});
        timings.push_back(std::vector<int>{b, 1, i});
    }

    // Main logic
    std::sort(timings.begin(), timings.end(), comp);

    int k = 0, k_max = 0, id;
    std::vector<int> assigned(n);
    std::list<int> s;

    for (int i=0; i<2*n; i++){
        // Guest arrives
        if (timings[i][1] == 0) {
            k++;

            if (!s.empty()) {
                id = s.front();
                s.pop_front();
            }
            else {
                id = k;
            }
            assigned[timings[i][2]] = id;
        }

        // Guest leaves
        else {
            k--;
            s.push_back(assigned[timings[i][2]]);
        }

        if (k > k_max) k_max = k;
    }

    std::cout << k_max << "\n";
    for (int i=0; i<n; i++){
        std::cout << assigned[i] << " ";
    }
    return 0;
}