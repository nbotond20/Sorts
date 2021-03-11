#include <iostream>
#include <time.h>
#include <vector>
#include "SelectionSort.h"

using namespace std;

static int type=0;
static int min_max = 0;
static int compare_count=0;
static int swap_count=0;

void selectionSort(vector<int> &A, int n){
    switch(min_max)
    {
    case 0://Min
        swap_count=0;
        compare_count=0;
        int i, j, min_idx;  
        for (i = 0; i < n-1; i++){  
            min_idx = i;  
            for (j = i+1; j < n; j++){
                compare_count++;
                if (A[j] < A[min_idx]){
                    min_idx = j; 
                }
            }
            swap_count++;
            swap(A[min_idx], A[i]);
            //////////////////////////////////////////////////////
            if(type == 1){
                cout<<"Swap("<<A[min_idx]<<", "<<A[i]<<")"<<endl;
                for(int k=0; k<n; k++){        
                    cout<<A[k]<<" ";           
                }                              
                cout<<endl<<endl;
            }
            //////////////////////////////////////////////////////  
        }  
        break;
    case 1://Max
        swap_count=0;
        compare_count=0;
        for(int i=n-1; i>=0; i--){
            int max_ind = 0;
            for(int j=0; j<=i; j++){
                compare_count++;
                if(A[j]>A[max_ind]){
                    max_ind = j;
                }
            }
            swap_count++;
            swap(A[max_ind], A[i]);
            //////////////////////////////////////////////////////
            if(type == 1){
                cout<<"Swap("<<A[max_ind]<<", "<<A[i]<<")"<<endl;
                for(int k=0; k<n; k++){        
                    cout<<A[k]<<" ";           
                }                              
                cout<<endl<<endl;
            }
            //////////////////////////////////////////////////////
        }
        break;
    }
}

void SSort()
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
		std::cout << "------------SelectionSort------------"<<std::endl;
		std::cout << "1: New Array" << std::endl;
        std::cout << "2: Print Array" << std::endl;
        std::cout << "3: Choose Type(Min or Max, Default: Min)" << std::endl;
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
			cout<<"Original list: ";				   
			for(int i=0; i<n; i++)					   
			{										   
				cout << B[i] << " ";				   
			}										   
			cout << endl;
			break;
        case 3:
            int choice;
			do{
				std::cout << std::endl;
				std::cout <<"--------------Choose Type--------------"<<std::endl;
				cout << "0: Min search"<<endl;
				cout << "1: Max search"<<endl;
				cout << "2: Back" << endl;
				std::cout <<"--------------------------------------"<<std::endl;
				std::cout << std::endl;
				cin>>choice;
				switch (choice)
				{
				case 0:
					cout<<"Search type set to Min, press 2 to go back."<<endl;
					min_max = 0;
					break;
				case 1:
					cout<<"Search type set to Max, press 2 to go back."<<endl;
					min_max = 1;
					break;
				}
			}while(choice!=2);
            break;
		case 4:
			type = 0;
            compare_count=0;
            selectionSort(A, n);
            cout<<"Sorted list: ";				   
			for(int i=0; i<n; i++)					   
			{										   
				cout << A[i] << " ";				   
			}
			for(int i=0; i<n; i++){
				A[i] = B[i];
			}									   
			cout << endl;
            //cout<<"Swap count: "<<swap_count<<endl;
            //cout<<"Compare count: "<<compare_count<<endl;
			break;
		case 5:
            type = 1;
            compare_count=0;
            selectionSort(A, n);
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
	}while(input!=6);
}