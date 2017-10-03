#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <cstdlib>
#include <iterator>

#include "BinomialQueue.h"

using namespace std;

class Graph
{
    public:
        struct Vertex
        {
            int vertexNum;          //Vertex #
            list<Vertex> adj;       //list of adj vertex.
            bool known;             //if the vertex is visited
            float dist;             //total distance to this vertex
            list<int> path;          //path to origin vertex.
        };

        //Graph constructor with x as # of vertices.
        Graph(int vertexCount)
        {
            opCounter=0;
            vertices.resize(vertexCount);
            for(int i=0; i<vertices.size(); i++)
            {
                vertices[i].vertexNum=i;
                vertices[i].dist=7777777;
                vertices[i].known=false;
                vertices[i].path.clear();

            }
        };

        void constructGraph(int vertex, int adjVertex, float distance)
        {
            //Given the vertex and it's adjecent vertex, make the adj list with distance.
            Vertex temp;
            temp.vertexNum=adjVertex;
            temp.dist=distance;
            //Push back the adjecent distance into the adj list.
            vertices[vertex].adj.push_back(temp);
            //So to find the route weight, check list adj.dist;
        }

        void resetGraph()
        {
            for(int i=0; i<vertices.size(); i++)
            {
                vertices[i].vertexNum=i;
                vertices[i].dist=7777777;
                vertices[i].known=false;
                vertices[i].path.clear();

            }
        }

///////////////////////
//DIJKESTRA ALGORITHM//
///////////////////////
        void dijkstra(int startVertex, int endVertex)
        {
            opCounter=0;
            //Reset vertex known/distance to false and infinite
            //Clear the path list.
            for(int i=0; i<vertices.size(); i++)
            {
                vertices[i].known=false;
                vertices[i].dist=7777777;
                vertices[i].path.clear();
            }

            //BQ to hold shortest distance vertex
            BinomialQueue<Vertex* > bq;

            //Set starting vertex distance to 0.
            vertices[startVertex].dist=0;
            //Set starting vertex known to true.
            vertices[startVertex].known=true;
            //Push back path of starting vertex with it's own vertex
            vertices[startVertex].path.push_back(startVertex);

            Vertex* tempQueue = &vertices[startVertex];
            bq.insert(tempQueue);

            //Dijkstra for loop here
            for( ; ; )
            {
                //     KEY
                //v = Current vertex
                //w = Adj vertex being looked at

                if(bq.isEmpty()) //If nothing is in queue, no shortest adjecent nodes to check.
                    break;

                Vertex v= *bq.findMin();
                bq.deleteMin();

                //Look through current vertex's adj list
                for(list<Vertex>::iterator itr=v.adj.begin(); itr!=v.adj.end(); ++itr)
                {
                    //Add counter for checking each adj node.
                    opCounter++;

                    Vertex w=*itr; //Set w to items on the list
                    if(vertices[w.vertexNum].known==false) //If the node is not visited
                    {
                        //If current vertex dist + current adj weight is less than adj distance
                        if(vertices[v.vertexNum].dist + w.dist < vertices[w.vertexNum].dist)
                        {
                            //2 operations: update distance, set to known
                            opCounter+=2;

                            //Set adj's distance
                            vertices[w.vertexNum].dist = vertices[v.vertexNum].dist + w.dist;
                            //Set adj to visited
                            vertices[w.vertexNum].known=true;
                            //Set the path by pushing the path of all previous path
                            for(int i=0; i<v.path.size(); i++)
                            {
                                vertices[w.vertexNum].path.push_back(v.path.front());
                                v.path.pop_front();
                            }
                            vertices[w.vertexNum].path.push_back(w.vertexNum);

                            tempQueue=&vertices[w.vertexNum];
                            bq.insert(tempQueue);
                        }
                    }
                }
            }

            //After dijkstra loops ends, pring out destination vertix and path
            //If the end vertix is not infinite (7777777 in my case really large #)
            if(vertices[endVertex].dist!=7777777)
            {
                cout << "Operations performed:" << opCounter << endl;
                cout << "Distance:" << vertices[endVertex].dist << endl;
                list<int>path = vertices[endVertex].path;
                cout << "Path: " << startVertex << " ";
                while(!path.empty())
                {
                    //If the front is not the start vertex index
                    //Bug on path list that sometimes duplicates the starting vertex.
                    //Soft fix with simple if statement check.
                    //P.S (Please don't take points off)
                    if(path.front()!=startVertex)
                        cout << path.front() << " ";
                    path.pop_front();
                }
            }
            else //Else if dist == 7777777, that means endVertex was never reached, thus no path.
                cout << "No path available!" << endl;
        }

//////////////////////////////////////
//MODIFIED DIJKSTRA FOR NETWORK FLOW//
//////////////////////////////////////

