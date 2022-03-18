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

int n, m, ai, bi, ci;

class dsu{
    public:
    vector<int> Rank;
    vector<int> parent;
    // vector<int> minPositive;

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
        }
        else if(Rank[a] > Rank[b]){
            parent[b] = a;
        }
        else{
            parent[a] = b;
            Rank[b]++;
        }
    }
};

dsu d;
V<int> cost;


int main(){

    cin >> n >> m;

    d.parent = V<int>(n+1);
    d.Rank = V<int>(n+1);

    cost = V<int>(n+1);

    loop(i, 0, n+1){
        d.Rank[i] = 0;
        d.parent[i] = i;
    }

    loop(i, 0, m){
        cin >> ai >> bi;
        d.UNION(ai, bi);
    }

    loop(i, 1, n+1){
        cin >> ci;
        if(ci < 0){
            cost[i] = inf+1;
        }
        else
            cost[i] = ci;
    }

    // cout << find_sum() << endl;
    V<int> min_val(n+1, inf + 1); 
    V<int> cont(n+1, 0);

    loop(i, 1, n+1){
        int p = d.findParent(i);
        cont[p]++;
        // if(cost[i] >= 0){
        min_val[p] = min(min_val[p], cost[i]);
        // }
        
    }

    int flag = 0;
    ll sum = 0;
    int min_cost = inf + 1;
    int no_of_sets = 0;

    loop(i, 1, n+1){
        if(cont[i] > 0){
            if(min_val[i] == inf + 1){
                flag = 1;
                break;            
            }
            else{
                no_of_sets++;
                sum += min_val[i];
                min_cost = min(min_cost, min_val[i]);
            }
        }
    }

    if(no_of_sets == 0){
        cout << 0 << endl;
    }
    else if(flag){
        cout << -1 << endl;
    }
    else{
        cout << (ll)min_cost * (no_of_sets-1) + sum - (ll)min_cost << endl;
    }
        

   return 0;
}
