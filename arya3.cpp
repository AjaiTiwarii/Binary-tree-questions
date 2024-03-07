#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main() {
    int t; cin >> t;
    while(t--){
        lli n, m, x0, y0, L;
        cin >> n >> m >> x0 >> y0 >> L;
        
        lli reachable_rows = (n - x0) / L + 1;
        if(x0 - L > 0) reachable_rows += (x0 - 1) / L;
        
        lli reachable_cols = (m - y0) / L + 1;
        if(y0 - L > 0) reachable_cols += (y0 - 1) / L;
        
        cout << reachable_rows * reachable_cols << endl;
    }
    
    return 0;
}
