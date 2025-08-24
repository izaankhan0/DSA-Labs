#include "iostream"
#include "cstring"
using namespace std;

class Exam
{
    string *Name;
    string *Date;
    int *Score;

public:
    Exam() // default constructor that performs DMA
    {
        Score = new int;
        Name = new string;
        Date = new string;
    }
    //below setters for all pointers
    void setName(string name) { *Name = name; }
    void setDate(string date) { *Date = date; }
    void setScore(int score) { *Score = score; }

    void displayExam() // display function to display exam details
    {
        cout << "Name: " << *Name << endl;
        cout << "Date: " << *Date << endl;
        cout << "Score: " << *Score << endl;
    }
    
    ~Exam() // Destructor to free memory
    {
        delete Score;
        delete Name;
        delete Date;
    }
};

int main()
{

    //demonstration of shallow copy (result of no copy constructor)

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