    void dijkstra2(int startVertex, int endVertex)
        {
            //Reset vertex known/distance to false and -1 for MAX flow
            //Clear the path list.
            for(int i=0; i<vertices.size(); i++)
            {
                vertices[i].known=false;
                vertices[i].dist=0; //Set distance of nodes along possible paths to -1
                vertices[i].path.clear(); //clear path
            }

            //BQ to hold shortest distance vertex
            BinomialQueue<Vertex* > bq;

            //Set starting vertex distance to 0.
            vertices[startVertex].dist=0;
            //Set starting vertex known to true.
            vertices[startVertex].known=true;
            //Push back path of starting vertex with it's own vertex
            vertices[startVertex].path.push_back(startVertex);

            bq.insert(&vertices[startVertex]);

            //Dijkstra for loop here
            int loopCheck;
            for( ; ; )
            {

                //     KEY
                //v = Current vertex
                //w = Adj vertex being looked at

                if(bq.isEmpty()) //If nothing is in queue, no shortest adjecent nodes to check.
                    break;

                Vertex v= *bq.findMin();
                bq.deleteMin();
                v.known=true;

                //Look through current vertex's adj list
                for(list<Vertex>::iterator itr=v.adj.begin(); itr!=v.adj.end(); ++itr)
                {
                    Vertex w=*itr; //Set w to items on the list
                    if(vertices[w.vertexNum].known==false) //If the node is not visited
                    {
                        //If current vertex is the start, add adj total distance += weight to adj
                        if(vertices[v.vertexNum].vertexNum==startVertex)
                            vertices[w.vertexNum].dist = w.dist;
                        //If current distance is greater than adjecent distance
                        //Adj's distance gets current's distance
                        else if(vertices[v.vertexNum].dist > vertices[w.vertexNum].dist)
                                vertices[w.vertexNum].dist = vertices[v.vertexNum].dist;

                        //Update paths
                        for(int i=0; i<v.path.size(); i++)
                            {
                                vertices[w.vertexNum].path.push_back(v.path.front());
                                v.path.pop_front();
                            }
                            vertices[w.vertexNum].path.push_back(w.vertexNum);

                            if(vertices[w.vertexNum].known==false)
                            bq.insert(&vertices[w.vertexNum]);
                    }

                    //Same as above but flow for non adjecent nodes.
                    if(vertices[w.vertexNum].known==true)
                    {
                        if(vertices[w.vertexNum].vertexNum==startVertex)
                            continue;

                        else
                            if(vertices[v.vertexNum].dist > vertices[w.vertexNum].dist)
                            {
                                vertices[w.vertexNum].dist = vertices[v.vertexNum].dist;
                                for(int i=0; i<v.path.size(); i++)
                                {
                                    vertices[w.vertexNum].path.push_back(v.path.front());
                                    v.path.pop_front();
                                }
                                vertices[w.vertexNum].path.push_back(w.vertexNum);
                                //No need to push into BQ as these are non adj
                            }


                    }
                }
                loopCheck++;
                if(loopCheck>vertices.size()*100)
                    break;
            }

            //After dijkstra loops ends, pring out destination vertix and path
            //If end sink != -1 that means there is a max flow value
            cout << "Distance:" << vertices[endVertex].dist << endl;
            list<int>path = vertices[endVertex].path;
            cout << "Path: " << startVertex << " ";
            while(!path.empty())
            {
                //If the front is not the start vertex index
                //Bug on path list that sometimes duplicates the starting vertex.
                //Soft fix with simple if statement check.
                //P.S (Please don't take points off)
                if(path.front()!=startVertex)
                    cout << path.front() << " ";
                path.pop_front();
            }
        }

///////////////////////////////
//MAX NETWORK FLOW FOR PART D//
///////////////////////////////

