#include <iostream>
using namespace std;

int main() {
    int deptCount;
    cout << "Enter the number of departments: ";
    cin >> deptCount;

    int* studentCount = new int[deptCount];
    int** scores = new int*[deptCount];

    for (int d = 0; d < deptCount; d++) {
        cout << "Enter the number of students in department " << d + 1 << ": ";
        cin >> studentCount[d];

        scores[d] = new int[studentCount[d] * 5];
        cout << "Enter marks for department " << d + 1 << ":" << endl;

        for (int s = 0; s < studentCount[d]; s++) {
            for (int subj = 0; subj < 5; subj++) {
                cout << "Student " << s + 1 << ", Subject " << subj + 1 << ": ";
                cin >> scores[d][s * 5 + subj];
            }
        }
    }

    for (int d = 0; d < deptCount; d++) {
        int maxMark = scores[d][0];
        int minMark = scores[d][0];
        double total = 0;

        for (int i = 0; i < studentCount[d] * 5; i++) {
            if (scores[d][i] > maxMark) maxMark = scores[d][i];
            if (scores[d][i] < minMark) minMark = scores[d][i];
            total += scores[d][i];
        }

        double avg = total / (studentCount[d] * 5);

        cout << "Department " << d + 1 << endl;
        cout << "  Highest: " << maxMark << endl;
        cout << "  Lowest: " << minMark << endl;
        cout << "  Average: " << avg << endl;
    }

    for (int d = 0; d < deptCount; d++) {
        delete[] scores[d];
    }
    delete[] scores;
    delete[] studentCount;

    return 0;
}
