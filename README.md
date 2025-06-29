# Sorting Algorithms Visualization Tool

A comprehensive C++ console application that demonstrates and visualizes various sorting algorithms with step-by-step execution details and performance metrics.

## 🚀 Features

-   **6 Sorting Algorithms Implementation:**

    -   **Bubble Sort** - Basic bubble sort with O(n²) time complexity
    -   **Optimized Bubble Sort** - Enhanced version with early termination
    -   **Insertion Sort** - Efficient for small datasets with O(n²) worst case
    -   **Selection Sort** - Simple selection-based sorting algorithm
    -   **Merge Sort** - Divide-and-conquer approach with O(n log n) complexity
    -   **Quick Sort** - Fast recursive algorithm with different pivot strategies

-   **Interactive Features:**
    -   User-friendly menu system for algorithm selection
    -   Custom array input with user-defined size and elements
    -   Step-by-step visualization of sorting process
    -   Performance metrics (comparison count, swap count)
    -   Multiple pivot strategies for Quick Sort

## 📁 Project Structure

```
Sorts/
├── main.cpp              # Main entry point
├── Menu.h                # Menu class header
├── Menu.cpp              # Menu implementation
├── BubbleSort.h/cpp      # Bubble sort implementation
├── UpBubbleSort.h/cpp    # Optimized bubble sort
├── InsertionSort.h/cpp   # Insertion sort implementation
├── SelectionSort.h/cpp   # Selection sort implementation
├── MergeSort.h/cpp       # Merge sort implementation
├── QuickSort.h/cpp       # Quick sort with pivot strategies
├── .gitignore            # Git ignore file
├── README.md             # This file
└── Makefile              # Build configuration
```

## 🛠️ Building and Running

### Prerequisites

-   C++ compiler (g++, clang++, or MSVC)
-   C++11 or later standard support

### Compilation

#### Using Make (Recommended):

```bash
make
```

#### Manual Compilation:

```bash
g++ -std=c++11 -o sorts main.cpp Menu.cpp BubbleSort.cpp UpBubbleSort.cpp InsertionSort.cpp SelectionSort.cpp MergeSort.cpp QuickSort.cpp
```

#### On Windows with Visual Studio:

```cmd
cl /EHsc main.cpp Menu.cpp BubbleSort.cpp UpBubbleSort.cpp InsertionSort.cpp SelectionSort.cpp MergeSort.cpp QuickSort.cpp
```

### Running the Application

```bash
./sorts          # Linux/Mac
sorts.exe        # Windows
```

## 🎮 Usage

1. **Launch the application** to see the main menu
2. **Select a sorting algorithm** (1-6) from the menu
3. **Choose an option** from the algorithm-specific submenu:
    - **New Array**: Create a new array with custom size and elements
    - **Print Array**: Display the current array
    - **Sort**: Execute the algorithm and show only the result
    - **Sort with detailed steps**: Execute with step-by-step visualization
    - **Exit**: Return to main menu
4. **View results** including sorted array and performance metrics

### Example Session:

```
-------------------Menu-------------------
1: BubbleSort
2: UpBubbleSort
3: InsertionSort
4: MergeSort
5: QuickSort
6: SelectionSort
7: Exit
------------------------------------------

> 1

--------------BubbleSort--------------
1: New Array
2: Print Array
3: Sort
4: Sort with detailed steps
5: Exit
--------------------------------------

> 1
Array size(Number of elements): 5
Number 1: 64
Number 2: 34
Number 3: 25
Number 4: 12
Number 5: 22

> 4
Swap(34, 64)
34 64 25 12 22

Swap(25, 64)
34 25 64 12 22
...
```

## 🔧 Algorithm Details

### Bubble Sort

-   **Time Complexity**: O(n²)
-   **Space Complexity**: O(1)
-   **Features**: Shows each swap operation in detailed mode

### Optimized Bubble Sort (UpBubbleSort)

-   **Time Complexity**: O(n²) worst case, O(n) best case
-   **Space Complexity**: O(1)
-   **Optimization**: Early termination when array is sorted

### Insertion Sort

-   **Time Complexity**: O(n²) worst case, O(n) best case
-   **Space Complexity**: O(1)
-   **Features**: Shows element positioning in detailed mode

### Selection Sort

-   **Time Complexity**: O(n²)
-   **Space Complexity**: O(1)
-   **Features**: Supports both min and max selection strategies

### Merge Sort

-   **Time Complexity**: O(n log n)
-   **Space Complexity**: O(n)
-   **Features**: Stable sorting algorithm with guaranteed performance

### Quick Sort

-   **Time Complexity**: O(n log n) average, O(n²) worst case
-   **Space Complexity**: O(log n)
-   **Pivot Strategies**:
    -   First element
    -   Middle element
    -   Random element

## 📊 Performance Metrics

The application tracks and displays:

-   **Comparison Count**: Number of element comparisons performed
-   **Swap Count**: Number of element swaps/moves performed
-   **Detailed Steps**: Visual representation of algorithm execution

## 🐛 Known Issues & Fixes

This project has been reviewed and the following issues have been addressed:

-   ✅ Fixed static variable reset issues
-   ✅ Improved code formatting and consistency
-   ✅ Added proper build system
-   ✅ Enhanced error handling
-   ✅ Standardized variable naming conventions

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## 📝 License

This project is available for educational purposes. Feel free to use and modify for learning about sorting algorithms.

## 🎓 Educational Value

This project is excellent for:

-   Understanding sorting algorithm implementations
-   Visualizing algorithm behavior step-by-step
-   Comparing performance characteristics
-   Learning C++ programming concepts
-   Studying time and space complexity analysis

## 📧 Contact

For questions or suggestions about this sorting algorithms visualization tool, please open an issue in the repository.

---

_Happy Sorting! 🔢✨_
