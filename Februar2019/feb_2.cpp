#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int najmanjaPredavanja(vector<int>& a, vector<int> arr){
    int i;
    int n=a.size();
    int k=arr.size();
    int start=0, start_value = a[start], end;
    int min = n;
    for(i=0; i<n; i++){
        arr[a[i]]++;
        if(arr[a[i]]-1 >= 0){
            int terminate=0;
            for(int j=1; j<k; j++){
                if(arr[j]==0){
                    terminate=1;
                    break;
                }
            }
            if(!terminate){
                end = i;
                if( ((end+1) - start) < min)
                    min = (end+1) - start;
                start++;
                start_value = a[start];
                continue;
            }
        }
        while(arr[a[start]]>1){
            arr[a[start]]--;
            start++;
            start_value = a[start];
        }
    }
    return min;
}

int main(){
    int k,n;
    cin >> k;
    cin >> n;
    vector<int> a;
    int i;
    for(i=0;i<n;i++){
        int kompanija;
        cin >> kompanija;
        a.push_back(kompanija);
    }
    vector<int> arr;
    arr.push_back(1);
    for(i=1; i<=k; i++)
        arr.push_back(0);

    int amount = najmanjaPredavanja(a, arr);

    cout << amount;
    return 0;
}