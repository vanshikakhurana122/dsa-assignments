#include <iostream>
#include <queue>
using namespace std;

int n;

class Graph {
public:
	int adj[50][50];

	//input graph
	void inputGraph() {
		cout<<"enter number of vertices: ";
		cin>>n;
		
		cout<<"enter "<<n*n<<" elements for adjacency matrix: "<<endl;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				cin>>adj[i][j];
	}

	void BFS(){
	    int start;
	    cout<<endl<<"enter starting value (0-"<<n-1<<"): ";
	    cin>>start;
	    
	    bool visited[n]={false};
	    int distance[n]={-1};
	    
	    queue<int> q;
	    
	    visited[start]=true;
	    distance[start]=0;
	    q.push(start);
	    
	    cout<<endl<<"BFS Traversal: ";
	    
	    while(!q.empty()){
	        int v=q.front();
	        q.pop();
	        
	        cout<<v<<" ";
	        
	        for(int i=0; i<n; i++){
	            if(adj[v][i]==1 && !visited[i]){
	                visited[i]=true;
	                q.push(i);
	                distance[i]=distance[v]+1;
	            }
	        }
	    }
	    
	    for(int i=0; i<n; i++){
	        if(!visited[i])
	            cout<<endl<<i<<" vertex not visited."<<endl;
	    }
	    
	    cout<<endl<<"distance of each vertex from starting vertex "<<start<<": "<<endl;
	    for(int i=0; i<n; i++){
	        cout<<"vertex "<<i<<": "<<distance[i]<<endl;
	    }
	}
};

int main()
{
    Graph g;
    g.inputGraph();
    
    g.BFS();

	return 0;
}