#include <iostream>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    int array[n+1];
    int swaps[m][2];
    int index_map[n+1];

    for (int i=0; i<n; i++) {
        std::cin >> array[i+1];
        index_map[array[i+1]] = i+1;
    }

    for (int i=0; i<m; i++) std::cin >> swaps[i][0] >> swaps[i][1];

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

    for (int i=0; i<m ; i++){
        if (swaps[i][0] == swaps[i][1]){
           std::cout << num_rounds << std::endl;
           continue;
        }

        int pos1 = swaps[i][0], pos2 = swaps[i][1];
        int x = array[pos1], y = array[pos2];
        
        // For x
        if (x > 1){
            if ((index_map[x-1] < pos1) && (index_map[x-1] > pos2)) num_rounds++;
            else if ((index_map[x-1] > pos1) && (index_map[x-1] < pos2)) num_rounds--;
        }

        if (x < n){
            if ((index_map[x+1] > pos1) && (index_map[x+1] < pos2)) num_rounds++;
            else if ((index_map[x+1] < pos1) && (index_map[x+1] > pos2)) num_rounds--;
        }

        // For y
        if (y > 1){
            if (index_map[y-1] < pos2 && index_map[y-1] > pos1) num_rounds++;
            else if (index_map[y-1] > pos2 && index_map[y-1] < pos1) num_rounds--;
        }

        if (y < n){
            if ((index_map[y+1] > pos2) && (index_map[y+1] < pos1)) num_rounds++;
            else if ((index_map[y+1] < pos2) && (index_map[y+1] > pos1)) num_rounds--;
        }

        // If the numbers are adjacent (there was no counting as there was no equality sign in position comparison)
        if (abs(x-y) == 1){
            if (x < y){
                if (pos1 < pos2) num_rounds++;
                else num_rounds--;
            }
            else {
                if (pos1 < pos2) num_rounds--;
                else num_rounds++; 
            }
        }

        // Making the swaps
        array[pos1] = y;
        array[pos2] = x;
        index_map[x] = pos2;
        index_map[y] = pos1;

        std::cout << num_rounds << std::endl;
    }

    return 0;
}