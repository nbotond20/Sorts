@echo off
REM Build script for Sorting Algorithms Project on Windows

echo Building Sorting Algorithms Project...

REM Check if compiler is available
where g++ >nul 2>nul
if %ERRORLEVEL% neq 0 (
    echo Error: g++ compiler not found. Please install MinGW or similar C++ compiler.
    echo You can also use Visual Studio's cl.exe compiler.
    pause
    exit /b 1
)

REM Compile the project
g++ -std=c++11 -Wall -Wextra -O2 main.cpp Menu.cpp BubbleSort.cpp UpBubbleSort.cpp InsertionSort.cpp SelectionSort.cpp MergeSort.cpp QuickSort.cpp -o sorts.exe

if %ERRORLEVEL% equ 0 (
    echo Build successful! 
    echo Run the program with: sorts.exe
    echo.
    echo Do you want to run the program now? [Y/N]
    set /p choice=
    if /i "%choice%"=="Y" (
        sorts.exe
    )
) else (
    echo Build failed! Please check for errors above.
    pause
)
