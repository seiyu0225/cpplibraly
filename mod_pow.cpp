
#include <bits/stdc++.h>
using i64 = long long;
// 繰り返し二乗法
i64 modPow(long long a, long long n, long long p) {
  if (n == 0) return 1; 
  if (n == 1) return a % p;
  if (n % 2 == 1) return (a * modPow(a, n - 1, p)) % p;
  long long t = modPow(a, n / 2, p);
  return (t * t) % p;
}