#include <iostream>
#include <vector>

using namespace std;

bool bez11(vector<int>& a){
	int n = a.size();
	if(n == 1 && a[0] == 1)
		return false;
		
	int i = n-1;
	/*																										0000 > 0001 > 0011 > 0100 > 0101
	
	*/
	while((i>=0 && a[i] == 1) || (i>=0 && a[i-1] == 1))
		a[i--] = 0;
	
	if(i<0)
		return false;
		
	a[i] = 1;
	return true;		
}

int main(){
	int n;
	cin >> n;
	int i;
	
	vector<int> a(n,0);
		
	do{
		for(i=0;i<n;i++)
			cout << a[i];
		cout << endl;
	}while(bez11(a));
	
	return 0;
}
