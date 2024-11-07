#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

#define ll long long
using namespace std;

int main() {

    int n; cin>>n;
    vector<vector<int>> v(n+1);
    int limit=0;
    for(int i=1;i<=n;i++) {
        int x,y; cin>>x>>y;
        v[x].push_back(y);
        limit = max(limit,x);
    }

    ll cost = 0;
    priority_queue<int> pq;
    for(int i = limit; i >= 1; i--) {
        for(auto j : v[i]) {
            pq.push(j);
        }

        //ko rong thi lay phan tu co gia lon nhat
        if(!pq.empty()) {
            cost += pq.top();
            pq.pop();
        }
    }

    cout<<cost;
    return 0;
}
