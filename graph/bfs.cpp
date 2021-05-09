// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph
    
    
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    int visited[V];
        vector<int> ret_v;
        for(int i = 0; i<V; i++)
            visited[i] = 0;
        
	    queue<int> q;
	    
	    q.push(0);
	    visited[0] = 1;
	 
	    while(!q.empty()){
	        
	        int i = q.front();
	        q.pop();
	        ret_v.push_back(i);
	
	        for(int j = 0; j<adj[i].size(); j++){
	            
	            if(visited[adj[i][j]] == 0){
	                visited[adj[i][j]] = 1;
	                q.push(adj[i][j]);
	            }
	        }
	        
	    }
	    return ret_v;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    // 		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.bfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends