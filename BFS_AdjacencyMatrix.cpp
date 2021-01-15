
#include <iostream>
#include <vector>
using namespace std;
class Graph
{
    private:
        int v;
        int **adj;
    public:
    Graph(int vertices)
    {
        v=vertices;
        adj=new int*[v];
        for (int row=0; row<v;row++){
            adj[row]=new int[v];
            for (int col=0;col<v ; col++){
                adj[row][col]=0;
            }
        }
    }
    /*
    * @Func: AddEdge
    * @Params: 
    *   src:- Integer.This is the source node of the edge
    *   dest:- Integer.This is the source node of the edge
    *   direction:- Integer(1,2).This indicate if connection 
    *   is bi-direction (2) or unidirection(1) 
    */
    void AddEdge(int src,int dest,int direction)
    {
        /* return on boudary conditions*/
        if (src >=v || dest>=v || src<0 || dest<0)
            return;
        if (direction==2){
           adj[src][dest]=1;
           adj[dest][src]=1;
        }
        else
        {
            adj[src][dest]=1;
        }
        
    }
    void PrintAdjMatrx()
    {
        for (int row=0; row<v;row++){
            cout<<"\n";
            for (int col=0;col<v ; col++){
                cout<<adj[row][col]<<" ";
            }
        }
    }
    
    void BFS(int startnode){
        /* Create an array to store the visited noted and init all with zero indicating none visited*/
        int visited[v]={0};
        /* Created this vector that will be iused as the queue to store the list of vertice connected the any vertice*/
        vector<int> q;
        q.push_back(startnode);
        visited[startnode]=1;
        while(! q.empty()){
            int vis=q[0];
            cout<<vis<<" ";
            q.erase(q.begin());
            for (int i=0;i<v;i++)
            {
                /* check if visited vertice is connected to vertice i and also that we have not visited this vertice before */
                if (adj[vis][i]==1 && visited[i]!=1){
                    /* Add the current vertice to the queue */
                    q.push_back(i);
                    /* set the current vertice as visited */
                    visited[i]=1;
                }
            }
            
        }
    }
};


int main() {
    // Write C++ code here
 
    cout<<"Create the Graph obj\n";
    Graph grphobj(4);  
    cout<<"Add vertices\n";
    grphobj.AddEdge(0,1,2);
    grphobj.AddEdge(0,2,2);
    grphobj.AddEdge(1,3,2);
  
    cout<<"Print the Adjacency Matrix";
    grphobj.PrintAdjMatrx();
    
    cout<<"\n BFS \n";
    grphobj.BFS(2);
    return 0;
}