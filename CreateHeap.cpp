#include<bits/stdc++.h>
using namespace std;

void CreateMaxHeap(int h[], int n){
	int i = n;
    int temp = h[n];
    while (i > 0 && temp > h[i % 2 == 0 ? (i/2)-1 : i/2]){
        h[i] = h[i % 2 == 0 ? (i/2)-1 : i/2];
        i = i % 2 == 0 ? (i/2)-1 : i/2;
    }
    h[i] = temp;
}

void CreateMinHeap(int h[], int n){
	int i = n;
    int temp = h[n];
    while (i > 0 && temp < h[i % 2 == 0 ? (i/2)-1 : i/2]){
        h[i] = h[i % 2 == 0 ? (i/2)-1 : i/2];
        i = i % 2 == 0 ? (i/2)-1 : i/2;
    }
    h[i] = temp;
}

void traverse(int h[], int n){
	for(int i=0;i<n;i++){
		cout<<h[i];
		if (i < n-1){
            cout << ", ";
        }
	}
	cout<<" ] ";
}

void MaxHeap(int h[], int n){
	for (int i=0; i<n; i++){
        CreateMaxHeap(h, i);
    }
}

void MinHeap(int h[], int n){
	for (int i=0; i<n; i++){
        CreateMinHeap(h, i);
    }
}

int main(){
	int n;
	cout<<" Enter the size of your heap \n ";
	cin>>n;
	int heap[n];
	cout<<" Enter elements in your heap \n";
	for(int i=0;i<n;i++){
		cin>>heap[i];
	}
	int a;
	cout<<" 1. Enter 1 to create Max Heap \n 2. Enter 2 to create Min Heap \n";
	cin>>a;
	switch(a){
		case 1: MaxHeap(heap,n);
				cout<<" Max Heap : [ ";
				traverse(heap,n);

	
		case 2: MinHeap(heap,n);
				cout<<" Min Heap : [ ";
				traverse(heap,n);
				break;
		
	}	
	return 0;
	}
	

