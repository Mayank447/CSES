#include <iostream>
#include <list>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    // Main logic
    std::list <int> linked_list;
    for (int i=0; i<n; i++) linked_list.push_back(i+1);

    auto it = linked_list.begin();
    while(linked_list.size()){
        it = std::next(it);
        if (it == linked_list.end()) it = linked_list.begin();
        
        auto next_it = std::next(it);
        if (next_it == linked_list.end()) next_it = linked_list.begin();

        std::cout << *it << " ";
        linked_list.erase(it);
        it = next_it;
    }

    std::cout << "\n";
    return 0;
}