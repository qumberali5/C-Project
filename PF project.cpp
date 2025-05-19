#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Grade(float);

struct Student {
    string name;
    int roll;
    float attendance;
    float PF = 0, Calculus = 0, Eng = 0, Discrete = 0, ICT = 0;
};

float calculateSum(const Student& s) {
    return s.PF + s.Calculus + s.Eng + s.Discrete + s.ICT;
}

int main() {
    vector<Student> students;
    int Total = 500;

    int choice;
    while (true) {
        cout << "\nAre you a:\n1. Teacher\n2. Student\n3. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 3) break;

        if (choice == 1) {
            if (students.empty()) {
                int n;
                cout << "Enter number of students to register: ";
                cin >> n;

                for (int i = 0; i < n; i++) {
                    Student s;
                    cout << "Enter name of student " << (i + 1) << ": ";
                    cin >> s.name;
                    cout << "Enter roll number: ";
                    cin >> s.roll;
                    cout << "Enter attendance percentage: ";
                    cin >> s.attendance;
                    if (s.attendance < 0 || s.attendance > 100) {
                        cout << "Invalid attendance, try again.\n";
                        i--;
                        continue;
                    }
                    students.push_back(s);
                }
            }

            cout << "\nSubjects:\n1. PF\n2. Calculus\n3. English\n4. Discrete\n5. ICT\n";
            int subjectChoice;
            cout << "Enter subject number to enter marks for: ";
            cin >> subjectChoice;
            if (subjectChoice < 1 || subjectChoice > 5) {
                cout << "Invalid subject choice.\n";
                continue;
            }

            for (auto& s : students) {
                if (s.attendance >= 75) {
                    cout << "Enter marks for " << s.name << " (Roll " << s.roll << "): ";
                    float mark;
                    cin >> mark;
                    if (mark < 0 || mark > 100) {
                        cout << "Invalid marks, please enter 0-100 only.\n";
                        continue;
                    }
                    switch (subjectChoice) {
                        case 1: s.PF = mark; break;
                        case 2: s.Calculus = mark; break;
                        case 3: s.Eng = mark; break;
                        case 4: s.Discrete = mark; break;
                        case 5: s.ICT = mark; break;
                    }
                } else {
                    cout << s.name << " not eligible (low attendance).\n";
                }
            }
            cout << "Marks updated for chosen subject.\n";
        }
        else if (choice == 2) {
            if (students.empty()) {
                cout << "No students registered yet.\n";
                continue;
            }
            cout << "\nSearch by:\n1. Name\n2. Roll Number\nEnter choice: ";
            int searchChoice;
            cin >> searchChoice;

            int foundIndex = -1;
            if (searchChoice == 1) {
                string searchName;
                cout << "Enter name: ";
                cin >> searchName;
                for (int i = 0; i < (int)students.size(); i++) {
                    if (students[i].name == searchName) {
                        foundIndex = i;
                        break;
                    }
                }
            }
            else if (searchChoice == 2) {
                int searchRoll;
                cout << "Enter roll number: ";
                cin >> searchRoll;
                for (int i = 0; i < (int)students.size(); i++) {
                    if (students[i].roll == searchRoll) {
                        foundIndex = i;
                        break;
                    }
                }
            }
            else {
                cout << "Invalid choice.\n";
                continue;
            }

            if (foundIndex == -1) {
                cout << "Student not found.\n";
                continue;
            }

            Student& s = students[foundIndex];
            cout << "\nName: " << s.name << "\nRoll Number: " << s.roll << "\nAttendance: " << s.attendance << "%\n";

            if (s.attendance < 75) {
                cout << "Not eligible to give exam due to low attendance.\n";
                continue;
            }

            float sum = calculateSum(s);
            float percentage = (sum / Total) * 100;

            cout << "PF Marks: " << s.PF << "\nCalculus Marks: " << s.Calculus << "\nEnglish Marks: " << s.Eng
                 << "\nDiscrete Marks: " << s.Discrete << "\nICT Marks: " << s.ICT << "\nTotal Marks: " << sum
                 << " out of " << Total << "\nPercentage: " << percentage << "%\n";

            Grade(percentage);
        }
        else {
            cout << "Invalid choice, try again.\n";
        }
    }

    cout << "Program exited.\n";
    return 0;
}

void Grade(float p) {
    if (p >= 95.0 && p <= 100.0)
        cout << "Grade is: A+\n";
    else if (p >= 85.0 && p < 95.0)
        cout << "Grade is: A\n";
    else if (p >= 75.0 && p < 85.0)
        cout << "Grade is: B+\n";
    else if (p >= 65.0 && p < 75.0)
        cout << "Grade is: B\n";
    else if (p >= 60.0 && p < 65.0)
        cout << "Grade is: C\n";
    else if (p >= 55.0 && p < 60.0)
        cout << "Grade is: D\n";
    else
        cout << "You are Failed || You have skipped the exam.\n";
}
