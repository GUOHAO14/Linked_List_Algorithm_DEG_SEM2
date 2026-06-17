//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <filesystem>
//#include <cctype>
//#include <limits>
//#include <chrono>
//
//using namespace std;
//
//struct Student
//{
//    string StudentID;
//    string FullName;
//    string ProgrammeCode;
//    int YearOfStudy;
//    double CGPA;
//    string ContactNumber;
//};
//
//struct Programme
//{
//    string ProgrammeCode;
//    string ProgrammeName;
//    string Faculty;
//    int DurationYears;
//};
//
//Student students[35000];
//Programme programmes[25];
//
//int studentCount = 0;
//int programmeCount = 0;
//
//// Function prototypes
//void loadProgrammes(string filename);
//void loadStudents(string filename);
//
//bool studentIDExists(string studentID);
//int findProgramme(string programmeCode);
//bool isValidContactNumber(string contactNumber);
//void clearInput();
//void addStudent();
//
//void deleteStudent();
//void searchStudent();
//void displayStudent(int index);
//string toUpperCase(string text);
//
//void sortStudents();
//
//// Function definitions
//void loadProgrammes(string filename)
//{
//    ifstream file(filename);
//
//    if (!file.is_open())
//    {
//        cout << "Cannot open " << filename << endl;
//        return;
//    }
//
//    string line;
//
//    // Skip header row
//    getline(file, line);
//
//    while (getline(file, line))
//    {
//        stringstream ss(line);
//        string temp;
//
//        getline(ss, programmes[programmeCount].ProgrammeCode, ',');
//
//        getline(ss, programmes[programmeCount].ProgrammeName, ',');
//
//        getline(ss, programmes[programmeCount].Faculty, ',');
//
//        getline(ss, temp, ',');
//        programmes[programmeCount].DurationYears = stoi(temp);
//
//        programmeCount++;
//    }
//
//    file.close();
//}
//
//void loadStudents(string filename)
//{
//    ifstream file(filename);
//
//    if (!file.is_open())
//    {
//        cout << "Cannot open " << filename << endl;
//        return;
//    }
//
//    string line;
//
//    // Skip header row
//    getline(file, line);
//
//    while (getline(file, line))
//    {
//        stringstream ss(line);
//        string temp;
//
//        getline(ss, students[studentCount].StudentID, ',');
//
//        getline(ss, students[studentCount].FullName, ',');
//
//        getline(ss, students[studentCount].ProgrammeCode, ',');
//
//        getline(ss, temp, ',');
//        students[studentCount].YearOfStudy = stoi(temp);
//
//        getline(ss, temp, ',');
//        students[studentCount].CGPA = stod(temp);
//
//        getline(ss, students[studentCount].ContactNumber);
//
//        studentCount++;
//    }
//
//    file.close();
//}
//
//int findProgramme(string programmeCode)
//{
//    for (int i = 0; i < programmeCount; i++)
//    {
//        if (programmes[i].ProgrammeCode == programmeCode)
//        {
//            return i;
//        }
//    }
//
//    return -1; // Programme not found
//}
//
//void displayStudents()
//{
//    if (studentCount == 0)
//    {
//        cout << "No student records found." << endl;
//        return;
//    }
//
//    // ✅ START TIMER (only display operation)
//    auto start = chrono::high_resolution_clock::now();
//
//    for (int i = 0; i < studentCount; i++)
//    {
//        cout << "\n============================================" << endl;
//        cout << "Student " << i + 1 << endl;
//        cout << "============================================" << endl;
//
//        cout << "Student ID      : " << students[i].StudentID << endl;
//        cout << "Full Name       : " << students[i].FullName << endl;
//        cout << "Programme Code  : " << students[i].ProgrammeCode << endl;
//        cout << "Year of Study   : " << students[i].YearOfStudy << endl;
//        cout << "CGPA            : " << students[i].CGPA << endl;
//        cout << "Contact Number  : " << students[i].ContactNumber << endl;
//
//        // Find matching programme
//        int programmeIndex = findProgramme(students[i].ProgrammeCode);
//
//        if (programmeIndex != -1)
//        {
//            cout << "Programme Name  : "
//                << programmes[programmeIndex].ProgrammeName << endl;
//
//            cout << "Faculty         : "
//                << programmes[programmeIndex].Faculty << endl;
//
//            cout << "Duration        : "
//                << programmes[programmeIndex].DurationYears
//                << " years" << endl;
//        }
//        else
//        {
//            cout << "Programme Name  : Not Found" << endl;
//            cout << "Faculty         : Not Found" << endl;
//            cout << "Duration        : Not Found" << endl;
//        }
//    }
//
//    // ✅ END TIMER
//    auto end = chrono::high_resolution_clock::now();
//
//    auto duration =
//        chrono::duration_cast<chrono::microseconds>(end - start);
//
//    cout << "\nDisplay operation took "
//        << duration.count()
//        << " microseconds." << endl;
//}
//
//void displayStudent(int index)
//{
//    cout << "\n============================================" << endl;
//    cout << "Student Record" << endl;
//    cout << "============================================" << endl;
//
//    cout << "Student ID      : "
//        << students[index].StudentID << endl;
//
//    cout << "Full Name       : "
//        << students[index].FullName << endl;
//
//    cout << "Programme Code  : "
//        << students[index].ProgrammeCode << endl;
//
//    cout << "Year of Study   : "
//        << students[index].YearOfStudy << endl;
//
//    cout << "CGPA            : "
//        << students[index].CGPA << endl;
//
//    cout << "Contact Number  : "
//        << students[index].ContactNumber << endl;
//
//    int programmeIndex =
//        findProgramme(students[index].ProgrammeCode);
//
//    if (programmeIndex != -1)
//    {
//        cout << "Programme Name  : "
//            << programmes[programmeIndex].ProgrammeName
//            << endl;
//
//        cout << "Faculty         : "
//            << programmes[programmeIndex].Faculty
//            << endl;
//
//        cout << "Duration        : "
//            << programmes[programmeIndex].DurationYears
//            << " years" << endl;
//    }
//}
//
//bool studentIDExists(string studentID)
//{
//    for (int i = 0; i < studentCount; i++)
//    {
//        if (students[i].StudentID == studentID)
//        {
//            return true;
//        }
//    }
//
//    return false;
//}
//
//
//bool isValidContactNumber(string contactNumber)
//{
//    // must be 11 or 12 characters
//    if (contactNumber.length() != 11 && contactNumber.length() != 12)
//    {
//        return false;
//    }
//
//    // dash must be at position 4 (index 3)
//    if (contactNumber[3] != '-')
//    {
//        return false;
//    }
//
//    // check all characters
//    for (int i = 0; i < contactNumber.length(); i++)
//    {
//        if (i == 3)
//        {
//            continue; // skip dash
//        }
//
//        if (!isdigit(contactNumber[i]))
//        {
//            return false; // reject letters and symbols
//        }
//    }
//
//    return true;
//}
//
//bool contactNumberExists(string contactNumber)
//{
//    for (int i = 0; i < studentCount; i++)
//    {
//        if (students[i].ContactNumber == contactNumber)
//        {
//            return true;
//        }
//    }
//
//    return false;
//}
//
//void clearInput()
//{
//    cin.clear();
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//}
//
//void addStudent()
//{
//    if (studentCount >= 35000)
//    {
//        cout << "Student array is full." << endl;
//        return;
//    }
//
//    Student newStudent;
//
//    cout << "\n===== Add Student =====" << endl;
//
//    // Student ID
//    while (true)
//    {
//        cout << "Enter Student ID: ";
//        getline(cin, newStudent.StudentID);
//
//
//        if (newStudent.StudentID == "0")
//        {
//            cout << "Add student cancelled." << endl;
//            return;
//        }
//
//        if (newStudent.StudentID.empty())
//        {
//            cout << "Student ID cannot be blank." << endl;
//        }
//        else if (studentIDExists(newStudent.StudentID))
//        {
//            cout << "Duplicate Student ID is not allowed." << endl;
//        }
//        else
//        {
//            break;
//        }
//    }
//
//    // Full Name
//    while (true)
//    {
//        cout << "Enter Full Name: ";
//        getline(cin, newStudent.FullName);
//
//        if (newStudent.FullName == "0")
//        {
//            cout << "Add student cancelled." << endl;
//            return;
//        }
//
//        if (newStudent.FullName.empty())
//        {
//            cout << "Unable to leave name blank." << endl;
//        }
//        else
//        {
//            break;
//        }
//    }
//
//    // Display Programmes
//    cout << "\nAvailable Programmes" << endl;
//
//    for (int i = 0; i < programmeCount; i++)
//    {
//        cout << programmes[i].ProgrammeCode
//            << " - "
//            << programmes[i].ProgrammeName
//            << endl;
//    }
//
//    // Programme Code
//    int programmeIndex;
//
//    while (true)
//    {
//        cout << "\nEnter Programme Code: ";
//        getline(cin, newStudent.ProgrammeCode);
//
//        if (newStudent.ProgrammeCode == "0")
//        {
//            cout << "Add student cancelled." << endl;
//            return;
//        }
//
//        programmeIndex = findProgramme(newStudent.ProgrammeCode);
//
//        if (programmeIndex == -1)
//        {
//            cout << "Programme code does not exist." << endl;
//        }
//        else
//        {
//            break;
//        }
//    }
//
//    // Year of Study
//    while (true)
//    {
//        cout << "Enter Year of Study (0 to cancel): ";
//
//        if (!(cin >> newStudent.YearOfStudy))
//        {
//            cout << "Please select a valid year." << endl;
//
//            clearInput();
//            continue;
//        }
//
//        if (newStudent.YearOfStudy == 0)
//        {
//            clearInput();
//
//            cout << "Add student cancelled." << endl;
//            return;
//        }
//
//        clearInput();
//
//        if (newStudent.YearOfStudy < 1)
//        {
//            cout << "Year of study cannot be below 1." << endl;
//        }
//        else if (newStudent.YearOfStudy >
//            programmes[programmeIndex].DurationYears)
//        {
//            cout << "Year of study cannot exceed "
//                << programmes[programmeIndex].DurationYears
//                << " years." << endl;
//        }
//        else
//        {
//            break;
//        }
//    }
//
//    // CGPA
//    while (true)
//    {
//        cout << "Enter CGPA (-1 to cancel): ";
//
//        if (!(cin >> newStudent.CGPA))
//        {
//            cout << "Please enter a valid CGPA." << endl;
//
//            clearInput();
//            continue;
//        }
//
//        if (newStudent.CGPA == -1)
//        {
//            clearInput();
//
//            cout << "Add student cancelled." << endl;
//            return;
//        }
//
//        clearInput();
//
//        if (newStudent.CGPA < 0.0 ||
//            newStudent.CGPA > 4.0)
//        {
//            cout << "CGPA must be between 0.00 and 4.00." << endl;
//        }
//        else
//        {
//            break;
//        }
//    }
//
//    // Contact Number
//    while (true)
//    {
//        cout << "Enter Contact Number (xxx-xxxxxxx): ";
//
//        getline(cin, newStudent.ContactNumber);
//
//        if (newStudent.ContactNumber == "0")
//        {
//            cout << "Add student cancelled." << endl;
//            return;
//        }
//
//        if (!isValidContactNumber(newStudent.ContactNumber))
//        {
//            cout << "Invalid contact number format." << endl;
//            cout << "Example: 012-3456789" << endl;
//        }
//        else if (contactNumberExists(newStudent.ContactNumber))
//        {
//            cout << "Contact number already exists." << endl;
//        }
//        else
//        {
//            break;
//        }
//    }
//
//    auto start = chrono::high_resolution_clock::now();
//
//    students[studentCount] = newStudent;
//    studentCount++;
//
//    auto end = chrono::high_resolution_clock::now();
//
//    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
//
//    cout << "\nStudent added successfully." << endl;
//    cout << "Insert operation took "
//        << duration.count()
//        << " microseconds." << endl;
//}
//
//string toUpperCase(string text)
//{
//    for (int i = 0; i < text.length(); i++)
//    {
//        text[i] = toupper(text[i]);
//    }
//
//    return text;
//}
//
//void deleteStudent()
//{
//    if (studentCount == 0)
//    {
//        cout << "No student records found." << endl;
//        return;
//    }
//
//    clearInput();
//
//    string searchID;
//
//    cout << "\n===== Delete Student =====" << endl;
//    cout << "Enter Student ID to delete (0 to cancel): ";
//    getline(cin, searchID);
//
//    if (searchID == "0")
//    {
//        cout << "Delete operation cancelled." << endl;
//        return;
//    }
//
//    // Start timing before the search
//    auto searchStart = chrono::high_resolution_clock::now();
//
//    int foundIndex = -1;
//
//    // Case-insensitive linear search
//    for (int i = 0; i < studentCount; i++)
//    {
//        if (toUpperCase(students[i].StudentID) ==
//            toUpperCase(searchID))
//        {
//            foundIndex = i;
//            break;
//        }
//    }
//
//    // End timing for the search
//    auto searchEnd = chrono::high_resolution_clock::now();
//
//    auto searchDuration =
//        chrono::duration_cast<chrono::microseconds>(
//            searchEnd - searchStart);
//
//    if (foundIndex == -1)
//    {
//        cout << "Student ID not found." << endl;
//        cout << "Search operation took "
//            << searchDuration.count()
//            << " microseconds." << endl;
//        return;
//    }
//
//    // Display student details
//    cout << "\nStudent Found" << endl;
//    cout << "Student ID     : "
//        << students[foundIndex].StudentID << endl;
//
//    cout << "Full Name      : "
//        << students[foundIndex].FullName << endl;
//
//    cout << "Programme Code : "
//        << students[foundIndex].ProgrammeCode << endl;
//
//    cout << "Year of Study  : "
//        << students[foundIndex].YearOfStudy << endl;
//
//    cout << "CGPA           : "
//        << students[foundIndex].CGPA << endl;
//
//    cout << "Contact Number : "
//        << students[foundIndex].ContactNumber << endl;
//
//    // Confirmation (NOT timed)
//    char confirm;
//
//    cout << "\nAre you sure you want to delete this student? (Y/N): ";
//    cin >> confirm;
//
//    confirm = toupper(confirm);
//
//    if (confirm != 'Y')
//    {
//        cout << "Delete operation cancelled." << endl;
//        return;
//    }
//
//    // Start timing the deletion process
//    auto deleteStart = chrono::high_resolution_clock::now();
//
//    // Shift elements to fill the gap
//    for (int i = foundIndex; i < studentCount - 1; i++)
//    {
//        students[i] = students[i + 1];
//    }
//
//    studentCount--;
//
//    // End timing the deletion process
//    auto deleteEnd = chrono::high_resolution_clock::now();
//
//    auto deleteDuration =
//        chrono::duration_cast<chrono::microseconds>(
//            deleteEnd - deleteStart);
//
//    auto totalDuration = searchDuration + deleteDuration;
//
//    cout << "\nStudent deleted successfully." << endl;
//
//    cout << "Search operation took "
//        << searchDuration.count()
//        << " microseconds." << endl;
//
//    cout << "Delete operation took "
//        << deleteDuration.count()
//        << " microseconds." << endl;
//
//    cout << "Total algorithm time (search + delete) took "
//        << totalDuration.count()
//        << " microseconds." << endl;
//}
//
//void searchStudent()
//{
//    if (studentCount == 0)
//    {
//        cout << "No student records found." << endl;
//        return;
//    }
//
//    int choice;
//
//    cout << "\n===== Search Student =====" << endl;
//    cout << "1. Search by Student ID" << endl;
//    cout << "2. Search by Full Name" << endl;
//    cout << "0. Cancel" << endl;
//    cout << "Enter your choice: ";
//
//    while (!(cin >> choice))
//    {
//        cout << "Invalid input. Please enter a number: ";
//        clearInput();
//    }
//
//    clearInput();
//
//    string searchTerm;
//    bool found = false;
//
//    switch (choice)
//    {
//    case 0:
//        cout << "Search cancelled." << endl;
//        return;
//
//    case 1:
//    {
//        cout << "Enter Student ID: ";
//        getline(cin, searchTerm);
//
//        // ✅ START TIMER (after input only)
//        auto start = chrono::high_resolution_clock::now();
//
//        for (int i = 0; i < studentCount; i++)
//        {
//            if (toUpperCase(students[i].StudentID) ==
//                toUpperCase(searchTerm))
//            {
//                displayStudent(i);
//                found = true;
//                break;
//            }
//        }
//
//        // ❗ END TIMER (only search process)
//        auto end = chrono::high_resolution_clock::now();
//
//        auto duration =
//            chrono::duration_cast<chrono::microseconds>(end - start);
//
//        if (!found)
//        {
//            cout << "Student ID not found." << endl;
//        }
//
//        cout << "Linear Search (ID) took "
//            << duration.count()
//            << " microseconds." << endl;
//
//        break;
//    }
//
//    case 2:
//    {
//        cout << "Enter Full Name: ";
//        getline(cin, searchTerm);
//
//        // ✅ START TIMER (after input only)
//        auto start = chrono::high_resolution_clock::now();
//
//        for (int i = 0; i < studentCount; i++)
//        {
//            if (toUpperCase(students[i].FullName) ==
//                toUpperCase(searchTerm))
//            {
//                displayStudent(i);
//                found = true;
//            }
//        }
//
//        // ❗ END TIMER
//        auto end = chrono::high_resolution_clock::now();
//
//        auto duration =
//            chrono::duration_cast<chrono::microseconds>(end - start);
//
//        if (!found)
//        {
//            cout << "Student name not found." << endl;
//        }
//
//        cout << "Linear Search (Name) took "
//            << duration.count()
//            << " microseconds." << endl;
//
//        break;
//    }
//
//    default:
//        cout << "Invalid choice." << endl;
//    }
//}
//
//void sortStudents()
//{
//    if (studentCount == 0)
//    {
//        cout << "No student records found." << endl;
//        return;
//    }
//
//    int choice;
//
//    cout << "\n===== Sort Students by CGPA =====" << endl;
//    cout << "1. Ascending Order" << endl;
//    cout << "2. Descending Order" << endl;
//    cout << "0. Cancel" << endl;
//    cout << "Enter your choice: ";
//
//    while (!(cin >> choice))
//    {
//        cout << "Invalid input. Please enter a number: ";
//        clearInput();
//    }
//
//    clearInput();
//
//    switch (choice)
//    {
//    case 0:
//        cout << "Sort cancelled." << endl;
//        return;
//
//    case 1:
//    {
//        // ✅ START TIMER (ONLY sorting)
//        auto start = chrono::high_resolution_clock::now();
//
//        for (int i = 0; i < studentCount - 1; i++)
//        {
//            for (int j = 0; j < studentCount - i - 1; j++)
//            {
//                if (students[j].CGPA > students[j + 1].CGPA)
//                {
//                    swap(students[j], students[j + 1]);
//                }
//            }
//        }
//
//        // ✅ END TIMER
//        auto end = chrono::high_resolution_clock::now();
//
//        auto duration =
//            chrono::duration_cast<chrono::microseconds>(end - start);
//
//        cout << "\nStudents sorted in ASCENDING order by CGPA." << endl;
//        cout << "Sorting took " << duration.count() << " microseconds." << endl;
//
//        // ✅ Prompt AFTER timing output (as requested)
//        char displayChoice;
//        cout << "Display sorted records? (Y/N): ";
//        cin >> displayChoice;
//
//        displayChoice = toupper(displayChoice);
//
//        if (displayChoice == 'Y')
//        {
//            displayStudents();
//        }
//
//        break;
//    }
//
//    case 2:
//    {
//        // ✅ START TIMER (ONLY sorting)
//        auto start = chrono::high_resolution_clock::now();
//
//        for (int i = 0; i < studentCount - 1; i++)
//        {
//            for (int j = 0; j < studentCount - i - 1; j++)
//            {
//                if (students[j].CGPA < students[j + 1].CGPA)
//                {
//                    swap(students[j], students[j + 1]);
//                }
//            }
//        }
//
//        // ✅ END TIMER
//        auto end = chrono::high_resolution_clock::now();
//
//        auto duration =
//            chrono::duration_cast<chrono::microseconds>(end - start);
//
//        cout << "\nStudents sorted in DESCENDING order by CGPA." << endl;
//        cout << "Sorting took " << duration.count() << " microseconds." << endl;
//
//        // ✅ Prompt AFTER timing output
//        char displayChoice;
//        cout << "Display sorted records? (Y/N): ";
//        cin >> displayChoice;
//
//        displayChoice = toupper(displayChoice);
//
//        if (displayChoice == 'Y')
//        {
//            displayStudents();
//        }
//
//        break;
//    }
//
//    default:
//        cout << "Invalid choice." << endl;
//    }
//}
//
//int menu();
//
//int main()
//{
//    int choice;
//    loadProgrammes("programmes.csv");
//    loadStudents("students_30000.csv");
//
//    cout << "Students loaded: "
//        << studentCount << endl;
//
//    cout << "Programmes loaded: "
//        << programmeCount << endl;
//
//    cout << "Current directory: "
//        << filesystem::current_path()
//        << endl;
//
//    do {
//        choice = menu();
//        switch (choice) {
//        case 1:
//            cout << "\n===== Add Student =====" << endl;
//            cout << "Enter 0 at any prompt to cancel." << endl;
//            addStudent();
//            break;
//        case 2:
//            deleteStudent();
//            break;
//        case 3:
//            searchStudent();
//            break;
//        case 4:
//            displayStudents();
//            break;
//        case 5:
//            sortStudents();
//            break;
//
//        case 9:
//            break;
//        default:
//            cout << "Invalid choice. Please try again." << endl;
//        }
//    } while (choice != 9);
//
//
//    return 0;
//}
//
//int menu() {
//    int choice;
//    cout << "Welcome to Student Record Management System" << endl;
//    cout << "1. Add a Student" << endl;
//    cout << "2. Delete a Student" << endl;
//    cout << "3. Find a Student" << endl;
//    cout << "4. List all Students Record" << endl;
//    cout << "5. Sort Students" << endl;
//    cout << "9. Exit" << endl;
//    cout << "Enter your choice: ";
//    cin >> choice;
//    return choice;
//}