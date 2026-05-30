#include <iostream>
#include <set>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int x, n, point;
    std::cin >> x >> n; 

    // Main logic
    std::set<int> sorted;
    sorted.insert(0);
    sorted.insert(x);

    std::multiset<int, std::greater<int>> length;
    length.insert(x);

    for (int i=0; i<n; i++){
        std::cin >> point;
        auto upper = sorted.upper_bound(point);
        auto lower = std::prev(upper);
        
        auto it = length.find(*upper - *lower); // returns only the first instance
        if (it != length.end()) {
            length.erase(it);
        }
        length.insert(point - *lower);
        length.insert(*upper - point);

        // std::cout << *upper << " " << *lower << std::endl;
        std::cout << *length.begin() << std::endl;
        sorted.insert(point);
    }
    return 0;
}