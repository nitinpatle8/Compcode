
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/* Function to do DFS of graph

g : adjacency list of graph
N : number of vertices

return a list containing the DFS traversal of the given graph
*/

void dfsMat(vector<int> arr[], int visited[], int N, int start, vector<int> *ret){

    visited[start] = 1;
    ret->push_back(start);

    int i = 0;
    
    int llsize = arr[start].size();

    while(i<llsize){
        if(visited[arr[start][i]] == 0){
            dfsMat(arr, visited, N, arr[start][i], ret);
        }
        i++;
    }
    
}

vector <int> dfs(vector<int> g[], int N)
{
    
    // Your code here
    // Your code here
    vector<int> *ret = new vector<int>();
    int visited[N];
    memset(visited, 0, sizeof(visited));

    dfsMat(g, visited, N, 0, ret);
    
    
    return (*ret);

}

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {

        int N, E;
        cin>>N>>E;
        
        vector<int> g[N];
        bool vis[N];
        
        memset(vis, false, sizeof(vis));
        
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector <int> res = dfs(g, N);
        for (int i = 0; i < res.size (); i++)
            cout << res[i] << " ";
        cout<<endl;

    }
}  // } Driver Code Ends