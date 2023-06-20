// sqrt decomposition
// @author: Manoj Kumar Chatti

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int query(int l, int r,vector<int>&a,vector<int>&b int n, int m ) {
    int ans=1e9, lb = l/m, rb = r/m;
    if (lb == rb) {
      for (int i = l; i <= r; i++)ans=min(ans,a[i]);
    }
    else {
        for (int i = l, i< (lb+1)*m; i++) ans= min(ans,a[i]);
        for (int i = lb+1; i < rb; i++)ans=min(ans,b[i]);
        for (int i = rb*m; i <= r; i++)ans=min(ans,a[i]);
    }
    return ans;
}

void sqrt_decomposition(vector<int>&a, int n) {
    int m = sqrt(n), q, l, r;
    m += !(m*m == n);
    vector<int>b(m,1e9);
    for (int i = 0; i < n; i++) b[i/m] =min(b[i/m], a[i]);
    while(q--){
      cin>>l>>r;
      l--,r--; //0-based indexing
      cout<<query(l,r,a,b,n,m)<<"\n";
    }
}

int main() {
    int n;
    cin>>n;
    vector<int>a(n)
    for (int i = 0; i < n; i++) cin>>a[i];
    sqrt_decomposition(a, n);
}

// Input:
// 8 4
// 3 2 4 5 1 1 5 3
// 2 4
// 5 6
// 1 8
// 3 3

// Output:
// 2
// 1
// 1
// 4

// https://cses.fi/problemset/task/1647/
