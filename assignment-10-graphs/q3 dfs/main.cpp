#include <iostream>
#include <stack>
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

	void DFS(){
	    int start;
	    cout<<endl<<"enter starting value (0-"<<n-1<<"): ";
	    cin>>start;
	    
	    bool visited[n]={false};
	    int d[n]={0}; //start time
	    int f[n]={0}; //end time
	    
	    stack<int> s;
	    int t=0; //time
	    
	    visited[start]=true;
	    d[start]=++t;
	    s.push(start);
	    
	    cout<<endl<<"DFS Traversal: ";
	    cout<<start<<" ";
	    
	    while(!s.empty()){
	        int v=s.top();
	        bool unvisited=false;
	        
	        //look for unvisited adjacent vertex
	        for(int i=0; i<n; i++){
	            if(adj[v][i]==1 && !visited[i]){
	                visited[i]=true;
	                d[i]=++t;
	                cout<<i<<" ";
	                s.push(i);
	                unvisited=true;
	                break;
	            }
	        }
	        
	        //if no unvisited pop and go back
	        if(!unvisited){
	            s.pop();
	            f[v]=++t;
	        }
	    }
	    
	    for(int i=0; i<n; i++){
	        if(!visited[i])
	            cout<<endl<<i<<" vertex not visited."<<endl;
	    }
	    
	    cout<<endl<<"entry (d) and exit (f) times: "<<endl;
	    for(int i=0; i<n; i++){
	        cout<<"vertex "<<i<<": d="<<d[i]<<", f="<<f[i]<<endl;
	    }
	}
};

int main()
{
    Graph g;
    g.inputGraph();
    
    g.DFS();

	return 0;
}