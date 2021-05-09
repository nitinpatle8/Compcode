// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
    
    bool DFS(int s, int V, vector<int>adj[], int visited[]){
    
        bool t = false;
        
        for(int j = 0; j<adj[s].size(); j++){
            
            if(!visited[adj[s][j]]){
                visited[adj[s][j]] = 1;
                t = DFS(j, V, adj, visited);
                if(t){
                    return true;
                }
            }
            else{
                return true;
            }
            
        }
        return false;
    
    }
    
	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    int visited[V];
	    for(int i = 0; i<V; i++){
	        visited[i] = 0;
	    }
	    visited[0] = 1;
	    return DFS(0, V, adj, visited);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends