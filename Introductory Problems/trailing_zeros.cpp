#include <iostream>
using namespace std;

int cal_factor(int k){
    int res = 0;
    while (k%5 == 0){
        res++;
        k /= 5;
    }
    return res;
}

int main(){
    int n;
    cin >> n;

    int result = 0;
    for (int i=5; i<=n; i+=5){
        result += cal_factor(i);
    }    
    cout << result << endl;
    return 0;
}