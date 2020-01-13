#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    int i, j;
    vector<int>a;
    for(i=0; i<n; i++){
        for(j=0; j<n ;j++){
            int patka;
            cin >> patka;
            a.push_back(patka);
        }
    }
    
    vector<int> pom(n*n, 0);
    cout << endl;
    int max_stranica=0;
    pair<int, int> teme_max_kvadrata; //donje levo teme
    for(i=0; i<n; i++){
        for(j=0; j<n ;j++){
            if(i==0){
                pom[j] = a[j];
                continue;
            }
            if(j==0){
                pom[i*n] = a[i*n];
                continue;
            }
            if(a[i*n + j]){
                int vr = min(pom[i*n+j-1], min(pom[(i-1)*n+j], pom[(i-1)*n+j-1]));
                //cout << vr << " ";
                pom[i*n+j] = 1 + vr;
                if(pom[i*n+j] > max_stranica && ){
                    max_stranica = pom[i*n+j];
                    teme_max_kvadrata.first = i;
                    teme_max_kvadrata.second = j;
                }
            }
            else
                pom[i*n+j] = 0;
        }
    }
    //gornje levo
    cout << teme_max_kvadrata.first-max_stranica+1 << " " << teme_max_kvadrata.second-max_stranica+1 << endl;
    //donje levo
    cout << teme_max_kvadrata.first << " " << teme_max_kvadrata.second-max_stranica+1 << endl;
    //donje desno
    cout << teme_max_kvadrata.first << " " << teme_max_kvadrata.second << endl;
    //gornje desno
    cout << teme_max_kvadrata.first-max_stranica+1 << " " << teme_max_kvadrata.second;
    return 0;
}