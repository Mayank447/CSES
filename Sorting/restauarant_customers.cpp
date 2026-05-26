#include <iostream>
#include <vector>
#include <algorithm>

auto comp(const std::pair<int, int> &p1, const std::pair<int, int> &p2){
    return p1.first < p2.first;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, temp;
    std::cin >> n;

    std::vector<std::pair<int, int>> people;
    for (int i=0; i<n; i++){
        std::cin >> temp;
        people.push_back(std::pair<int, int>(temp, 0));
        
        std::cin >> temp;
        people.push_back(std::pair<int, int>(temp, 1)); 
    }
    sort(people.begin(), people.end(), comp);

    // Main logic
    int num_people = 0, max_people = 0;
    for (int i=0; i<2*n; i++){
        if (people[i].second == 0) num_people += 1;
        else num_people -= 1;

        if (num_people > max_people) max_people = num_people;
    }

    std::cout << max_people << std::endl;
    return 0;
}