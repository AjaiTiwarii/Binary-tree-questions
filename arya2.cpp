#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

lli solve(lli n, lli m, lli a, lli b, lli l, set<pair<lli, lli>> &st){
    if(l==1) return n*m;
    
    queue<pair<lli, lli>> q;
    q.push({a, b});
    lli count = 0;
    
    while (!q.empty()) {
        pair<lli, lli> cell = q.front();
        q.pop();
        count++;
        
        for(int i=0; i<4; i++){
            lli nx = cell.first + dx[i]*l;
            lli ny = cell.second + dy[i]*l;
            
            if(nx>=1 && nx<=n && ny>=1 && ny<=m && st.find({nx, ny}) == st.end()){
                st.insert({nx, ny});
                q.push({nx, ny});
            }
        }
    }
    
    return count;
}

int main() {
    int t; cin >> t;
    while(t--){
        lli n, m, a, b, l;
        cin >> n >> m >> a >> b >> l;
        
        set<pair<lli, lli>> st;
        st.insert({a,b});
        cout << solve(n,m,a,b,l,st) << endl;
    }
    
    return 0;
}
