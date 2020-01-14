#include <iostream>
#include <vector>

using namespace std;

unsigned long long brojParticija(int N) {
    vector<unsigned long long> dp(N+1, 0);
    dp[0] = 1;
    for (int smax = 1; smax <= N; smax++)
        for (int n = smax; n <= N; n++)
            dp[n] += dp[n-smax];
    return dp[N];
}

int main(){
    int n;
    cin >> n;

    cout << brojParticija(n);

    return 0;
}