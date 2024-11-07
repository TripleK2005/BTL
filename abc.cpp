#include<bits/stdc++.h>
using namespace std;
int Min_ArrA[10005][10005] ;
int Min_ArrB[10005][10005] ;
int Max_ArrA[10005][10005] ;
int Max_ArrB[10005][10005] ;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m,n ,q ; cin>> m>> n >> q;
    int a[m] , b[n] ;
    for(int i=0;i<m;i++){ cin>>a[i] ; }
    for(int i=0;i<n;i++){ cin>>b[i] ; }
    for(int i=1;i<=m;i++){ Min_ArrA[i][i] = a[i-1] ; Max_ArrA[i][i] = a[i-1] ; }
    for(int i=1;i<=n;i++){ Min_ArrB[i][i] = b[i-1] ; Max_ArrB[i][i] = b[i-1] ; }
    //min
    int cnt = 1;
    for(int j=1;j<=m;j++) {
        for(int i=1;i+cnt<=m;i++) {
            Min_ArrA[i][i+cnt] = min(Min_ArrA[i][i+cnt-1],Min_ArrA[i+1][i+cnt]) ;
        } cnt++ ;
    }
    cnt =1 ;
    for(int j=1;j<=n;j++) {
        for(int i=1;i+cnt<=n;i++) {
            Min_ArrB[i][i+cnt] = min(Min_ArrB[i][i+cnt-1],Min_ArrB[i+1][i+cnt]) ;
        } cnt++ ;
    }
    //end min


    // max
    cnt = 1;
    for(int j=1;j<=m;j++){
        for(int i=1;i+cnt<=m;i++){
            Max_ArrA[i][i+cnt] = max(Max_ArrA[i][i+cnt-1],Max_ArrA[i+1][i+cnt]) ;
        }
        cnt++ ;
    }
    cnt = 1;
    for(int j=1;j<=n;j++){
        for(int i=1;i+cnt<=n;i++){
            Max_ArrB[i][i+cnt] = max(Max_ArrB[i][i+cnt-1],Max_ArrB[i+1][i+cnt]) ;
        }
        cnt++ ;
    }
    // end max
    while(q--){
        int u , v ; cin>> u >> v;
        cout<<max(Min_ArrA[1][u]*Min_ArrB[1][v],Max_ArrA[1][u] * Max_ArrB[1][v])<< " ";
        cout<<min({Min_ArrA[1][u]*Min_ArrB[1][v],Min_ArrA[1][u]*Max_ArrB[1][v],Min_ArrB[1][v]*Max_ArrA[1][u]}) <<endl;
    }
}