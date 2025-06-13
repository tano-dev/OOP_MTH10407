/*
#include <iostream>
#include <vector>
using namespace std;

const int CAP = 9999; //inf

struct Edge {
    int u, v;
    int w;
};


vector<int> bellmanFord(int n,vector<Edge> &edges, int value) {
    vector<int> dist(n + 1, CAP);
    dist[value] = 0;

    for (int i = 1; i <= n - 1; ++i) {
        bool checked = false;
        for (auto j : edges) {
            if (dist[j.u] != CAP && dist[j.v] > dist[j.u] + j.w) {
                dist[j.v] = dist[j.u] + j.w;
                checked = true;
            }
        }
        if (!checked) break;
    }

    for (auto i : edges) {
        if (dist[i.u] != CAP && dist[i.v] > dist[i.u] + i.w) {
            return {};
        }
    }

    return dist;
}
int main() {
    int n = 5;
    vector<Edge> edges = {
        {1, 2, 6},
        {1, 3, 7},
        {2, 3, 8},
        {2, 4, 5},
        {3, 4, -3},
        {4, 5, 9}
    };

    vector<int> dist = bellmanFord(n, edges, 1);

    if (dist.empty()) {
        cout << "Negative weight cycle detected.\n";
    }
    else {
        for (int i = 1; i <= n; ++i) {
            cout << "Distance from 1 to " << i << ": ";
            if (dist[i] == CAP)
                cout << "INF";
            else
                cout << dist[i];
            cout << '\n';
        }
    }
    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;
#define MAX 1000

//Function to print an edge
void printedge(int[]);
//Function to generate a random edges list
int edgeListGen(int[][3], int, int, int);
//Function to implement the Bellman-Ford algorithm
void BF(int edgeList[][3], int numEdges, char start_vertex, int BFValue[], int BFPrev[]) {
	// Initialize the distance to all vertices as infinite and the predecessor as -1
	for (int i = 0; i < 10; i++) {
		BFValue[i] = MAX;
		BFPrev[i] = -1;
	}
	// Set the distance to the starting vertex to 0
	BFValue[start_vertex - 'a'] = 0;
	// Relax edges repeatedly
	for (int i = 0; i < 9; i++) { // Repeat for |V| - 1 times
		for (int j = 0; j < numEdges; j++) {
			int u = edgeList[j][0] - 'a'; // Convert char to index
			int v = edgeList[j][1] - 'a'; // Convert char to index
			int weight = edgeList[j][2];
			if (BFValue[u] != MAX && BFValue[u] + weight < BFValue[v]) {
				BFValue[v] = BFValue[u] + weight;
				BFPrev[v] = u; // Store predecessor
			}
		}
	}
}

int main() {
    enum Func_check { BF, BF_Path, Traveling, none };

    bool randGen = 1;
    int edgeList[70][3];
    int numEdges = 70;
    int const Esize = 10;

    // Replace this line:
    // ifstream fin("Input10A.txt");

    // With the following code to read from the resource file path:
	ifstream fin("EdgeList.txt");
    for (int i = 0; i < numEdges; i++) {
        fin >> edgeList[i][0] >> edgeList[i][1] >> edgeList[i][2];
    }
    fin.close();

    char start_vertices;
    char namelist[] = "?b";

    for (int i = 0; i < 2; i++) {
        start_vertices = namelist[i];
        int BFValue[Esize] = { MAX }; // Initialize BFValue array with MAX  
        int BFPrev[Esize] = { -1 };   // Initialize BFPrev array with -1  

        //for (int k = 0; k < Esize; k++) {
        //    BFValue[k] = -1;
        //    BFPrev[k] = -1;
        //}

        cout << "#####" << endl;

        for (int j = 0; j < 2; j++) {
            cout << "step:" << j + 1 << endl;
            BF(edgeList, numEdges, start_vertices, BFValue, BFPrev);

            for (int k = 0; k < Esize; k++) {
                cout << BFValue[k] << " ";
            }
            cout << endl;

            for (int k = 0; k < Esize; k++) {
                cout << BFPrev[k] << " ";
            }
            cout << endl;
        }
    }
}






//support function definition 
void printedge(int edge[]) {
    cout << char(edge[0]) << char(edge[1]) << "," << edge[2] << endl;
}

int edgeListGen(int edgeList[][3], int numEdges, int numVertices, int initlimit = 1) {
    /*
    edgeList: output generated edgeList
    numEdges: number of edges
    numVertices: number vertices
    initlimit: if <=1 all edges weight is 1, else, edges weight random int [1,initlimit]


    //random generator init
    random_device rd;
    mt19937 gen(rd());

    //exception
    if (numEdges > (numVertices * (numVertices - 1)) / 2) {
        cout << "cannot create simple graph";
        return -1;
    }
    if (numEdges < numVertices - 1) {
        cout << "cannot create a connected (weak) graph";
        return -1;
    }

    //generate random vertices' names
    int* verList = new int[numVertices];
    vector<int> verName;
    for (int i = 33; i <= 126; i++) { verName.push_back(i); }
    shuffle(verName.begin(), verName.end(), gen);
    for (int i = 0; i < numVertices; i++) { verList[i] = verName[i]; }

    //generate random edges, ensure that each vertices will have at least 1 edges;
    bool flag = 0;
    vector<pair<int, int>> fullList;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (i == j) break;
            fullList.push_back({ verList[i],verList[j] });
        }
    }
    int* checkList = new int[numVertices];
    while (!flag) {
        shuffle(fullList.begin(), fullList.end(), gen);
        for (int i = 0; i < numEdges; i++) {
            edgeList[i][0] = fullList[i].first;
            edgeList[i][1] = fullList[i].second;
        }
        int count = 0;

        for (int i = 0; i < numEdges; i++) {
            if (count == numVertices) {
                flag = 1; break;
            }
            bool found0 = 0;
            bool found1 = 0;
            for (int j = 0; j < count; j++) {
                if (!found0 && edgeList[i][0] == checkList[j]) {
                    found0 = 1;
                }
                if (!found1 && edgeList[i][1] == checkList[j]) {
                    found1 = 1;
                }
                if (found0 && found1) break;
            }
            if (!found0) {
                checkList[count++] = edgeList[i][0];
            }
            if (!found1) {
                checkList[count++] = edgeList[i][1];
            }
            //cout<<"reshuffle edgeList\n";
        }
    }
    delete[] checkList;

    ofstream fout("EdgeList.txt");
    //generate the weights
    if (initlimit <= 1) {//All the weights will be 1
        for (int i = 0; i < numEdges; i++) {
            edgeList[i][2] = 1;
        }
    }
    else {//randomize edges' weights
        uniform_int_distribution<int> dist(0, initlimit);
        for (int i = 0; i < numEdges; i++) {
            edgeList[i][2] = dist(gen);
            fout << edgeList[i][0] << " " << edgeList[i][1] << " " << edgeList[i][2] << endl;
        }
    }
    fout.close();
    delete[]verList;
    return 1;
}

*/