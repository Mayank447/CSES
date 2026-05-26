#include <iostream>
#include <set>
using namespace std;

int main(){
    int n, x, temp;
    cin >> n >> x;

    multiset<int> w;
    for (int i=0; i<n; i++) {
        cin >> temp;
        w.insert(temp);
    }

    int num = 0;
    while(!w.empty()){
        auto it = w.upper_bound(x - *w.begin());

        if (it != w.begin()) it--;
        if (it != w.begin()) w.erase(it);

        num += 1;
        w.erase(w.begin());
    }

    cout << num << endl;
    return 0;
}
