#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    int i;

    vector<pair<int, int>> vr;

    for(i=0;i<n;i++){
        int temp, vlaga;
        cin >> temp;
        cin >> vlaga;
        vr.push_back( make_pair(temp, vlaga));
    }
    sort(vr.begin(), vr.end()); //sortira rastuce prema vr[i].first

    int max_vlaga = -1;
    int br_subj_toplih = 0;
    
    //treba da krenemo od elementa gde je vr[i].first najveci a kod rastuceg sorta je to poslednji element
    for(i=n-1;i>=0;i--){ 
        if(vr[i].second > max_vlaga){
            max_vlaga = vr[i].second;
            br_subj_toplih++;
        }
    }
    cout << br_subj_toplih;
    return 0;
}