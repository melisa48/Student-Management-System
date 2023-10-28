#include <iostream>
#include <vector>
#include <string>

class Student {
public:
    std::string name;
    int id;
    double grade;

    // Constructor
    Student(std::string n, int i, double g) : name(n), id(i), grade(g) {}
};

class StudentManagementSystem {
private:
    std::vector<Student> students;

public:
    // Add a new student to the system
    void addStudent(std::string name, int id, double grade) {
        students.push_back(Student(name, id, grade));
    }

    // Display all students
    void displayStudents() {
        for (const auto& student : students) {
            std::cout << "Name: " << student.name << ", ID: " << student.id << ", Grade: " << student.grade << std::endl;
        }
    }

    // Find a student by ID
    Student* findStudentById(int id) {
        for (auto& student : students) {
            if (student.id == id) {
                return &student;
            }
        }
        return nullptr;
    }
};

int main() {
    StudentManagementSystem system;

    // Add students
    system.addStudent("John Doe", 1, 85.5);
    system.addStudent("Jane Smith", 2, 90.0);

    // Display students
    system.displayStudents();

    // Find a student by ID
    int idToFind = 2;
    Student* foundStudent = system.findStudentById(idToFind);
    if (foundStudent != nullptr) {
        std::cout << "Found student: " << foundStudent->name << std::endl;
    }
    else {
        std::cout << "Student with ID " << idToFind << " not found." << std::endl;
    }

    return 0;
}
