#!/bin/bash
# Build script for Sorting Algorithms Project

echo "Building Sorting Algorithms Project..."

# Check if compiler is available
if ! command -v g++ &> /dev/null; then
    echo "Error: g++ compiler not found. Please install a C++ compiler."
    exit 1
fi

# Compile the project
g++ -std=c++11 -Wall -Wextra -O2 main.cpp Menu.cpp BubbleSort.cpp UpBubbleSort.cpp InsertionSort.cpp SelectionSort.cpp MergeSort.cpp QuickSort.cpp -o sorts

if [ $? -eq 0 ]; then
    echo "Build successful!"
    echo "Run the program with: ./sorts"
    echo
    echo "Do you want to run the program now? [y/N]"
    read -r choice
    if [[ "$choice" =~ ^[Yy]$ ]]; then
        ./sorts
    fi
else
    echo "Build failed! Please check for errors above."
    exit 1
fi
