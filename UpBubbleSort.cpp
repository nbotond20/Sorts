#include <iostream>
#include <time.h>
#include <vector>
#include "UpBubbleSort.h"

using namespace std;

static int type=0;
static int compare_count=0;
static int swap_count=0;

void upbubbleSort(vector<int> &A, int n){
    int i=n-1;
    int u;
    while(i>=1){
        cout<<"i:"<<i<<endl;
        u=0;
        for(int j=0; j<i; j++){
            compare_count++;
			cout<<"j:"<<j;
            if(A[j] > A[j+1]){
                swap_count++;
                swap(A[j], A[j+1]);
                u=j;
            }
        }
        cout<<endl;
        i=u;
    }
}

void UpBSort()
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
		std::cout << "-------------UpBubbleSort------------"<<std::endl;
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
            compare_count=0;
            upbubbleSort(A, n);
            cout<<"Sorted list: ";				   
			for(int i=0; i<n; i++)					   
			{										   
				cout << A[i] << " ";				   
			}
			for(int i=0; i<n; i++){
				A[i] = B[i];
			}									   
			cout << endl;
            cout<<"Swap count: "<<swap_count<<endl;
            cout<<"Compare count: "<<compare_count<<endl;
			break;
		case 4:
            type = 1;
            compare_count=0;
            upbubbleSort(A, n);
			cout<<"Sorted list: ";				   
			for(int i=0; i<n; i++)					   
			{										   
				cout << A[i] << " ";				   
			}
			for(int i=0; i<n; i++){
				A[i] = B[i];
			}										   
			cout << endl;
            cout<<"Swap count: "<<swap_count<<endl;
            cout<<"Compare count: "<<compare_count<<endl;
			break;
		}
	}while(input!=5);
}