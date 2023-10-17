#include <iostream>
#include <vector>

using namespace std;

struct Subject {
    string name;
    int credits;
    double grade;
};

double calculateCGPA(const vector<Subject>& subjects) {
    double totalCredits = 0.0;
    double totalGradePoints = 0.0;

    for (const Subject& subject : subjects) {
        totalCredits += subject.credits;
        totalGradePoints += subject.credits * subject.grade;
    }

    if (totalCredits > 0) {
        return totalGradePoints / totalCredits;
    } else {
        return 0.0;
    }
}

int main() {
    int numSubjects;
    cout << "Enter the number of subjects: ";
    cin >> numSubjects;

    vector<Subject> subjects;

    for (int i = 0; i < numSubjects; ++i) {
        Subject subject;
        cout << "Enter the name of subject " << i + 1 << ": ";
        cin >> subject.name;
        cout << "Enter the credits for " << subject.name << ": ";
        cin >> subject.credits;
        cout << "Enter the grade for " << subject.name << " (0-10): ";
        cin >> subject.grade;

        if (subject.grade < 0 || subject.grade > 10) {
            cout << "Invalid grade. Please enter a grade between 0 and 10." << endl;
            return 1;
        }

        subjects.push_back(subject);
    }

    double cgpa = calculateCGPA(subjects);
    cout << "Your CGPA is: " << cgpa << endl;

    if (cgpa > 5.0) {
        cout << "Congratulations! Your CGPA is greater than 5.0." << endl;
    } else {
        cout << "Keep up the good work!" << endl;
    }

    return 0;
}
