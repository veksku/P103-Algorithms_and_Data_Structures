#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sledecaPermutacija(vector<int>& permutacija){
    int n = permutacija.size();

    int i = n - 2;
    while( i>= 0 && permutacija[i]>permutacija[i+1]) //1234 -> 1243 -> 1324 -> 1342 -> 1423
        i--;
    if(i== -1) return false;
    //                                  15243
    int j = n - 1;
    while(permutacija[j] < permutacija[i])
        j--;

    swap(permutacija[i], permutacija[j]);

    for(j = n-1, i++; i<j; i++, j--)
        swap(permutacija[i], permutacija[j]);
    return true;
}

bool ispunjavaSvojstvo(vector<int>& a){
    int n = a.size();
    for(int i=0; i< n-1; i++){
        if(a[i]%2 == a[i+1]%2)
            return false;
    }
    return true;
}

int main(){
    int n;
    cin >> n;

    vector<int> a;
    int i;
    for(i=0;i<n;i++){
        a.push_back(i+1);
        cout << i+1 << " ";
    }
    cout << endl;
    while(sledecaPermutacija(a)){
        if(ispunjavaSvojstvo(a)){
            for(i=0;i<n;i++)
                cout << a[i] << " ";
            cout << endl;
        }
        
    }
    return 0;
}