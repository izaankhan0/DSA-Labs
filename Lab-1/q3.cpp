/*Q3. Create a C++ class Box that uses dynamic memory allocation for an integer. Implement the
Rule of Three by defining a destructor, copy constructor, and copy assignment operator.
Demonstrate the behavior of both shallow and deep copy using test cases.*/

#include <iostream>
using namespace std;

class Box
{
    int *number;

public:
    Box()
    {
        number = new int;
    }

    void setNumber(int value) { *number = value; }
    int getNumber() const { return *number; }

    ~Box()
    {
        delete number;
    }

    Box(const Box &other)
    {
        number = new int(*other.number);
    }

    Box &operator=(const Box &other)
    {
        if (this == &other)
        {
            return *this;
        }

        delete number;
        number = new int(*other.number);
        return *this;
    }
};

int main()
{
    cout << "Deep Demo:" << endl;
    Box b1;
    b1.setNumber(42);

    Box b2 = b1;
    cout << "b1 number: " << b1.getNumber() << endl;
    cout << "b2 number: " << b2.getNumber() << endl;

    b2.setNumber(100);
    cout << "After modifying b2:" << endl;
    cout << "b1 number: " << b1.getNumber() << endl;
    cout << "b2 number: " << b2.getNumber() << endl;

    Box b3;
    b3 = b1;
    cout << "b3 number: " << b3.getNumber() << endl;

    return 0;
}
