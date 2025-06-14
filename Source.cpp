#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;
#define MAX 1000
#define INF 9999
//Function to print an edge
void printedge(int[]);
//Function to generate a random edges list
int edgeListGen(int[][3], int, int, int);
const int VERTICES = 10;

void BF(int edgeList[][3], int numEdges, int start_vertex, int BFValue[], int BFPrev[]) {
	// step 1: get all vertecies
	vector<int> Vertexes;
	Vertexes.reserve(numEdges * 2); // Reserve space for vertices
	for (int i = 0; i < numEdges; i++) {
		Vertexes.push_back(edgeList[i][0]);
		Vertexes.push_back(edgeList[i][1]);
	}
	sort(Vertexes.begin(), Vertexes.end());
	Vertexes.erase(unique(Vertexes.begin(), Vertexes.end()), Vertexes.end());

	int startVertexIndex = 0;
	for (int i = 0; i < VERTICES; i++) {
		if (Vertexes[i] == start_vertex) {
			startVertexIndex = i; // Tim chi so cua dinh v
		}
	}
	BFValue[startVertexIndex] = 0;
	cout << endl << "Start vertex: " << start_vertex << " index: " << startVertexIndex << endl;
	for (int i = 0; i < numEdges - 1; i++) { // Duyet qua tat ca cac canh
		int u = edgeList[i][0]; // Dinh bat dau cua canh
		if (u != start_vertex) continue; // Neu dinh bat dau khong phai la dinh bat dau thi bo qua
		int v = edgeList[i][1]; // Dinh ket thuc cua canh
		int weight = edgeList[i][2]; // Trong so cua canh
		int valueIndexV = 0; // Khoi tao chi so cua dinh v

		//cout << "Edge: " << u << " -> " << v << ", weight: " << weight << " with BFValue " << endl;
		if (BFValue[startVertexIndex] != -1) {
			for (int k = 0; k < VERTICES; k++) {
				if (Vertexes[k] == v) {
					valueIndexV = k; // Tim chi so cua dinh v
				}
			}
			if (BFValue[valueIndexV] != -1 && BFValue[valueIndexV] <= BFValue[startVertexIndex] + weight) {
				//cout << "continue " << endl;
				continue; // Neu dinh v da duoc cap nhat khoang cach toi thi bo qua
			}
			else {
				//cout << "update " << endl;
				BFValue[valueIndexV] = BFValue[startVertexIndex] + weight; // Cap nhat khoang cach toi dinh v
				BFPrev[valueIndexV] = startVertexIndex; // Cap nhat dinh truoc cua v
			}
		}
	}
	for (int k = 0; k < VERTICES; k++) {
		cout << BFValue[k] << " ";
	}
	cout << endl;

	for (int k = 0; k < VERTICES; k++) {
		cout << BFPrev[k] << " ";
	}
	cout << endl;
	for (int j = VERTICES - 1; j >= 0; j--) {
		int currentVertexIndex = j;
		int currentVertex = Vertexes[currentVertexIndex];
		if (currentVertex == start_vertex) continue;
		cout << "Vertex: " << currentVertex << ", index: " << currentVertexIndex << endl;
		for (int i = 0; i < numEdges - 1; i++) { // Duyet qua tat ca cac canh
			int u = edgeList[i][0]; // Dinh bat dau cua canh
			if (u != currentVertex) continue; // Neu dinh bat dau khong phai la dinh bat dau thi bo qua
			int v = edgeList[i][1]; // Dinh ket thuc cua canh
			int weight = edgeList[i][2]; // Trong so cua canh
			int valueIndexV = 0; // Khoi tao chi so cua dinh v

			//cout << "Edge: " << u << " -> " << v << ", weight: " << weight << " with BFValue " << endl;
			if (BFValue[currentVertexIndex] != -1) {
				for (int k = 0; k < VERTICES; k++) {
					if (Vertexes[k] == v) {
						valueIndexV = k; // Tim chi so cua dinh v
					}
				}
				if (BFValue[valueIndexV] != -1 && BFValue[valueIndexV] <= BFValue[currentVertexIndex] + weight) {
					//cout << "continue " << endl;
					continue; 
				}
				else {
					BFValue[valueIndexV] = BFValue[currentVertexIndex] + weight; // Cap nhat khoang cach toi dinh v
					BFPrev[valueIndexV] = currentVertexIndex; // Cap nhat dinh truoc cua v
				}



			}
		}
		for (int k = 0; k < VERTICES; k++) {
			cout << BFValue[k] << " ";
		}
		cout << endl;

		for (int k = 0; k < VERTICES; k++) {
			cout << BFPrev[k] << " ";
		}
		cout << endl;
	}

}
int main() {
	// enum Func_check { BF, BF_Path, Traveling, none };

	int edgeList[70][3];
	int numEdges = 70;
	int const Esize = 10;

	// Replace this line:
	// 

	// With the following code to read from the resource file path:
	ifstream fin("Input10A.txt");
	for (int i = 0; i < numEdges; i++) {
		fin >> edgeList[i][0] >> edgeList[i][1] >> edgeList[i][2];
	}
	fin.close();



	char start_vertices;
	char namelist[] = "?b";


	for (int i = 0; i < 2; i++) {
		start_vertices = namelist[i];
		int BFValue[Esize];
		int BFPrev[Esize];

		for (int k = 0; k < Esize; k++) {
			BFValue[k] = -1;
			BFPrev[k] = -1;
		}
		cout << start_vertices << endl;
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

