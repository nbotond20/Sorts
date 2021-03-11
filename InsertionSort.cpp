#include <iostream>
#include <time.h>
#include <vector>
#include "InsertionSort.h"

using namespace std;

static int type=0;
static int compare_count=0;

void insertionSort(vector<int> &A, int n){
    int x;
    int j;
    int i;
    for(i=1; i<n; i++){
        if(A[i-1] > A[i]){
			compare_count++;
            ///////////////////////////////////////////////////////
			if(type == 1){                                       //
                cout<<"Searching the postion of "<<A[i]<<": ";   //
                for(int k=0; k<n; k++){                          //
                cout<<A[k]<<" ";                                 //
                }                                                //
                cout<<endl;                                      //
            }                                                    //
			///////////////////////////////////////////////////////
            x = A[i];
            A[i] = A[i-1];
            j = i-1;
            while(j >= 0 && A[j] > x){
                A[j+1] = A[j];
                j = j-1;
                /////////////////////////////////////////
				if(type == 1){						   //
                    cout<<"    Moving "<<x<<"--->  ";  //
                    for(int k=0; k<n; k++){            //
                        cout<<A[k]<<" ";               //
                    }                                  //
                    cout<<endl;                        //
                }                                      //
				//////////////////////////////////////////
            }
            /////////////////////////////
			if(type == 1) cout<<endl;  //
			/////////////////////////////
            A[j+1] = x;
        }
    }
    /////////////////////////////
	if(type == 1) cout<<endl;  //
	/////////////////////////////
}

void InSort()
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
		std::cout << "------------InsertionSort------------"<<std::endl;
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
            insertionSort(A, n);
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
            insertionSort(A, n);
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