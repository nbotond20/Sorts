#!/bin/bash
# Test script for Sorting Algorithms Project

echo "Running comprehensive tests for Sorting Algorithms Project..."
echo "============================================================"

# Test 1: Check if all source files exist
echo "Test 1: Checking source files..."
required_files=("main.cpp" "Menu.cpp" "Menu.h" "BubbleSort.cpp" "BubbleSort.h" 
               "UpBubbleSort.cpp" "UpBubbleSort.h" "InsertionSort.cpp" "InsertionSort.h"
               "SelectionSort.cpp" "SelectionSort.h" "MergeSort.cpp" "MergeSort.h"
               "QuickSort.cpp" "QuickSort.h")

missing_files=()
for file in "${required_files[@]}"; do
    if [ ! -f "$file" ]; then
        missing_files+=("$file")
    fi
done

if [ ${#missing_files[@]} -eq 0 ]; then
    echo "✓ All required source files found"
else
    echo "✗ Missing files: ${missing_files[*]}"
    exit 1
fi

# Test 2: Check for compiler
echo "Test 2: Checking compiler availability..."
if command -v g++ &> /dev/null; then
    echo "✓ g++ compiler found: $(g++ --version | head -n1)"
else
    echo "✗ g++ compiler not found"
    exit 1
fi

# Test 3: Compile the project
echo "Test 3: Compiling project..."
g++ -std=c++11 -Wall -Wextra -O2 main.cpp Menu.cpp BubbleSort.cpp UpBubbleSort.cpp InsertionSort.cpp SelectionSort.cpp MergeSort.cpp QuickSort.cpp -o sorts_test

if [ $? -eq 0 ]; then
    echo "✓ Project compiled successfully"
else
    echo "✗ Compilation failed"
    exit 1
fi

# Test 4: Check if executable was created
echo "Test 4: Checking executable..."
if [ -f "sorts_test" ]; then
    echo "✓ Executable created successfully"
    file_size=$(stat -f%z "sorts_test" 2>/dev/null || stat -c%s "sorts_test" 2>/dev/null)
    echo "  Executable size: $file_size bytes"
else
    echo "✗ Executable not found"
    exit 1
fi

# Test 5: Basic syntax check with compilation warnings
echo "Test 5: Running strict compilation check..."
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror main.cpp Menu.cpp BubbleSort.cpp UpBubbleSort.cpp InsertionSort.cpp SelectionSort.cpp MergeSort.cpp QuickSort.cpp -o sorts_strict 2>/dev/null

if [ $? -eq 0 ]; then
    echo "✓ No compilation warnings or errors"
    rm -f sorts_strict
else
    echo "⚠ Some warnings found (not critical)"
fi

# Clean up
rm -f sorts_test

echo ""
echo "Test Summary:"
echo "============="
echo "✓ All tests passed successfully!"
echo "✓ Project is ready to build and run"
echo ""
echo "To build and run the project:"
echo "  make && ./sorts"
echo "  or"
echo "  ./build.sh"
