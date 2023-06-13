#include<bits/stdc++.h>
using namespace std;

signed main(){
    long long n; cin >> n;
    vector<complex<long long>> v(n);
    for (long long i = 0; i < n; i++) {
        long long x, y; cin >> x >> y;
        v[i] = {x, y};
    }
    v.push_back(v[0]);
    long long area = 0;
    long long b = 0;
    for (long long i = 0; i < n; i++) {
        complex<long long> x = v[i], y = v[i+1];
        area += (conj(x) * y).imag();
        complex<long long> z = y - x;
        long long g = __gcd(z.real(), z.imag());
        b += abs(g);
    }
    long long a = abs(area) - b + 2;
    cout << a/2 << ' ' << b;
}
