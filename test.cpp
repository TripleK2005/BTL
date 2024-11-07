#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool solve(vector<int>& v , int n , int k, int kc) {
    int cnt = 1;
    int last = v[0];
    for(int i = 1; i < n; i++) {
        if( v[i] - last >= kc ) {
            cnt += 1;
            last = v[i];
        }
        if( cnt == k ) {
            return true;
        }
    }
    return false;
}
int main(){

    int coc , bo ; cin>>coc>>bo;

    vector<int> v(coc);
    for(int i=0;i<coc;i++) cin>>v[i];
    sort(v.begin(),v.end());

    int left = 1, right = v[coc-1] - v[0];
    int res = 0;

    while(left <= right) {
        int mid = (left + right) / 2;
        if(solve(v,coc,bo,mid)) {
            res = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }

    cout<<res<<endl;
    return 0;
}
