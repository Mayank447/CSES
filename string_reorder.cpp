#include <iostream>
#include <string>
using namespace std;

int max_array(int* A){
    int max_id = 0, max_element=0;
    for (int i=0; i<26; i++){
        if(A[i] > max_element){
            max_element = A[i];
            max_id = i;
        }
    }
    return max_id;
}

int main(){
    string s;
    cin >> s;

    int c[26] = {0}, n = s.length();
    for (int i=0; i<n; i++){
        c[s[i]-'A']++;
    }

    for (int i=0; i<26; i++){
        if (n%2 == 1 && c[i] > n/2 + 1){
            cout << -1 << endl;
            return 0;
        }
        else if (n%2 == 0 && c[i] > n/2){
            cout << -1 << endl;
            return 0;
        }
    }

    string A (n, '0');
    int j=0;

    for (int i=0; i<26; i++)
    {
        int m = max_array(c);
        for(int k=0; k<c[m]; k++){
            A[j] = 'A'+m;
            j+=2;
            if (j>=n) j=1;
        }
        c[m] = 0;
    }
    
    cout << A << endl;
    return 0;
}