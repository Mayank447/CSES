#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int factorial(int n){
    int res = 1;
    while (n > 1){
        res *= n;
        n--;
    }
    return res;
}

int main(){
    string s;
    cin >> s;

    int len=0, c[26] = {0};
    for (int i=0; s[i]!='\0'; i++){
        c[s[i]-97]++;
        len++;
    }

    int res = factorial(len);
    for (int i=0; i<26; i++){
        res /= factorial(c[i]);
    }    
    cout << res << endl;
    sort(s.begin(), s.end());

    while(true){
        cout << s << endl;
        
        int last = -1;
        for (int i=0; i < len-1; i++){
            if(s[i] < s[i+1]) last = i;
        }

        int to_swap = last + 1;
        if (last != -1){
            for (int i=last+1; i< len; i++){
                if ((s[i] > s[last]) && (s[i] < s[to_swap])) to_swap = i;
            }
            swap(s[last], s[to_swap]);
            sort(s.begin() + last + 1, s.end());
            continue;
        }
        break;
    }
    return 0;
}