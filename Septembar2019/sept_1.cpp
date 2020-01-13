#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    int i,j;

    vector<int> v;

    for(i=0;i<n;i++)
        for(j=0;j<n;j++){
            int broj;
            cin >> broj;
            v.push_back(broj);
        }

    int k;
    cin >> k;
    vector<int> el;

    for(i=0;i<k;i++){
        int broj;
        cin >> broj;
        el.push_back(broj);
    }
    int brojac;
    for(int z=0; z<k;z++){
        brojac = 0;
        int vr = el[z];
        i=0, j=0;
        while(i<n && j<n){
            if(v[i*n + j] < vr)
                j++;
            else if(v[i*n + j] > vr)
                i++;
            else if(v[i*n + j] == vr){
                brojac++;
                i++;
                j++;
            }
        }
        cout << brojac << " ";
    }
    return 0;
}