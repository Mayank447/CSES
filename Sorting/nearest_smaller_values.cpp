#include <iostream>
#include <list>
#include <vector>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> array(n);
    for (int i=0; i<n; i++) std::cin >> array[i];

    // Main logic
    std::list<std::pair<int, int>> linked_list;

    for (int i=0; i<n; i++){
        while(!linked_list.empty() && array[i] <= linked_list.back().first){
            linked_list.pop_back();
        }

        if (linked_list.empty()) std::cout << "0" << " ";
        else std::cout << linked_list.back().second << " ";

        linked_list.push_back(std::make_pair(array[i], i+1));
    }

    std::cout << "\n";
    return 0;
}