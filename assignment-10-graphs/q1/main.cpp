#include <iostream>
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

	//display adjacency matrix
	void displayMatrix() {
		cout<<endl<<"Adjacency Matrix: "<<endl;
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++)
				cout<<adj[i][j]<<" ";
			cout<<endl;
		}
	}

	//display adjacency list
	void displayList() {
		cout<<endl<<"Adjacency List: "<<endl;
		for(int i=0; i<n; i++) {
			cout<<i<<"->";
			for(int j=0; j<n; j++) {
				if(adj[i][j]==1)
					cout<<j<<" ";
			}
			cout<<endl;
		}
	}

	//degrees of vertex
	void degree(int v) {
		int outdeg=0; //v->column
		int indeg=0; //row->v

		for(int i=0; i<n; i++) {
			outdeg+=adj[v][i];
			indeg+=adj[i][v];
		}

		cout<<endl<<"Outdegree of vertex "<<v<<": "<<outdeg<<endl;
		cout<<"Indegree of vertex "<<v<<": "<<indeg<<endl;
	}

	//adjacent vertices of a vertex{
	void adjVertice(int v) {
		cout<<endl<<"adjacent vertices of vertex "<<v<<": ";
		for(int i=0; i<n; i++) {
			if(adj[v][i]==1)
				cout<<i<<" ";
		}
		cout<<endl;
	}
	
	//total number of edges, directed graph
	void totalEdges(){
	    int edges=0;
	    for(int i=0; i<n; i++)
	        for(int j=0; j<n; j++)
	            edges+=adj[i][j];
	    cout<<endl<<"total number of edges: "<<edges<<endl;
	}
};

int main()
{
    Graph g;
    g.inputGraph();
    
    g.displayMatrix();
    g.displayList();
    
    int v;
    cout<<"enter vertex (0-"<<n-1<<"): ";
    cin>>v;
    
    g.degree(v);
    g.adjVertice(v);
    
    g.totalEdges();

	return 0;
}