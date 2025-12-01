#include <iostream>
#include <queue>
using namespace std;

#define INF 100000

int n;

class Graph {
public:
	int cost[50][50];

	//input graph
	void inputGraph() {
		cout<<"enter number of vertices: ";
		cin>>n;
		
		cout<<"enter "<<n*n<<" elements for cost adjacency matrix (0 for no edge): "<<endl;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin>>cost[i][j];
				if(cost[i][j]==0&&i!=j)
				    cost[i][j]=INF;
			}
		}
		
	}

	//prim's algo to find min spanning tree
	void prim(){
	    int parent[50]; //store predecessor for MST
	    int minCost[50]; //min cost to connect each vertex
	    bool inMST[50]; //flag for vertex in MST
	    
	    for(int i=0; i<n; i++){
	        parent[i]=-1;
	        minCost[i]=INF;
	        inMST[i]=false;
	    }
	    
	    //start from vertex 0
	    minCost[0]=0;
	    parent[0]=-1;
	    
	    //max number of edges from each vertex = n-1
	    for(int count=0; count<n-1; count++){
	        //u = vertex with min cost needed not in MST
	        int u=-1;
	        int minKey=INF;
	        
	        //check all vertices in order to find which vertex to add to MST
	        for(int v=0; v<n; v++){
	            if(!inMST[v]&&minCost[v]<minKey){
	                minKey=minCost[v];
	                u=v;
	            }
	        }
	        
	        //found vertex, add in MST
	        inMST[u]=true;
	        
	        //update minCosts and parents
	        for(int v=0; v<n; v++){
	            if(cost[u][v]<minCost[v]&&!inMST[v]){
	                minCost[v]=cost[u][v];
	                parent[v]=u;
	            }
	        }
	    }
	    
	    //print MST
	    cout<<endl<<"edges in Minimum Spanning Tree: "<<endl;
	    int totalCost=0;
	    for(int i=1; i<n; i++){
	        cout<<parent[i]<<"-"<<i<<" (cost="<<cost[parent[i]][i]<<")"<<endl;
	        totalCost+=cost[parent[i]][i];
	    }
	    
	    cout<<"total cost of MST = "<<totalCost<<endl;
	}
};

int main()
{
    Graph g;
    g.inputGraph();
    
    g.prim();

	return 0;
}