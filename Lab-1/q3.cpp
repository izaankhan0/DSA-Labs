#include <iostream>
using namespace std;

class Box
{
    int *number;

public:
    Box() // default constructor performing DMA on the one pointer
    {
        number = new int;
    }
    // getter & setter below
    void setNumber(int value) { *number = value; }
    int getNumber() const { return *number; }

    ~Box() // destructor to free memory
    {
        delete number;
    }

    Box(const Box &other) // copy constructor to ensure deep copies
    {
        number = new int(*other.number);
    }

    Box &operator=(const Box &other) // move assignment operator to move one object to another completely
    {
        if (this == &other)
        {
            return *this;
        }

        delete number; // The memory of the pervious object occupation is freed
        number = new int(*other.number);
        return *this;
    }
};

int main()
{

    // demonstration of the deep copy below
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
