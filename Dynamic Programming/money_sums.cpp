#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> array(n);
    for (int i=0; i<n; i++) std::cin >> array[i];

    // Main logic
    std::vector<int> vec;
    std::unordered_set<int> s;
    vec.push_back(0);

    for (int i=0; i<n; i++){
        int m = vec.size();
        for (int j=0; j<m; j++){
            if (s.find(vec[j] + array[i]) == s.end()){
                vec.push_back(vec[j] + array[i]);
                s.insert(vec[j] + array[i]);
            }
        }
    }

    std::sort(vec.begin(), vec.end());

    std::cout << vec.size()-1 << "\n";
    for (int i=1; i<vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
    return 0;
}