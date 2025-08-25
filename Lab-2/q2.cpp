#include <iostream>
using namespace std;

int main() {
    int students = 5, subjects = 4;

    // Dynamic allocation of 2D array
    int** scores = new int*[students];
    for (int s = 0; s < students; s++) {
        scores[s] = new int[subjects];
    }

    // Taking input
    cout << "Enter marks:\n";
    for (int s = 0; s < students; s++) {
        cout << "Student " << s + 1 << ":\n";
        for (int sub = 0; sub < subjects; sub++) {
            cout << "  Subject " << sub + 1 << ": ";
            cin >> scores[s][sub];
        }
    }

    // Student totals
    int* sums = new int[students];
    cout << "\nTotal marks of students:\n";
    for (int s = 0; s < students; s++) {
        int total = 0;
        for (int sub = 0; sub < subjects; sub++) {
            total += scores[s][sub];
        }
        sums[s] = total;
        cout << "Student " << s + 1 << ": " << total << endl;
    }

    // Subject averages
    cout << "\nSubject averages:\n";
    for (int sub = 0; sub < subjects; sub++) {
        float avg = 0;
        for (int s = 0; s < students; s++) {
            avg += scores[s][sub];
        }
        avg /= students;
        cout << "Subject " << sub + 1 << ": " << avg << endl;
    }

    // Topper
    int bestStudent = 0;
    for (int s = 1; s < students; s++) {
        if (sums[s] > sums[bestStudent]) {
            bestStudent = s;
        }
    }
    cout << "\nTopper: Student " << bestStudent + 1
         << " with " << sums[bestStudent] << " marks\n";

    // Free memory
    for (int s = 0; s < students; s++) {
        delete[] scores[s];
    }
    delete[] scores;
    delete[] sums;

    return 0;
}
