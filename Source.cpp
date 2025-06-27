//#include <iostream>
//#include <fstream>
//#include <string.h>
//#include <cmath>
//#include <vector>
//#include <algorithm>
//#include <random>
//using namespace std;
//#define MAX 1000
//#define INF 9999
////Function to print an edge
//void printedge(int[]);
////Function to generate a random edges list
//int edgeListGen(int[][3], int, int, int);
//const int VERTICES = 10;
//
//void BF(int edgeList[][3], int numEdges, int start_vertex, int BFValue[], int BFPrev[]) {
//	// step 1: get all vertecies
//	vector<int> Vertexes;
//	Vertexes.reserve(numEdges * 2);
//	for (int i = 0; i < numEdges; i++) {
//		Vertexes.push_back(edgeList[i][0]);
//		Vertexes.push_back(edgeList[i][1]);
//	}
//	sort(Vertexes.begin(), Vertexes.end());
//	Vertexes.erase(unique(Vertexes.begin(), Vertexes.end()), Vertexes.end());
//
//	int startVertexIndex = 0;
//	for (int i = 0; i < VERTICES; i++) {
//		if (Vertexes[i] == start_vertex) {
//			startVertexIndex = i; // Tim chi so cua dinh v
//		}
//	}
//	BFValue[startVertexIndex] = 0;
//	//cout << endl << "Start vertex: " << start_vertex << " index: " << startVertexIndex << endl;
//	
//	Vertexes.push_back(start_vertex); // Add the start vertex to the list of vertices
//	//for (int i = 0; i < VERTICES + 1; i++) {
//
//	//	cout << Vertexes[i] << " ";
//	//}
//	//cout << endl;
//	for (int j = VERTICES ; j >= 0; j--) {
//		int currentVertexIndex = j;
//		int currentVertex = Vertexes[currentVertexIndex]; // Lay dinh hien tai tu chi so
//		if (j == VERTICES) currentVertexIndex = startVertexIndex;// Neu la lan dau tien thi gan chi so cua dinh bat dau
//		else if(currentVertex == start_vertex && j != VERTICES) continue; // Neu la dinh bat dau thi bo qua
//		//cout << "Vertex: " << currentVertex << ", index: " << currentVertexIndex << endl;
//		for (int i = 0; i < numEdges - 1; i++) { // Duyet qua tat ca cac canh
//			int u = edgeList[i][0]; // Dinh bat dau cua canh
//			if (u != currentVertex) continue; // Neu dinh bat dau khong phai la dinh bat dau thi bo qua
//			int v = edgeList[i][1]; // Dinh ket thuc cua canh
//			int weight = edgeList[i][2]; // Trong so cua canh
//			int valueIndexV = 0; // Khoi tao chi so cua dinh v
//
//			//cout << "Edge: " << u << " -> " << v << ", weight: " << weight << " with BFValue " << endl;
//			if (BFValue[currentVertexIndex] != -1) {
//				for (int k = 0; k < VERTICES; k++) {
//					if (Vertexes[k] == v) {
//						valueIndexV = k; // Tim chi so cua dinh v
//					}
//				}
//				if (BFValue[valueIndexV] != -1 && BFValue[valueIndexV] <= BFValue[currentVertexIndex] + weight) {
//					//cout << "continue " << endl;
//					continue; 
//				}
//				else {
//					BFValue[valueIndexV] = BFValue[currentVertexIndex] + weight; // Cap nhat khoang cach toi dinh v
//					BFPrev[valueIndexV] = currentVertexIndex; // Cap nhat dinh truoc cua v
//				}
//
//
//
//			}
//		}
//		//for (int k = 0; k < VERTICES; k++) {
//		//	cout << BFValue[k] << " ";
//		//}
//		//cout << endl;
//
//		//for (int k = 0; k < VERTICES; k++) {
//		//	cout << BFPrev[k] << " ";
//		//}
//		//cout << endl;
//	}
//
//}
///*
//The output of the BF_Path() function is a string containing the names of the vertices in the
//path separated by a whitespace, for example: "A D C B" representing the path going from
//A to D to C and then B. (Datatype string)
//*/
//string BF_Path(int edgeList[][3], int numEdges, int start_vertex, int end_vertex) {
//	int BFValue[VERTICES];
//	int BFPrev[VERTICES];
//	int holdArray[VERTICES];
//	for (int i = 0; i < VERTICES; i++) {
//		BFValue[i] = -1;
//		BFPrev[i] = -1;
//		holdArray[i] = -1;
//	}
//	int isFinished = 0;
//	while (isFinished == 0) {
//		BF(edgeList, numEdges, start_vertex, BFValue, BFPrev);
//		isFinished = 1; // Assume finished unless we find a change
//		for (int i = 0; i < VERTICES; i++) {
//			if (BFValue[i] != -1 && holdArray[i] != BFValue[i]) {
//				isFinished = 0; // Found a change, not finished
//				holdArray[i] = BFValue[i]; // Update hold array
//			}
//		}
//	}
//	vector<int> Vertexes;
//	Vertexes.reserve(numEdges * 2);
//	for (int i = 0; i < numEdges; i++) {
//		Vertexes.push_back(edgeList[i][0]);
//		Vertexes.push_back(edgeList[i][1]);
//	}
//	sort(Vertexes.begin(), Vertexes.end());
//	Vertexes.erase(unique(Vertexes.begin(), Vertexes.end()), Vertexes.end());
//	int startVertexIndex = 0;
//	int endVertexIndex = 0;
//	for (int i = 0; i < VERTICES; i++) {
//		if (Vertexes[i] == start_vertex) {
//			startVertexIndex = i; // Tim chi so cua dinh bat dau
//		}
//		if (Vertexes[i] == end_vertex) {
//			endVertexIndex = i; // Tim chi so cua dinh ket thuc
//		}
//	}
//
//
//	cout << "BFPrev: ";
//	for (int i = 0; i < VERTICES; i++) {
//		cout << BFPrev[i] << " ";
//	}
//	cout << "start: " << start_vertex << " end: " << end_vertex << endl;
//	string path = "";
//	int currentVertexIndex = endVertexIndex;
//	while (currentVertexIndex != -1 && currentVertexIndex != startVertexIndex) {
//		path = char(Vertexes[currentVertexIndex]) + string(" ") + path;
//		currentVertexIndex = BFPrev[currentVertexIndex];
//	}
//	if (currentVertexIndex == startVertexIndex) {
//		path = char(Vertexes[currentVertexIndex]) + string(" ") + path; 
//	}
//	else {
//		path = "No path foundd";
//	}
//	return path;
//}
//int main() {
//	// enum Func_check { BF, BF_Path, Traveling, none };
//
//	int edgeList[70][3];
//	int numEdges = 70;
//	int const Esize = 10;
//
//	// Replace this line:
//	// 
//
//	// With the following code to read from the resource file path:
//	ifstream fin("Input10A.txt");
//	for (int i = 0; i < numEdges; i++) {
//		fin >> edgeList[i][0] >> edgeList[i][1] >> edgeList[i][2];
//	}
//	fin.close();
//
//
//
//	char start_vertices;
//	char namelist[] = "?b";
//
//
//	for (int i = 0; i < 2; i++) {
//		start_vertices = namelist[i];
//		int BFValue[Esize];
//		int BFPrev[Esize];
//
//		for (int k = 0; k < Esize; k++) {
//			BFValue[k] = -1;
//			BFPrev[k] = -1;
//		}
//		cout << start_vertices << endl;
//		cout << "#####" << endl;
//
//		for (int j = 0; j < 2; j++) {
//			cout << "step:" << j + 1 << endl;
//			BF(edgeList, numEdges, start_vertices, BFValue, BFPrev);
//
//			for (int k = 0; k < Esize; k++) {
//				cout << BFValue[k] << " ";
//			}
//			cout << endl;
//
//			for (int k = 0; k < Esize; k++) {
//				cout << BFPrev[k] << " ";
//			}
//			cout << endl;
//		}
//	}
//	cout << BF_Path(edgeList, numEdges, '?', 'b') << endl;
//}
//
////support function definition 
//void printedge(int edge[]) {
//	cout << char(edge[0]) << char(edge[1]) << "," << edge[2] << endl;
//}

