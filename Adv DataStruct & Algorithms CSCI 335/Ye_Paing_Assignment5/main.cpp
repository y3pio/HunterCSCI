#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

#include "graph.h"

using namespace std;

int main()
{
    //cout << "Hello world!" << endl;
    enum EntryType {VERTEX, ADJECENT, WEIGHT, TERMINATES};
    //Entry type to determine txt file entry (word)

    ifstream myfile;
    myfile.open("graphfile.txt");
    string line, word;

    getline(myfile, line); //Read the first line for # of vertex
    int vertexCount=atoi(line.c_str()); //Set the vertex #;
    float graphArray[vertexCount][vertexCount]; //Make an array to store vertex/weight
    for(int i=0; i<vertexCount; i++)
        for(int j=0; j<vertexCount; j++)
            graphArray[i][j]=-1;


    for(int i=0; i<vertexCount; i++) //Will loop through all 5 lines containing the 5 vertex.
    {
        int adj=-1;
        float weight=-1;
        getline(myfile, line);
        istringstream iss(line);
        EntryType info=VERTEX;
        while(getline(iss, word, ' '))
        {
            for(int j=0; j<word.length(); j++)
            {
                if(word[j]=='.')
                    info=WEIGHT;
                else if(word[j]=='-')
                    info=TERMINATES;
            }

            if(info==ADJECENT)
            {
                //cout << "Adjecent:" << word << " " << endl;
                adj=atoi(word.c_str());
            }
            else if(info==WEIGHT)
            {
                //cout << "Weight:" << word << " " << endl;
                weight=atof(word.c_str());
                graphArray[i][adj]=weight;
            }

            info=ADJECENT;
        }
        //cout << endl;
    }
    myfile.close();

    ////////////
    // PART A //
    ////////////
    cout << "\---------------------"
         << "\nPart A)Adjacency List"
         << "\n---------------------" << endl;
    cout << "Vertex   Adjacency List (vertex:weight)" << endl;
    for(int i=0; i<vertexCount; i++)
    {
        cout << i << "    -   ";
        for(int j=0; j<vertexCount; j++)
        {
            if(graphArray[i][j]!=-1)
                cout << j <<":" << graphArray[i][j] << "| ";
        }
        cout << endl;
    }
    ///////////////////////
    //Create graph here!!//
    ///////////////////////

    Graph graphObj(vertexCount);
    for(int i=0; i<vertexCount; i++)
        for(int j=0; j<vertexCount; j++)
        {
            if(graphArray[i][j]!=-1) //Meaning it has a weight to another node.
            {
                //i is the vertex, j is the adjecent, and value is weight.
                graphObj.constructGraph(i, j, graphArray[i][j]);
            }
        }

    ////////////
    // PART B //
    ////////////
    //graphObj.testFunction();
    cout << "\n---------------------------------------"
         << "\nPart B)Shortest Path Dijkstra Algorithm"
         << "\n---------------------------------------" << endl;
    string input;
    int startVertex, endVertex;
    bool validInput=false;
    string repeat="y";
    //Do while loop to get starting vertex.
    do
    {
        do
        {
            cout << "Input starting vertex #(0-" << vertexCount-1 << "):";
            cin >> input;
            validInput=true; //assume input is valid integer string
            for(int i=0; i<input.length(); i++)
                if(isalpha(input[i])) //if alpha character found set valid to false
                    validInput=false;

            if(validInput)
                startVertex=atoi(input.c_str());

            if(startVertex>=vertexCount || startVertex<0) //if integer input is out of bound
                validInput=false;

            if(!validInput)
                cout << "Error input! Please try again..." << endl;

        }while(!validInput);

        //Do whule loop to get ending vertex.
        do
        {
            cout << "Input ending vertex #(0-" << vertexCount-1 << "):";
            cin >> input;
            validInput=true; //assume input is valid integer string
            for(int i=0; i<input.length(); i++)
                if(isalpha(input[i])) //if alpha character found set valid to false
                    validInput=false;

            if(validInput)
                endVertex=atoi(input.c_str());

            if(endVertex>=vertexCount || endVertex<0) //if integer input is out of bound
                validInput=false;

            if(!validInput)
                cout << "Error input! Please try again..." << endl;

        }while(!validInput);

        cout << "Starting vertex : " << startVertex << endl;
        cout << "Ending vertex   : " << endVertex << endl;
        graphObj.dijkstra(startVertex, endVertex);

        cout << "\nDo another search?(y/n):";
        cin >> repeat;
        cout << endl;
    }while(repeat!="n");

    graphObj.resetGraph();

    //////////
    //PART C//
    //////////
    cout << "\-------------------------------"
         << "\nPart C)Maximum Flow from A to B"
         << "\n-------------------------------" << endl;
    //Clean user input variable;
    input="";
    startVertex=-1;
    endVertex=-1;
    validInput=false;
    repeat="y";
    //Do while loop to get starting vertex.
    do
    {
        do
        {
            cout << "Input vertex A #(0-" << vertexCount-1 << "):";
            cin >> input;
            validInput=true; //assume input is valid integer string
            for(int i=0; i<input.length(); i++)
                if(isalpha(input[i])) //if alpha character found set valid to false
                    validInput=false;

            if(validInput)
                startVertex=atoi(input.c_str());

            if(startVertex>=vertexCount || startVertex<0) //if integer input is out of bound
                validInput=false;

            if(!validInput)
                cout << "Error input! Please try again..." << endl;

        }while(!validInput);

        //Do whule loop to get ending vertex.
        do
        {
            cout << "Input vertex B #(0-" << vertexCount-1 << "):";
            cin >> input;
            validInput=true; //assume input is valid integer string
            for(int i=0; i<input.length(); i++)
                if(isalpha(input[i])) //if alpha character found set valid to false
                    validInput=false;

            if(validInput)
                endVertex=atoi(input.c_str());

            if(endVertex>=vertexCount || endVertex<0) //if integer input is out of bound
                validInput=false;

            if(!validInput)
                cout << "Error input! Please try again..." << endl;

        }while(!validInput);

        cout << "Vertex A : " << startVertex << endl;
        cout << "vertex B : " << endVertex << endl;

        graphObj.dijkstra2(startVertex, endVertex);

        cout << "\nDo another search?(y/n):";
        cin >> repeat;
        cout << endl;
    }while(repeat!="n");

    graphObj.resetGraph();

    //////////
    //PART D//
    //////////
    cout << "\---------------------------"
         << "\nPart D)Maximum Network Flow"
         << "\n---------------------------" << endl;
    //Clean user input variable;
    input="";
    startVertex=-1;
    endVertex=-1;
    validInput=false;
    repeat="y";
    //Do while loop to get starting vertex.
    do
    {
        do
        {
            cout << "Input vertex A #(0-" << vertexCount-1 << "):";
            cin >> input;
            validInput=true; //assume input is valid integer string
            for(int i=0; i<input.length(); i++)
                if(isalpha(input[i])) //if alpha character found set valid to false
                    validInput=false;

            if(validInput)
                startVertex=atoi(input.c_str());

            if(startVertex>=vertexCount || startVertex<0) //if integer input is out of bound
                validInput=false;

            if(!validInput)
                cout << "Error input! Please try again..." << endl;

        }while(!validInput);

        //Do whule loop to get ending vertex.
        do
        {
            cout << "Input vertex B #(0-" << vertexCount-1 << "):";
            cin >> input;
            validInput=true; //assume input is valid integer string
            for(int i=0; i<input.length(); i++)
                if(isalpha(input[i])) //if alpha character found set valid to false
                    validInput=false;

            if(validInput)
                endVertex=atoi(input.c_str());

            if(endVertex>=vertexCount || endVertex<0) //if integer input is out of bound
                validInput=false;

            if(!validInput)
                cout << "Error input! Please try again..." << endl;

        }while(!validInput);

        cout << "Vertex A : " << startVertex << endl;
        cout << "vertex B : " << endVertex << endl;

        graphObj.dijkstra3(startVertex, endVertex);

        cout << "\nDo another search?(y/n):";
        cin >> repeat;
        cout << endl;
    }while(repeat!="n");

    return 0;
}
