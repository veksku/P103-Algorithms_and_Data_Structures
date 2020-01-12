#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool sledecaMogucnost(string& s){
    int n = s.length();
    int i = n-1;
    while(( i >=0 && s[i] == 'p') || (i>0 && s[i-1] == 'p'))
        s[i--] = 'c';
    if(i<0)
        return false;
    s[i] = 'p';
    return true;
}

int main(){
    int n;
    cin >> n;
    string s(n,'c');

    int i,j;
    do{
        j = count(s.begin(), s.end(), 'p');
        cout << s << " " <<j << endl;  
    }while (sledecaMogucnost(s)); // c = 0, p = 1

    return 0;
}