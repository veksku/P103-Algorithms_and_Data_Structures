#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> b(45);

bool jeIskoriscen(int x, vector<int> b){
    if( find(b.begin(), b.end(), x) == b.end())
        return false;
    else
        return true;
}

int bektrekKvadrati(vector <int>& a, vector<int>& c, int x, int i, int n){
    if(i == n-1){
        b[i] = x;
        return 1;
    }
    c[i] = x;

    //moguci sabirci f-ja
    int maxmoguci = x + n;
    int sabirak;
    queue<int> sabirci;

    for (int count1 = 4, count2 = 5; count1 <= maxmoguci; count1 += count2, count2 += 2){   
        sabirak = count1 - x;                                                                
        if(sabirak > 0  &&  !(jeIskoriscen(sabirak, c))){                                   
            sabirci.push(sabirak);
        }
    }

    int suma = 0;
    //ako nema sabiraka
    if(sabirci.empty()){
        c[i]=0;
        return 0;
    }
    //inace rekurzivno zovemo funkciju za sve sabirke    
    else{
        do{
            int value = sabirci.front();
            sabirci.pop();
            suma += bektrekKvadrati(a, c, value, i+1, n);
        } while(sabirci.size() != 0);

        if (suma){
            b[i]=x;
            return 1;
        }
        else{
            c[i]=0;
            return 0;
        }
    }
}

int main(){
    int n;
    cin >> n;

    vector<int> a;
    for(int i = 1; i<=n; i++){
        a.push_back(i);
    }
    vector<int> c(n);

    for(int i=0; i<n; i++){
        if(bektrekKvadrati(a, c, a[i], 0, n)){
            for(int i=0; i<n; i++)
                cout << b[i] << " ";
            return 0;
        }    
    }
    cout << "ne vazi";
    return 0;
}