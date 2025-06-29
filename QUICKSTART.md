# QUICK START GUIDE

## 🚀 Building the Project

### Option 1: Using Make (Linux/Mac/Windows with Make)

```bash
make
./sorts        # Linux/Mac
sorts.exe      # Windows
```

### Option 2: Using Build Scripts

```bash
# Linux/Mac
chmod +x build.sh
./build.sh

# Windows
build.bat
```

### Option 3: Manual Compilation

```bash
# Linux/Mac/Windows with g++
g++ -std=c++11 -Wall -Wextra -O2 *.cpp -o sorts

# Windows with Visual Studio
cl /EHsc *.cpp
```

## 🧪 Testing the Build

```bash
# Linux/Mac
chmod +x test.sh
./test.sh

# Windows
test.bat

# Using Make
make test
```

## 📋 Project Files Overview

### Core Files

-   `main.cpp` - Entry point
-   `Menu.cpp/h` - Main menu system

### Sorting Algorithms

-   `BubbleSort.cpp/h` - Basic bubble sort
-   `UpBubbleSort.cpp/h` - Optimized bubble sort
-   `InsertionSort.cpp/h` - Insertion sort
-   `SelectionSort.cpp/h` - Selection sort
-   `MergeSort.cpp/h` - Merge sort
-   `QuickSort.cpp/h` - Quick sort with pivot options

### Build & Development

-   `Makefile` - Build configuration
-   `build.sh/bat` - Build scripts
-   `test.sh/bat` - Test scripts
-   `README.md` - Complete documentation
-   `.gitignore` - Git ignore rules

## 🐛 Recent Fixes Applied

✅ **Fixed static variable reset issues**

-   All counters now properly reset between algorithm runs
-   No more accumulated counts from previous executions

✅ **Added missing headers**

-   Added `#include <algorithm>` for std::swap function
-   Ensures compatibility across different compilers

✅ **Improved random number generation**

-   Fixed srand() being called multiple times
-   Corrected random pivot range calculation in QuickSort

✅ **Enhanced build system**

-   Added comprehensive Makefile with multiple targets
-   Created cross-platform build and test scripts
-   Added proper error handling and validation

✅ **Code quality improvements**

-   Consistent variable naming and formatting
-   Better error handling throughout the codebase
-   Proper memory management practices

## 🎯 Algorithm Quick Reference

| Algorithm        | Time Complexity | Space    | Features              |
| ---------------- | --------------- | -------- | --------------------- |
| Bubble Sort      | O(n²)           | O(1)     | Step-by-step swaps    |
| Optimized Bubble | O(n²)/O(n)      | O(1)     | Early termination     |
| Insertion Sort   | O(n²)/O(n)      | O(1)     | Good for small arrays |
| Selection Sort   | O(n²)           | O(1)     | Min/Max selection     |
| Merge Sort       | O(n log n)      | O(n)     | Stable, guaranteed    |
| Quick Sort       | O(n log n)      | O(log n) | 3 pivot strategies    |

## 💡 Usage Tips

1. **Start with small arrays** (5-10 elements) to see step-by-step execution
2. **Use detailed steps mode** to understand algorithm behavior
3. **Compare performance metrics** between different algorithms
4. **Try different pivot strategies** in QuickSort for comparison
5. **Test with sorted/reverse-sorted arrays** to see best/worst cases

## 📞 Need Help?

-   Check the main `README.md` for complete documentation
-   Run test scripts to verify your build environment
-   All algorithms include both normal and detailed execution modes
-   Performance metrics help understand algorithm efficiency
