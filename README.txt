# Student Record Management System - Setup Guide

## Project Overview & Structure

This is a **Linked List-based Student Record Management System** written in C++. Ensure project folder is organised as follows before compiling:

```
project/
|-- DS Assignment Project.slnx
|-- DS Assignment Project
|	|-- Student.h
|	|-- Programme.h
|	|-- menu.h
|	|-- utils.h
|	|-- TP076267_KhooGuoHao_CT077_LW1.cpp
|	|-- Datasets/
|		|--students_500.csv
|		|-- students_2000.csv
|		|-- students_8000.csv
|		|-- students_30000.csv
|		|-- programmes.csv
|-- TP076267_PerfRecord.txt
|-- README.txt

```

**Important:** The `Datasets` folder must be in the same directory as your compiled executable, otherwise the program will fail to load any data.


## Prerequisites

- IDE: Microsoft Visual Studio (2019 or later recommended)
- Compiler: MSVC (included with Visual Studio)
- C++ Language Standard: ISO C++20 Standard (/std:c++20) or latest versions


## How to Compile and Run

### Using Visual Studio

1. Extract the submitted zip file to a folder of your choice.
2. Open Visual Studio and select "Open a project or solution".
3. Navigate to the extracted folder and open DS Assignment Project.slnx.
4. Once the project loads, ensure the Solution Explorer panel on the right shows all the source and header files (as shown in project structure).
5. Press Ctrl + F5 (Start Without Debugging) to compile and run.


## Changing Dataset Size

Currently, the dataset loaded at startup is hardcoded in `main.cpp`. Dataset size is not switchable at runtime.
To switch between dataset sizes, follow these steps:

1. Open `main.cpp`
2. Locate this line near the top of `main()`:

```
string fileName = "Datasets\\students_500.csv";
```

3. Replace `students_500.csv` with your desired dataset file:

| Dataset Size 	  | File Name 		 |
|-----------------|----------------------|
| 500 students    | `students_500.csv`   |
| 2,000 students  | `students_2000.csv`  |
| 8,000 students  | `students_8000.csv`  |
| 30,000 students | `students_30000.csv` |

Example — to load 30,000 students, change the filename (DO NOT CHANGE the structure of the relative path, only the filename):
```
string fileName = "Datasets\\students_30000.csv";
```

4. Run the program after making this change (rebuild the solution if needed).


## Menu Navigation Guide

The program is made up of the main menu and submenus. Main menu will lead to main operations of the programs, and submenus are to allow selection of specific operation type to be executed.
Each menu item is indexed with integers from 1. Input purely the integer `1`, `2`, `3`, or so on to access operations/navigate the program. 
At any prompt, entering `0` or `-1` (where applicable) will cancel the operation and return to the previous menu.

