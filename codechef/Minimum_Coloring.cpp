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

int n, m, x11, y11, x22, y22;

int change_p(int k){
    if(k == 1){
        return 2;
    }
    else{
        return 1;
    }
}

void solve(){
    cin >> n >> m; 
    cin >> x11 >> y11;
    cin >> x22 >> y22;

    V<V<int>> v(n+1, V<int> (m+1, 0));

    v[x11][y11] = 1;
    v[x22][y22] = 2;

    int md = abs(x22 - x11) + abs(y22 - y11);

    // cout << "yes" << endl;

    // md is even ans 3
    // md is odd ans 2
    int md_1 = x11 + y11 - 2;

    if(md_1%2 == 0){
        // start with 1
        loop(i, 1, n+1){
            if(i%2 == 1){
                int s = 1;
                loop(j, 1, m+1){
                    v[i][j] = s;
                    s = change_p(s);   
                }
            }
            else{
                int s = 2;
                loop(j, 1, m+1){
                    v[i][j] = s;
                    s = change_p(s);
                }
            }
        }
    }
    else{
        // start with 2
        loop(i, 1, n+1){
            if(i%2 == 0){
                int s = 1;
                loop(j, 1, m+1){
                    v[i][j] = s;
                    s = change_p(s);
                }
            }
            else{
                int s = 2;
                loop(j, 1, m+1){
                    v[i][j] = s;
                    s = change_p(s);
                }
            }
        }
    }

    
    // x2, y2 
    if(md % 2 == 0){
        if(x22 - 1 >= 1){
            v[x22-1][y22] = 3;
        }
        if(x22 + 1 <= n){
            v[x22+1][y22] = 3;
        }
        if(y22 - 1 >= 1){
            v[x22][y22-1] = 3;
        }
        if(y22 + 1 <= m){
            v[x22][y22 + 1] = 3;
        }   
    }

    v[x11][y11] = 1;
    v[x22][y22] = 2;
    
    loop(i, 1, n+1){
        loop(j, 1, m+1){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    
}

int main(){
    FAST

    test{
        solve();
    }
   return 0;
}