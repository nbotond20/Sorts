#include <iostream>
#include <time.h>
#include "MergeSort.h"
#include <vector>

using namespace std;

static int type=0;
static int compare_count=0;

void merge(vector<int> &A, int u, int m, int v){
    int d;
    d = m-u;
    vector<int> Z;
    for(int i=u; i<m; i++){
        Z.push_back(A[i]);
    }
    int k = u;
    int j=0;
    int i=m;
    while(i<v && j<d){
        if(A[i] < Z[j]){
            compare_count++;
			A[k] = A[i];
            i++;
        }
        else{
            A[k] = Z[j];
            j++;
        }
        k++;
    }
    while(j<d){
        A[k] = Z[j];
        k++;
        j++;
    }
}

void ms(vector<int> &A, int u, int v){
    int m;
    if(u < v-1){
        m = (u+v)/2;
        ms(A, u, m);
        ms(A, m, v);
        merge(A, u, m, v);
    }
}

void mergeSort(vector<int> &A, int n){
    ms(A,0,n);
}

void MSort()
{
	//Menu
	/////////////////////////////////////////////
	int input;
	int n;
	vector<int> A;
	vector<int> B;
    do
    {
		std::cout << std::endl;
		std::cout << "--------------MergeSort--------------"<<std::endl;
		std::cout << "1: New Array" << std::endl;
        std::cout << "2: Print Array" << std::endl;
        std::cout << "3: Sort" << std::endl;
        std::cout << "4: Sort with detailed steps" << std::endl;
        std::cout << "5: Exit" << std::endl;
		std::cout <<"--------------------------------------"<<std::endl;
		std::cout << std::endl;

        std::cin >> input;
        switch (input)
        {
        case 1:
			cout << "Array size(Number of elements): ";
			int tmp;
			cin>>n;
			A.clear();
			B.clear();
			for(int i=0; i<n; i++)
			{
				cout<<"Number "<<i+1<<": ";
				cin>>tmp;
				A.push_back(tmp);
				B.push_back(tmp);
			}
			break;
		case 2:
			cout<<"Original list: ";				   
			for(int i=0; i<n; i++)					   
			{										   
				cout << B[i] << " ";				   
			}										   
			cout << endl;
			break;
		case 3:
			type = 0;
            mergeSort(A, n);
            cout<<"Sorted list: ";				   
			for(int i=0; i<n; i++)					   
			{										   
				cout << A[i] << " ";				   
			}
			for(int i=0; i<n; i++){
				A[i] = B[i];
			}									   
			cout << endl;
			//cout<<"Compare/Swap count: "<<compare_count<<endl;
			break;
		case 4:
            type = 1;
            mergeSort(A, n);
			cout<<"Sorted list: ";				   
			for(int i=0; i<n; i++)					   
			{										   
				cout << A[i] << " ";				   
			}
			for(int i=0; i<n; i++){
				A[i] = B[i];
			}										   
			cout << endl;
			//cout<<"Compare/Swap count: "<<compare_count<<endl;
			break;
		}
	}while(input!=5);
}