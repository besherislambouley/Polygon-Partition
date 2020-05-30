/*
 * https://github.com/thecodingwizard/competitive-programming/blob/master/IOI/IOIPractice%2016-polygon.cpp
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 400
#define mp make_pair
#define mid (l+r)/2
#define Le Node * 2 
#define Ri Node * 2 + 1 
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
#define gc getchar_unlocked
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef pair<double,ll>pdi;
const ll inf=1e18;
const ll Mod=1e9+7;
const ld pai=acos(-1) ;
ll Dp [129][129] ;
ll Add ( ll x , ll y ) {
	return ( x + y ) % Mod ; 
}
ll Mul ( ll x , ll y ) {
	return ( x * y ) % Mod ;
}
ll Pow ( ll x , ll y ) {
	if ( y == 0 ) return 1ll ;
	ll Ret = Pow ( x , y / 2ll ) ;
	Ret = Mul ( Ret , Ret ) ;
	if ( y % 2 ) Ret = Mul ( Ret , x ) ;
	return Ret ;
}
ll Inv ( ll x ) {
	return Pow ( x , Mod -2 ) ;
}
ll Bt ( ll n , ll k ) {
        if ( n < 3 )  return 0ll ;
        if ( k == 0 ) return 1ll ;
	ll &Ret = Dp [n][k] ;
	if ( Ret != -1 ) return Ret ;
	Ret = 0 ;
	for ( ll i = 2 ; i < n - 1 ; i ++ ) {
		if ( i + 1 > ( n - i ) + 1 ) break ;
		for ( ll j = 0 ; j < k ; j ++ ) {
			Ret = Add ( Ret , Mul ( ( ( i * 2 == n ) ? n / 2 : n ) , Mul ( Bt ( i + 1 , j ) , Bt ( n - i + 1 , k - j - 1 ) ) ) ) ;
		}
	}
	Ret = Mul ( Ret , Inv ( k ) ) ;
	return Ret ;
}
int main () {
	mem ( Dp , -1 ) ;
	ll n , k ;
	cin >> n >> k ;
	cout << Bt ( n , k - 1 ) << endl ; 
}

