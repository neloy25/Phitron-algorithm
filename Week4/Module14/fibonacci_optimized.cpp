#include<bits/stdc++.h>
using namespace std;

vector<long long> fib;

long long fibonacci(int n) {
    if(n < 2) return n;

    if(fib[n] != -1) return fib[n];
    fib[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return fib[n];
}

int main()
{
    int n;
    cin >> n;

    fib.assign(n + 1,-1);
    cout << fibonacci(n);
    return 0;
}

