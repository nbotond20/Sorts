#include <iostream>
#include "Menu.h"
#include "BubbleSort.h"
#include "UpBubbleSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "SelectionSort.h"

void Menu::run(){
    static int input;
    do{
        std::cout << std::endl;
		std::cout << "-------------------Menu-------------------"<<std::endl;
		std::cout << "1: BubbleSort" << std::endl;
        std::cout << "2: UpBubbleSort" << std::endl;
        std::cout << "3: InsertionSort" << std::endl;
        std::cout << "4: MergeSort" << std::endl;
        std::cout << "5: QuickSort" << std::endl;
        std::cout << "6: SelectionSort" << std::endl;
        std::cout << "7: Exit" << std::endl;
		std::cout <<"------------------------------------------"<<std::endl;
		std::cout << std::endl;

        std::cin >> input;
        switch(input){
            case 1:
                BSort();
                break;
            case 2:
                UpBSort();
                break;
            case 3:
                InSort();
                break;
            case 4:
                MSort();
                break;
            case 5:
                QSort();
                break;
            case 6:
                SSort();
                break;
        }
    }while(input!=7);
}