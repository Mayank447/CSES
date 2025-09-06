#include <iostream>
using namespace std;

int main(){
    char s[1000001];
    cin >> s;

    int c[26] = {0};
    for (int i=0; s[i]!='\0'; i++){
        c[s[i]-65]++;
    }

    int flag = -1;
    for (int i=0; i<26; i++){
        if (flag > -1 && c[i]%2==1){
            cout << "NO SOLUTION" << endl;
            return 0;
        }

        else if (c[i]%2==1) flag = i;
    }

    for (int i=0; i<26; i++){
        for (int j=0; j<c[i]/2; j++){
            cout << char(65+i);
        }
    }

    if (flag > -1){
        cout << char(65+flag);
    }
    for (int i=25; i>-1; i--){
        for (int j=0; j<c[i]/2; j++){
            cout << char(65+i);
        }
    }
    return 0;
}