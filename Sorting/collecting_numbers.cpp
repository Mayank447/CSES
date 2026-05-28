#include <iostream>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int array[n];
    int index_map[n+1];

    for (int i=0; i<n; i++) {
        std::cin >> array[i];
        index_map[array[i]] = i;
    }

    // Main logic
    int num_rounds = 0;
    int number = 1;
    int prev_index = n+1, index;

    while(number != n+1){
        index = index_map[number];
        if (index < prev_index){
            num_rounds++;
        }
        prev_index = index;
        number++;
    }
    std::cout << num_rounds << std::endl;
    return 0;
}