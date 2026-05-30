#include <iostream>
#include <set>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);    

    int n;
    std::cin >> n;

    int cube[n];
    for (int i=0; i<n; i++) std::cin >> cube[i];

    // Main logic
    int k = 0;
    std::multiset<int> discs;

    for (int i=0; i<n; i++){
        auto element = discs.upper_bound(cube[i]);
        if (element == discs.end()) k++;
        else discs.erase(element);
        discs.insert(cube[i]);
    }

    std::cout << k << std::endl;
    return 0;
}