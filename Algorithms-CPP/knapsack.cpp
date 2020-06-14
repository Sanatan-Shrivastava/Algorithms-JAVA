#include<iostream>
using namespace std;

class knapsack
{
public:
	int weight, value;
};


int compare(knapsack x, knapsack y){
	double r1 = (double)x.value/x.weight;
	double r2 = (double)y.value/y.weight; 
	return r1>r2;
}

void knap(int targetWeight, int size, knapsack array[]){
	sort(array, array+size, compare);
	int currentWeight = 0;
	double res = 0.0;
	for(int i=0; i<size; i++){
		if(currentWeight + array[i].weight <= targetWeight){
			currentWeight = currentWeight + array[i].weight;
			res = res + array[i].value;
		}
		else{
			int remainWeight = targetWeight - currentWeight;
			res = res + (array[i].value * ((double)remainWeight/array[i].weight));

		}
	}
	cout << "Optimum value out of the knapsack is: " << res << endl;

}


int main(void){
	int size, targetWeight;
	cout << "Enter the number of objects: ";
	cin >> size;
	cout << "Enter the target weight: ";
	cin >> targetWeight;
	knapsack array[size];
	cout << "Enter the weight and value of all the objects: " << endl;
	for(int i=0; i<size; i++){
		cout << "Enter weight: ";
		cin >>  array[i].weight;
		cout << "Enter Value: ";
		cin >> array[i].value;
	}
	knap(targetWeight, size, array);
	return 0;
}