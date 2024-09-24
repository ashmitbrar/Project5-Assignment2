#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

//defining a simple struct
struct STUDENT_DATA {
    std::string FirstName;
    std::string LastName;
    std::string Email;
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

    
#ifdef PRE_RELEASE
    std::cout << "Running Pre-Release Version" << std::endl; //message to show when running on perelease 

    // Open the student email data file in pre-release mode
    std::ifstream emailFile("C:/Users/ashmi/OneDrive/Desktop/CSCN73030-Assignment2/CSCN73030-Assignment2/StudentData_Emails.txt");

    // Check if the email file opened successfully
    if (!emailFile) {
        std::cerr << "Error opening student email data file" << std::endl;
        return 1;
    }

    // Reading and parsing the email file
    while (std::getline(emailFile, line)) {
        std::stringstream ss(line);
        std::string FirstName, LastName, Email;

        // Parse the email file for first name, last name, and email
        if (std::getline(ss, FirstName, ',') && std::getline(ss, LastName, ',') && std::getline(ss, Email)) {
           
            
            // Findiong students in student vector
            for (auto& student : students) {
                if (student.FirstName == FirstName && student.LastName == LastName) {
                    student.Email = Email; // Assign email if names match
                    break;
                }
            }
        }
    }

    // Close the email data file
    emailFile.close();

#else
    std::cout << "Running Standard Version" << std::endl;
#endif

    //Debug functionality : Prints student data
#ifdef _DEBUG
    std::cout << "Student List:" << std::endl;
    for (const auto& student : students) {
        std::cout << "First Name: " << student.FirstName << ", Last Name: " << student.LastName << std::endl;
   
#ifdef PRE_RELEASE
        std::cout << ", Email: " << student.Email;  // Only show email in pre-release
#endif
        std::cout << std::endl;
    
    }
#endif

    return 0; 
}
