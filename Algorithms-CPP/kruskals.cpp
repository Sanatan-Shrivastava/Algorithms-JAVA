#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

const int V = 5;
const int I = 9999;
int parent[V];

int find(int number){
	while(parent[number] != number){
		number = parent[number];
	}
	return number;
}


void unionFind(int i, int j){
	int a = find(i);
	int b = find(j);
	parent[a] = b;
}


void kruskal(int cost[][V]){
	int minCost = 0;
	for(int i=0; i<V; i++){
		parent[i] = i;
	}
	int edgeCount = 0;
	int i, j;
	while(edgeCount < V-1){
		int min = I, a = -1, b = -1;
			for(i=0; i<V; i++){
			for(j=0; j<V; j++){
				if(find(i) != find(j) && cost[i][j] < min){
					min = cost[i][j];
					a = i;
					b = j;
				}
			}
		}
		unionFind(a,b);
		cout << "Edge: " << edgeCount++ << " " << a  << " " << b << endl;
		cout << "Cost: " << min << endl;
		minCost = minCost + min;
	}
	cout << "The minimum cost is: " << minCost << endl;
}

int main(void){
	int cost[][V] = {
		{ I, 2, I, 6, I }, 
        { 2, I, 3, 8, 5 }, 
        { I, 3, I, I, 7 }, 
        { 6, 8, I, I, 9 }, 
        { I, 5, 7, 9, I }, 
    }; 

    kruskal(cost);
    return 0;
}