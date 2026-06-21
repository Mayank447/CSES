#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

bool comp(std::tuple<int, int, int> &p1, std::tuple<int, int, int> &p2){
    if (std::get<0>(p1) != std::get<0>(p2))
         return std::get<0>(p1) > std::get<0>(p2);

    return std::get<1>(p1) < std::get<1>(p2);
}

int main(){
    int n, a, b;
    std::cin >> n;

    std::vector<std::tuple<int, int, int>> ranges;
    for (int i=0; i<n; i++){
        std::cin >> a >> b;
        ranges.push_back(std::make_tuple(a, b, i));
    }

    std::sort(ranges.begin(), ranges.end(), comp);
    std::vector<int> contains(n);
    std::vector<int> is_contained(n);

    // Contains
    int current_min = 1000000001;
    for (int i=0; i<n; i++){
        auto [a, b, index] = ranges[i];
        if (current_min <= b) contains[index]=1;
        else contains[index]=0;

        if (std::get<1>(ranges[i]) < current_min)
            current_min=std::get<1>(ranges[i]);
    }

    // Is contained
    int current_max = 0;
    for (int i=n-1; i>=0; i--){
        auto [a, b, index] = ranges[i];
        if (current_max >= b) is_contained[index]=1;
        else is_contained[index]=0;

        if (std::get<1>(ranges[i]) > current_max)
            current_max=std::get<1>(ranges[i]);
    }
    
    for (int i=0; i<n; i++) std::cout << contains[i] << " ";
    std::cout << "\n";

    for (int i=0; i<n; i++) std::cout << is_contained[i] << " ";
    std::cout << "\n";
    return 0;
}