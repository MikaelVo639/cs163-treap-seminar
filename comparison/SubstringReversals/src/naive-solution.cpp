#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen("main.inp" , "r" , stdin);
//    freopen("main.out" , "w" , stdout);
    int n , q; string s;
    cin >> n >> q >> s;;
    while (q--){
        int l , r;
        cin >> l >> r; l--; r--;
        int len = r - l + 1;
        for (int i = 0 ; i < len / 2 ; i++){
            swap(s[l + i] , s[r - i]);
        }
    }
    cout << s << "\n";
    return 0;
}

