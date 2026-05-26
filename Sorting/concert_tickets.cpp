#include <iostream>
#include <set>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m, temp; 
    std::cin >> n >> m;

    int customers[m];
    std::multiset<int> ticket_price;
    for (int i=0; i<n; i++) {
        std::cin >> temp;
        ticket_price.insert(temp);
    }
    for (int i=0; i<m; i++) std::cin >> customers[i];

    // Main logic
    for (int i=0; i<m; i++){
        auto it = ticket_price.upper_bound(customers[i]);
        if (it == ticket_price.begin()){
            std::cout << -1 << std::endl;
            continue;
        }

        it--;
        std::cout << *it << std::endl;
        ticket_price.erase(it);
    }
    return 0;
}