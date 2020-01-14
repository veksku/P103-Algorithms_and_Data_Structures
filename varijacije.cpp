#include <iostream>
#include <vector>

using namespace std;

bool variraj(vector<int>& varijacije,int n){
	int k = varijacije.size();
	if(k==1)
		return false;
		
	int i;
	for(i = k-1;i>=0 && varijacije[i] == n;i--)
		varijacije[i] = 1;
	
	if(i<0)
		return false;
		
	varijacije[i]++;
	
	return true;
}

int main(){
	int n,k;
	cin >> n >> k;
	int i;
	
	vector<int> varijacije(k,1);
		
	do{
		for(i=0;i<k;i++)
			cout << varijacije[i];
		cout << endl;
	}while(variraj(varijacije,n));
	
	return 0;
}
