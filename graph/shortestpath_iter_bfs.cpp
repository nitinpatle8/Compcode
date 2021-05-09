
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    int visited[1001];
    int d[1001];
    
    void initialise(){
        for(int i = 0; i<1001; i++){
            visited[i] = 0;
            d[i] = INT_MAX;
        }
    }
    
    
    
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        // Code here'
        
        initialise();
        
        queue<int> q;
        
        q.push(S);
        
        d[S] = 0;
        
        while(!q.empty()){
            int i = q.front();
            q.pop();
            for(int k = 0; k<adj[i].size(); k++){
                
                int p = adj[i][k][1] + d[i];
                int j = adj[i][k][0];
                
                if(visited[j] == 0 || p < d[j]){
                    q.push(j);
                    visited[j] = 1;
                    if(p < d[j]){
                        d[j] = p;
                    }
                }
            }
        }
        
        vector<int> ret_d;
        for(int i = 0; i<V; i++){
            ret_d.push_back(d[i]);
        }
        return ret_d;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends