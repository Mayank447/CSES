#include <iostream>
#include <set>
#include <map>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int x[n];
    for (int i=0; i<n; i++) std::cin >> x[i];

    // Main logic
    int j=0;
    long long int length=0, sub_arrays=0;

    std::set<int> collected;
    std::map<int, int> pos;

    while (j < n){
        if (collected.find(x[j]) != collected.end()){
            int i = j - length;
            for (int k=i; k<=pos[x[j]]; k++){
                collected.erase(x[k]);
            }
            
            long long int k = j - (pos[x[j]] + 1);
            sub_arrays += length * (length+1)/2;
            sub_arrays -= k * (k+1)/2;
            length -= (pos[x[j]] - i + 1);
        }
        pos[x[j]] = j;
        collected.insert(x[j++]);
        length++;
    }

    sub_arrays += length * (length+1)/2;    

    std::cout << sub_arrays << "\n";
    return 0;
}