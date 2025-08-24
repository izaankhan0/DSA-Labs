/*Q2. Create a C++ class named "Exam" using DMA designed to manage student exam records,
complete with a shallow copy implementation? Define attributes such as student name, exam
date, and score within the class, and include methods to set these attributes and display exam
details. As part of this exercise, intentionally omit the implementation of the copy constructor
and copy assignment operator. Afterward, create an instance of the "Exam" class, generate a
shallow copy, and observe any resulting issues?*/

#include "iostream"
#include "cstring"
using namespace std;

class Exam
{
    string *Name;
    string *Date;
    int *Score;

public:
    Exam()
    {
        Score = new int;
        Name = new string;
        Date = new string;
    }

    ~Exam()
    {
        delete Score;
        delete Name;
        delete Date;
    }

    void setName(string name) { *Name = name; }
    void setDate(string date) { *Date = date; }
    void setScore(int score) { *Score = score; }

    void displayExam()
    {
        cout << "Name: " << *Name << endl;
        cout << "Date: " << *Date << endl;
        cout << "Score: " << *Score << endl;
    }
};

int main()
{

    Exam candidate1;
    candidate1.setName("Izaan");
    candidate1.setDate("14 Aug");
    candidate1.setScore(98);
    cout << "Candidate#1 Details:" << endl;
    candidate1.displayExam();
    cout << endl;

    Exam candidate2 = candidate1;
    candidate2.setName("Ahmed");
    candidate2.setDate("14 Jan");
    candidate2.setScore(28);
    cout << "Candidate#2 Details:" << endl;
    candidate2.displayExam();
    cout << endl;
    cout << "Candidate#1 Details:" << endl;
    candidate1.displayExam();
    cout << endl;

    return 0;
}