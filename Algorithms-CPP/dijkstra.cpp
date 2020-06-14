#include<iostream>
using namespace std;
const int V = 9;
const int infinity = 9999;

int minDist(int dist[], bool set[]){
	int min, min_index;
	min = infinity;
	for(int v=0; v<V; v++){
		if(set[v] == false && dist[v] <= min){
			min = dist[v];
			min_index  = v;
		}
	}
	return min_index;
}


int print(int dist[]){
	for(int i=0; i<V; i++){
		cout << "Distance from the vertex " << i << " is: " << dist[i] << endl;
 	}
}

void dijsktra(int graph[V][V], int source){
	int dist[V];
	bool set[V];
	for(int i=0; i<V; i++){
		dist[i] = infinity;
		set[i] = false;
	}

	dist[source] = 0;

	for(int count = 0; count < V-1; count++){

	int u = minDist(dist, set);
	set[u] = true;

		for(int v=0; v<V; v++){
			if(!set[v] && graph[u][v] && dist[u] != infinity && (dist[u] + graph[u][v] < dist[v])){
			dist[v] = dist[u] + graph[u][v];
			}
		}
	}
	print(dist);
}


int main(){
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 

    dijsktra(graph,0);
}