#include<iostream>
#include <list>
using namespace std;


class Graph
{
    int V;    // No. of vertices

    // Pointer to an array containing adjacency lists
    list<int> *adj;

    // A function used by DFS
    void DFSUtil(int v, bool visited[]);
public:
    Graph(int V);   // Constructor
    ~Graph();
    void addEdge(int v, int w);
    void connectedComponents();
};

// Method to print connected components in an
// undirected graph
void Graph::connectedComponents()
{
    int i=1;
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int v = 0; v < V; v++)
        visited[v] = false;

    for (int v=0; v<V; v++)
    {
        if (visited[v] == false)
        {
            // print all reachable vertices
            // from v

            cout<<i<<"\t \t";
            i++;
            DFSUtil(v, visited);

            cout << "\n \n";

        }
    }
    delete[] visited;
}

void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << ",";

    // Recur for all the vertices
    // adjacent to this vertex
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            DFSUtil(*i, visited);
}

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

Graph::~Graph()
{
    delete[] adj;
}

// method to add an undirected edge
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}


int main() {
    int array[20][20] = {

        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
        {0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},

         };

         Graph g(20);

        list<int> visted;
        list<int> visted1;

        for(int satir=0;satir<20;satir++)
        {
            for(int sutun=0;sutun<20;sutun++)
            {
                if((array[satir][sutun]==1)&&(array[sutun][satir]==1))
                {
                    /* add(1,4)
                        list(4,1)*/
                    bool t = false;
                    list <int> :: iterator it;
                    list <int> :: iterator it1;
                    for(it = visted.begin(), it1 =visted1.begin(); it != visted.end(); ++it,++it1)
                    {
                        if(satir == *it1 && sutun == *it){
                            t = true;
                            break;
                        }
                    }
                    if(!t){
                        visted.push_back(satir);
                        visted1.push_back(sutun);
                        g.addEdge(satir, sutun);
                    }


                }
            }
        }

        cout<<"Alt Bilesen: \t"<<"Dugumler \n";
    g.connectedComponents();
    return 0;
}