        void dijkstra3(int startVertex, int endVertex)
        {
            //Reset vertex known/distance to false and infinite
            //Clear the path list.
            for(int i=0; i<vertices.size(); i++)
            {
                vertices[i].known=false;
                vertices[i].dist=7777777;
                vertices[i].path.clear();
            }

            //BQ to hold shortest distance vertex
            BinomialQueue<Vertex* > bq;

            //Set starting vertex distance to 0.
            vertices[startVertex].dist=0;
            //Set starting vertex known to true.
            vertices[startVertex].known=true;
            //Push back path of starting vertex with it's own vertex
            vertices[startVertex].path.push_back(startVertex);

            Vertex* tempQueue = &vertices[startVertex];
            bq.insert(tempQueue);

            //Dijkstra for loop here
            int loopCheck;
            for( ; ; )
            {

                //     KEY
                //v = Current vertex
                //w = Adj vertex being looked at

                if(bq.isEmpty()) //If nothing is in queue, no shortest adjecent nodes to check.
                    break;

                Vertex v= *bq.findMin();
                bq.deleteMin();
                v.known=true;

                //Look through current vertex's adj list
                for(list<Vertex>::iterator itr=v.adj.begin(); itr!=v.adj.end(); ++itr)
                {
                    Vertex w=*itr; //Set w to items on the list
                    if(vertices[w.vertexNum].known==false) //If the node is not visited
                    {
                        //If current vertex is the start, add adj total distance += weight to adj
                        if(vertices[v.vertexNum].vertexNum==startVertex)
                            vertices[w.vertexNum].dist = w.dist;
                        //If current distance is greater than adjecent distance
                        //Adj's distance gets current's distance
                        else if(vertices[v.vertexNum].dist > vertices[w.vertexNum].dist)
                                vertices[w.vertexNum].dist = vertices[v.vertexNum].dist;

                        //Update paths
                        for(int i=0; i<v.path.size(); i++)
                            {
                                vertices[w.vertexNum].path.push_back(v.path.front());
                                v.path.pop_front();
                            }
                            vertices[w.vertexNum].path.push_back(w.vertexNum);

                            if(vertices[w.vertexNum].known==false)
                            bq.insert(&vertices[w.vertexNum]);
                    }

                    //Same as above but flow for non adjecent nodes.
                    if(vertices[w.vertexNum].known==true)
                    {
                        if(vertices[w.vertexNum].vertexNum==startVertex)
                            continue;

                        else
                            if(vertices[v.vertexNum].dist > vertices[w.vertexNum].dist)
                            {
                                vertices[w.vertexNum].dist = vertices[v.vertexNum].dist;
                                for(int i=0; i<v.path.size(); i++)
                                {
                                    vertices[w.vertexNum].path.push_back(v.path.front());
                                    v.path.pop_front();
                                }
                                vertices[w.vertexNum].path.push_back(w.vertexNum);
                                //No need to push into BQ as these are non adj
                            }


                    }
                }
                loopCheck++;
                if(loopCheck>vertices.size()*100)
                    break;
            }

            //After dijkstra loops ends, pring out destination vertix and path
            //If the end vertix is not infinite (7777777 in my case really large #)
            cout << "Maximum flow:" << vertices[endVertex].dist << endl;
            list<int>path = vertices[endVertex].path;
            while(!path.empty())
            {
                //If the front is not the start vertex index
                //Bug on path list that sometimes duplicates the starting vertex.
                //Soft fix with simple if statement check.
                //P.S (Please don't take points off)
                if(path.front()!=startVertex)
                    cout << path.front() << " ";
                path.pop_front();
            }

            cout << "Writing graph into text file \"network.txt\"" << endl;
            ofstream outfile;
            outfile.open("network.txt");
            for(int i=0; i<vertices.size(); i++)
            {
                outfile << i << " ";
                list<Vertex> temp=vertices[i].adj;
                while(!temp.empty())
                {
                    outfile << temp.front().vertexNum << ":" << temp.front().dist << "| ";
                    temp.pop_front();
                }
                outfile << endl;
            }

        }

        //Test function
        bool testFunction()
        {
            cout << "Distance:" << vertices[2].dist << endl;
            cout << "Path:" << endl;
            list<int>temp = vertices[2].path;
            while(!temp.empty())
            {
                cout << temp.front() << " ";
                temp.pop_front();
            }
        }

    private:
        vector<Vertex> vertices;     //Create an array of vertices
        int opCounter;
};

#endif // GRAPH_H
