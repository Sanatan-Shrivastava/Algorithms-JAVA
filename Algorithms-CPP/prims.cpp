#include<iostream>
#include<algorithm>
using namespace std;
const int V = 5;
const int I = 9999;


int minKey(int key[], bool mstSet[]){
	int min = I, min_index;
	for(int i=0; i<V; i++){
		if(mstSet[i] ==  false && key[i] < min){
			min = key[i];
			min_index = i;
		}
	}
	return min_index;
}


void print(int parent[], int graph[][V]){
	cout << "Edge" << " " << "Weight" << endl;
	for(int i = 1; i<V; i++){
		cout <<  parent[i] << "-" << i << "   " << graph[i][parent[i]] << endl;
	} 
}

void prims(int graph[][V]){
	int parent[V];
	int key[V];
	bool mstSet[V];



	for(int i=0; i<V; i++){
		key[i] = I;
		mstSet[i] = false;
	}


	key[0] = 0;      //key stores key value of v.
	parent[0] = -1; //parent carries result, no result abhi.


	for(int count = 0; count < V-1; count++){
		int u = minKey(key, mstSet);
		mstSet[u] = true;


		for(int v=0; v<V; v++){
			if(graph[u][v] && mstSet[v]==false && graph[u][v] < key[v]){
				parent[v] = u;
				key[v] = graph[u][v];
			}
		}
	} 
	print(parent,graph);
}

int main(void){
	int graph[][V] = {
		{ 0, 2, 0, 6, 0 },  
        { 2, 0, 3, 8, 5 },  
        { 0, 3, 0, 0, 7 },  
        { 6, 8, 0, 0, 9 },  
        { 0, 5, 7, 9, 0 }
        };  
  
    prims(graph);
    return 0;
}