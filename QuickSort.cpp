#include <iostream>
#include <time.h>
#include <vector>
#include "QuickSort.h"

using namespace std;

static int counter = 0;
static int pivot_type=0;
static int info_type=0;

int partition(vector<int> &A, int p, int r){
	srand(time(NULL));
	counter++;
	int i;
	switch(pivot_type){
		case 0:
			i=p;
			break;
		case 1:
			i = (p+r)/2;
			break;
		case 2:
			i = (rand() % r) + p;
			break;
	}
	int  x= A[i];
	A[i] = A[r];
	i = p;
	while(i<r && A[i]<=x){
		i++;
	}
	if(i<r){
		int j= i+1;
		while(j<r){
			if(A[j] < x){
				swap(A[i], A[j]);
				i++;
			}
			j++;
		}
		A[r] = A[i];
		A[i] = x;
	}
	else{
		A[r] = x;
	}
	if(info_type == 1){
		//Print list
		/////////////////////////////////////////////
		cout<<"Run "<< counter <<": ";			   //
		for(int k=p; k<=r; k++)					   //
		{										   //
			if(A[k] == x){						   //
				//+ a pivot elé                    //
				cout<<"+"<<A[k]<<", ";			   //
			}else{                                 //
				cout<<A[k]<<", ";                  //
			}                                      //
		}                                          //
		cout<<endl;                                //
		/////////////////////////////////////////////
	}
	return i;
}

void quickSort(vector<int> &A, int p, int r){
	if(p < r){
		int q = partition(A, p, r);
		quickSort(A, p, q-1);
		quickSort(A, q+ 1, r);
	}
}

void QSort()
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
		std::cout << "--------------QuickSort--------------"<<std::endl;
		std::cout << "1: New Array" << std::endl;
        std::cout << "2: Choose pivot type(Default first element of the partion)" << std::endl;
        std::cout << "3: Print Array" << std::endl;
        std::cout << "4: Sort" << std::endl;
        std::cout << "5: Sort with detailed steps" << std::endl;
        std::cout << "6: Exit" << std::endl;
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
			int choice;
			do{
				std::cout << std::endl;
				std::cout <<"--------------------------------------"<<std::endl;
				cout << "0: First Element of the partion"<<endl;
				cout << "1: Middle Element"<<endl;
				cout << "2: Random Pivot"<<endl;
				cout << "3: Back" << endl;
				std::cout <<"--------------------------------------"<<std::endl;
				std::cout << std::endl;
				cin>>choice;
				switch (choice)
				{
				case 0:
					cout<<"Pivot type set to 0, press 3 to go back."<<endl;
					pivot_type = 0;
					break;
				case 1:
					cout<<"Pivot type set to 1, press 3 to go back."<<endl;
					pivot_type = 1;
					break;
				case 2:
					cout<<"Pivot type set to 2, press 3 to go back."<<endl;
					pivot_type = 2;
				 	break;
				}
			}while(choice!=3);
			break;
		case 3:
			cout<<"Original list: ";				   
			for(int i=0; i<n; i++)					   
			{										   
				cout << B[i] << " ";				   
			}										   
			cout << endl;
			break;
		case 4:
			info_type = 0;
			quickSort(A,0,n-1);
			counter=0;
			cout<<"Sorted list: ";				   
			for(int i=0; i<n; i++)					   
			{										   
				cout << A[i] << " ";				   
			}
			for(int i=0; i<n; i++){
				A[i] = B[i];
			}										   
			cout << endl;
			break;
		case 5:
			info_type=1;
			quickSort(A,0,n-1);
			counter=0;
			cout<<"Sorted list: ";				   
			for(int i=0; i<n; i++)					   
			{										   
				cout << A[i] << " ";				   
			}
			for(int i=0; i<n; i++){
				A[i] = B[i];
			}										   
			cout << endl;
			break;
		}
	}while(input!=6);
}