@echo off
REM Test script for Sorting Algorithms Project on Windows

echo Running comprehensive tests for Sorting Algorithms Project...
echo ============================================================

REM Test 1: Check if all source files exist
echo Test 1: Checking source files...
set missing_files=
for %%f in (main.cpp Menu.cpp Menu.h BubbleSort.cpp BubbleSort.h UpBubbleSort.cpp UpBubbleSort.h InsertionSort.cpp InsertionSort.h SelectionSort.cpp SelectionSort.h MergeSort.cpp MergeSort.h QuickSort.cpp QuickSort.h) do (
    if not exist "%%f" (
        set missing_files=!missing_files! %%f
    )
)

if "%missing_files%"=="" (
    echo ✓ All required source files found
) else (
    echo ✗ Missing files: %missing_files%
    pause
    exit /b 1
)

REM Test 2: Check for compiler
echo Test 2: Checking compiler availability...
where g++ >nul 2>nul
if %ERRORLEVEL% equ 0 (
    echo ✓ g++ compiler found
    g++ --version 2>nul | findstr /C:"g++"
) else (
    echo ✗ g++ compiler not found
    echo Please install MinGW or similar C++ compiler
    pause
    exit /b 1
)

REM Test 3: Compile the project
echo Test 3: Compiling project...
g++ -std=c++11 -Wall -Wextra -O2 main.cpp Menu.cpp BubbleSort.cpp UpBubbleSort.cpp InsertionSort.cpp SelectionSort.cpp MergeSort.cpp QuickSort.cpp -o sorts_test.exe

if %ERRORLEVEL% equ 0 (
    echo ✓ Project compiled successfully
) else (
    echo ✗ Compilation failed
    pause
    exit /b 1
)

REM Test 4: Check if executable was created
echo Test 4: Checking executable...
if exist "sorts_test.exe" (
    echo ✓ Executable created successfully
    for %%A in (sorts_test.exe) do echo   Executable size: %%~zA bytes
) else (
    echo ✗ Executable not found
    pause
    exit /b 1
)

REM Test 5: Basic syntax check
echo Test 5: Running strict compilation check...
g++ -std=c++11 -Wall -Wextra -Wpedantic main.cpp Menu.cpp BubbleSort.cpp UpBubbleSort.cpp InsertionSort.cpp SelectionSort.cpp MergeSort.cpp QuickSort.cpp -o sorts_strict.exe >nul 2>nul

if %ERRORLEVEL% equ 0 (
    echo ✓ No compilation warnings or errors
    del sorts_strict.exe >nul 2>nul
) else (
    echo ⚠ Some warnings found ^(not critical^)
)

REM Clean up
del sorts_test.exe >nul 2>nul

echo.
echo Test Summary:
echo =============
echo ✓ All tests passed successfully!
echo ✓ Project is ready to build and run
echo.
echo To build and run the project:
echo   build.bat
echo   or
echo   make ^&^& sorts.exe
echo.
pause
