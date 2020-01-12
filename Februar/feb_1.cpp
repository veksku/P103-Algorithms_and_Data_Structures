#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> a;

    int i;
    for(i=0;i<n;i++){
        int cena;
        cin >> cena;
        a.push(cena);
    }
    int m;
    cin >> m;

    vector<int> zelja;
    vector<int> brVozila;
    for(i=0;i<m;i++){
        int cena;
        cin >> cena;
        zelja.push_back(cena);
        int br;
        cin >> br;
        brVozila.push_back(br);
    }

    vector<int> automobili;

    while(!a.empty()){
        int vr = a.top();
        automobili.push_back(vr);                                                         
        a.pop();
        i++;
    }

    for(i=0;i<m;i++){
        int size = brVozila[i];
        if(size == n){
            cout << automobili[i] << " " << automobili[n-1];
            continue;
        }
        int min_razlika = automobili[n-1]+1;
        int min_i = n;
        int vrednost;
        int l = 0;
        int d = n-1;      
        int s = d/2;
        bool equalityFound = false;
        while(1){
            if(automobili[s] > zelja[i]){
                //cout << automobili[s] << " > " << zelja[i] << endl;
                vrednost = (automobili[s]-zelja[i]);
                if(min_razlika >= vrednost && min_i > s){
                    if(min_razlika > vrednost){
                        min_i = s;
                        min_razlika = vrednost;
                    }
                    else if(min_razlika == vrednost)
                        if(s < min_i)
                            min_i = s;
                }
                d = s;
                s = (d-l)/2 + l;
                if(s == d) break;
            }
            else if(automobili[s] < zelja[i]){
                //cout << automobili[s] << " < " << zelja[i] << endl;
                vrednost = (zelja[i] - automobili[s]);

                if(min_razlika >= vrednost){
                    if(min_razlika > vrednost){
                        min_i = s;
                        min_razlika = vrednost;
                    }
                    else if(min_razlika == vrednost)
                        if(s < min_i)
                            min_i = s;
                }
                l = s;
                s = (d-l)/2 + l;
                if(s == l) break;
            }
            else if(automobili[s] == zelja[i]){
                equalityFound = true;
                if(s < (size-1))
                    cout << automobili[0] << " " << automobili[size-1] << endl;
                else if( (n-s) < (size-1) )
                    cout << automobili[n-s] << " " << automobili[n-1] << endl;
                else{
                    int count = s - size + 1;
                    cout << automobili[count] << " " << automobili[s] << endl;
                }
                break;
            }
        }
        if(!equalityFound){
            if(min_i == n-1)
                cout << automobili[n-size+1] << " " << automobili[min_i] << endl;
            else if(min_i < size-1)
                cout << automobili[0] << " " << automobili[size-1] << endl;
            else
                cout << automobili[min_i-size+2] << " " <<automobili[min_i+1] << endl;
        }
    }

    return 0;
}