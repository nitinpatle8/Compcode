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

int n, q, u, v, val;

vector<int> Rank;
vector<int> parent;

int findParent(int x){
    while(x != parent[x]){
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
   return x;
}
void UNION(int a, int b){
    a = findParent(a);
    b = findParent(b);
    if(Rank[a] < Rank[b]){
        parent[a]=b;
    }else if(Rank[a] > Rank[b]){
        parent[b] = a;
    }else{
        parent[a] = b;
        Rank[b]++;
    }
}

void solve(){
    cin >> n >> q;

    Rank = V<int> (n+1, 0);
    parent = V<int> (n+1);

    loop(i, 0, n+1){
        parent[i] = i;
    }

    V<PII> ones;

    loop(i, 0, q){
        cin >> u >> v >> val;
        if(val == 0){
            UNION(u, v);
        }
        else{
            ones.pb(make_pair(u, v));
        }
    }
    int flag = 0;

    V<bool> parity(n+1, false);
    V<bool> setting(n+1, false);

    loop(i, 0, ones.size()){
        PII p = ones[i];
        int p1 = findParent(p.F), p2 = findParent(p.S);

        if(p1 == p2){
            flag = 1;
            break;
        }
        else{
            // par[p1] = -1 && par[p2] == -1 // set both 0 & 0
            // par[p1] = -1 && par[p2] = 1 // set p1 = 1
            // par[p1] = -1 && par[p2] = 0 // set p1 = 0
            // par[p1] = 1 && par[p2] = 0
            // par[p1] = 1 && par[p2] = 1
            if(!setting[p1] && !setting[p2]){
                setting[p1] = true;
                setting[p2] = true;
                parity[p2] = true;
            }
            else if(setting[p1] && !setting[p2]){
                setting[p2] = true;
                parity[p2] = !parity[p1];
            }
            else if(!setting[p1] && setting[p2]){
                setting[p1] = true;
                parity[p1] = !parity[p2];
            }
            else{
                if(parity[p1] == parity[p2]){
                    flag = 1;
                    break;
                }
            }

        }
    }

    if(flag){
        cout << "no" << endl;
    }
    else{
        cout << "yes" << endl;
    }
}

int main(){

    FAST 

    test{
        solve();
    }

   return 0;
}