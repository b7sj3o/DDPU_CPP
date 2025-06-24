#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Enum for specialties
enum Specialty { 
    CS, // Computer Science
    IT, // Information Technology
    ME, // Mechanical Engineering
    PI, // Programming and Information Systems
    TE  // Telecommunications Engineering
 };

// Struct for student
struct Student {
    string lastName;
    int course;
    Specialty specialty;
    int physicsGrade;
    int mathGrade;
    int informaticsGrade;
};

// Convert int to Specialty
Specialty inputSpecialty() {
    int s;
    cout << "Enter specialty (0 - CS, 1 - IT, 2 - ME, 3 - PI, 4 - TE): ";
    cin >> s;
    return static_cast<Specialty>(s);
}

// Input student data
void inputStudents(Student* students, int count) {
    for (int i = 0; i < count; i++) {
        cout << "\nStudent #" << i + 1 << ":\n";
        cout << "Last name: ";
        cin >> students[i].lastName;
        cout << "Course: ";
        cin >> students[i].course;
        students[i].specialty = inputSpecialty();
        cout << "Grade in Physics: ";
        cin >> students[i].physicsGrade;
        cout << "Grade in Math: ";
        cin >> students[i].mathGrade;
        cout << "Grade in Informatics: ";
        cin >> students[i].informaticsGrade;
    }
}

// Get string name of specialty
string getSpecialtyName(Specialty s) {
    switch (s) {
        case CS: return "CS";
        case IT: return "IT";
        case ME: return "ME";
        case PI: return "PI";
        case TE: return "TE";
        default: return "Undefined";
    }
}

// Print student table
void printTable(const Student* students, int count) {
    cout << "\n==========================================================================\n";
    cout << "| # | Last Name     | Course | Spec | Physics | Math       | Informatics |\n";
    cout << "==========================================================================\n";

    for (int i = 0; i < count; i++) {
        cout << "| " << setw(2) << i + 1 << " "
             << "| " << setw(13) << left << students[i].lastName
             << "| " << setw(7) << students[i].course
             << "| " << setw(5) << getSpecialtyName(students[i].specialty)
             << "| " << setw(8) << students[i].physicsGrade
             << "| " << setw(11) << students[i].mathGrade
             << "| " << setw(12) << students[i].informaticsGrade << "|\n";
    }

    cout << "==========================================================================\n";
}

int main() {
    int studentCount;
    cout << "Enter number of students: ";
    cin >> studentCount;

    Student* students = new Student[studentCount];

    inputStudents(students, studentCount);
    printTable(students, studentCount);

    delete[] students;

    return 0;
}
