#include <iostream>
#include <set>
#include <map>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int songs[n];
    for (int i=0; i<n; i++) std::cin >> songs[i];

    // Main logic
    std::set<int> unique_sequence;
    int max_length = 0, length = 0;    
    std::map<int, int> song_pos;

    for (int i=0; i<n; i++){
        if (unique_sequence.contains(songs[i])){
            if (length > max_length) max_length = length;

            // Removing the elements
            for (int j=i-length; j<=song_pos[songs[i]]; j++){
                unique_sequence.erase(songs[j]);
            }
            length -= song_pos[songs[i]] - (i - length) + 1;
        }
        unique_sequence.insert(songs[i]);
        song_pos[songs[i]] = i;
        length++;
    }
    if (length > max_length) max_length = length;

    std::cout << max_length << std::endl;
    return 0;
}