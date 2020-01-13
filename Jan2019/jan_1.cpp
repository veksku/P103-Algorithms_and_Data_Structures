#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int iznos;
    cin >> iznos;
    
    int n;
    cin >> n;

    int a[n];
    int i,j,k;
    for(i=0; i<n; i++){
        int value;
        cin >> value;
        a[i]=value;
    }

    sort(a, a+n, greater<int>());

    int zbir;
    int brNacina=0;
    for(i=0; i<(n-2);i++){
        for(j=i+1, k=n-1; j<k;){
            zbir = a[i]+a[j]+a[k];
            if(zbir > iznos)
                j++;
            else if(zbir < iznos)
                k--;
            else if(zbir == iznos){
                brNacina++;
                j++;
                k++;
            }
        }
    }
    cout << brNacina;
    return 0; 
}