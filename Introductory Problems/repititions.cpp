#include <iostream>
#include <cstring>
using namespace std;
 
int main(void){
    char sequence[1000001];
    cin >> sequence;
 
    int length = strlen(sequence);
    int repeating_length = 0, max_repeating_length = 0;
    char repeating_character = '\0';
 
    for (int i=0; i < length; i++)
    {
        if (repeating_character != sequence[i]){
            if(repeating_length > max_repeating_length){
                max_repeating_length = repeating_length;
            }
            repeating_character = sequence[i];
            repeating_length = 1;
        }
 
        else {
            repeating_length++;
        }
    }
 
    if (repeating_length > max_repeating_length){
        max_repeating_length = repeating_length;
    }
 
    cout << max_repeating_length << endl;
    return 0;
}