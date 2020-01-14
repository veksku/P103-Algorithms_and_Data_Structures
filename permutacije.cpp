#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool permutuj(vector<int>& permutacije){
	int n = permutacije.size();
	if(n==1)
		false;
	
	int i = n-2;
	while(i>=0 && permutacije[i] > permutacije[i+1])
		i--;

	if(i<0)
		return false;
		
	int j = n-1;
	while(permutacije[j] < permutacije[i])
		j--;
		
	swap(permutacije[i],permutacije[j]);
	
	for(j=n-1, i++; i<j;i++, j--)
		swap(permutacije[i],permutacije[j]);
		
	return true;
}

int main(){
	int n;
	cin >> n;
	int i;
	
	vector<int> permutacije;
	for(i=0;i<n;i++){
		permutacije.push_back(i+1);
	}
	do{
		for(i=0;i<n;i++)
			cout<< permutacije[i];
		cout<< endl;
	}while(permutuj(permutacije));
	
	return 0;
}
