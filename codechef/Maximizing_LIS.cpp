#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define all(a) a.begin(),a.end()
#define ld long double
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

int find_l_bound(V<int> & w, int s, int l, int x){

    int ans = -1;

    while(s <= l){
        int mid = (s+l)/2;

        if(w[mid] < x){
            ans = mid;
            s = mid + 1;
        }
        else{
            l = mid - 1;
        }
    }

    return ans;
}


void LongestIncreasingSubsequenceLength(V<int> & v, V<int> & w, V<int> &li){

    int n = v.size();

    w[0] = v[0];

    int l = 0;

    li[0] = 1;

    loop(i, 1, n){
        int l_bound = find_l_bound(w, 0, l, v[i]);
        
        w[l_bound+1] = v[i];

        l = max(l_bound + 1, l);

        li[i] = l+1;
    }

}

int find_u_bound(V<int> &t, int s, int l, int x){

    int ans = l+1;

    while(s <= l){
        int mid = (s+l)/2;

        if(x < t[mid]){
            ans = mid;
            l = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }

    return ans;

}

void LongestDecreasingSubsequenceLength(V<int> &v, V<int> &t, V<int> & rei){

    int n = v.size();

    t[n-1] = v[n-1];
    
    int l = n-1;

    rei[l] = 1;

    loopr(i, n-2, 0){
        int u_bound = find_u_bound(t, l, n-1, v[i]);

        t[u_bound-1] = v[i];

        l = min(u_bound-1, l);
        
        rei[i] = n-l;
    }

    // return n-l;

}

int n, ai;

void solve(){
    cin >> n;

    V<int> v(n);

    loop(i, 0, n){
        cin >> v[i];
    }

    V<int> w(n), li(n), rei(n);

    LongestIncreasingSubsequenceLength(v, w, li);

    // loop(i, 0, n){
    //     cout << li[i] << " ";
    // }
    // cout << endl;

    V<int> t(n);

    LongestDecreasingSubsequenceLength(v, t, rei);

    // loop(i, 0, n){
    //     cout << rei[i] << " ";
    // }
    // cout << endl;

    int bi = 0;

    loop(i, 0, n-1){
        bi = max(bi, li[i] + rei[i+1]);
    }

    cout << bi << endl;
    
}

int main(){
    FAST

    test{
        solve();
    }
   return 0;
}