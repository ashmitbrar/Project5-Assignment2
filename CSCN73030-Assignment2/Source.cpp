#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

//defining a simple struct
struct STUDENT_DATA {
    std::string FirstName;
    std::string LastName;
};

int main() {
    // Vector to store student data
    std::vector<STUDENT_DATA> students;

    // Open file
    std::ifstream file("C:/Users/ashmi/OneDrive/Desktop/CSCN73030-Assignment2/CSCN73030-Assignment2/StudentData.txt");
    std::string line;

    // if opened not success
    if (!file) {
        std::cerr << "error opening student data" << std::endl;
        return 1;
    }

    // Reading and parsing the file
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string FirstName, LastName;

        // take first name and last name from txt
        if (std::getline(ss, FirstName, ',') && std::getline(ss, LastName)) {
            STUDENT_DATA student{ FirstName, LastName };
            students.push_back(student);
        }
    }

    // Close the file
    file.close();

    //Debug functionality : Prints student data
#ifdef _DEBUG
    std::cout << "Student List:" << std::endl;
    for (const auto& student : students) {
        std::cout << "First Name: " << student.FirstName << ", Last Name: " << student.LastName << std::endl;
    }
#endif

    return 0; // Return success
}
