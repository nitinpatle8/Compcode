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

int q, u, v;
char c;

int f1(PII & p1){
    return p1.F + p1.S;
}
int f2(PII & p1){
    return p1.F - p1.S;
}
int f3(PII & p1){
    return -p1.F + p1.S;
}
int f4(PII &p1){
    return -p1.F - p1.S;
}

struct comp1{
    bool operator()(PII & p1, PII & p2){
        return f1(p1) < f1(p2);
    }
};

struct comp2{
    bool operator()(PII & p1, PII & p2){
        return f2(p1) < f2(p2);
    }
};

struct comp3{
    bool operator()(PII & p1, PII & p2){
        return f3(p1) < f3(p2);
    }
};

struct comp4{
    bool operator()(PII & p1, PII & p2){
        return f4(p1) < f4(p2);
    }
}; 

void solve(){
    
    cin >> q;

    set<PII> pq1;
    set<PII> pq2;
    set<PII> pq3;
    set<PII> pq4;

    set<PII>::iterator it;

    V<PII> vec;

    int id = 1;

    int ans = 0;

    while(q--){
        cin >> c;
        switch (c)
        {
        case '+':{
            cin >> u >> v;
            u = u^ans;
            v = v^ans;
            PII p = make_pair(u, v);

            PII p1 = make_pair(f1(p), id);
            PII p2 = make_pair(f2(p), id);
            PII p3 = make_pair(f3(p), id);
            PII p4 = make_pair(f4(p), id);

            id++;
            vec.pb(p);
            pq1.insert(p1);
            pq2.insert(p2);
            pq3.insert(p3);
            pq4.insert(p4);
            break;}

        case '-':{
            cin >> u;
            u = u^ans;
            pq1.erase(make_pair(f1(vec[u-1]), u));
            pq2.erase(make_pair(f2(vec[u-1]), u));
            pq3.erase(make_pair(f3(vec[u-1]), u));
            pq4.erase(make_pair(f4(vec[u-1]), u));
            break;}

        case '?':{   
            cin >> u >> v;
            //
            u = u^ans;
            v = v^ans;
            PII p2 = make_pair(u, v);

            int maxa = 0;

            it = pq1.end();
            it--;
            maxa = max((*it).F - f1(p2), maxa);
            it = pq2.end();
            it--;
            maxa = max((*it).F - f2(p2), maxa);
            it = pq3.end();
            it--;
            maxa = max((*it).F - f3(p2), maxa);
            it = pq4.end();
            it--;
            maxa = max((*it).F - f4(p2), maxa);

            cout << maxa << endl;
            ans = maxa;
            //
            break;}        
        default:
            break;
        }
    }

    // cout << pq1.size() << endl;

    // while(!pq1.empty()){
    //     PII p = pq1.top();

    //     cout << p.F << " " << p.S << " " << p.F + p.S << endl;

    //     pq1.pop();
    // }


}

int main(){
    FAST

    solve();

   return 0;
}