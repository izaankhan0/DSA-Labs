#include <iostream>
using namespace std;

class DynamicMatrix {
private:
    int** matrix;
    int rows;
    int cols;

public:
    // Construcor
    DynamicMatrix(int rows, int cols) : rows(rows), cols(cols), matrix(nullptr) {
        if (rows <= 0 || cols <= 0) {
            cerr << "Err: Rows and cols must be positive." << endl;
            return;
        }

        matrix = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = new int[cols];
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] = 0; // Initialize All elements to 0
            }
        }
    }

    // Destructor
    ~DynamicMatrix() {
        if (matrix) {
            for (int i = 0; i < rows; ++i) {
                delete[] matrix[i];
            }
            delete[] matrix;
            matrix = nullptr;
        }
    }

    // Resize Matrix
    void resize(int newRows, int newCols, int initialValue = 0) {
        if (newRows <= 0 || newCols <= 0) {
            cerr << "Err: Rows and cols must be positive.";
            return;
        }

        int** newMatrix = new int*[newRows];
        for (int i = 0; i < newRows; ++i) {
            newMatrix[i] = new int[newCols];
            for (int j = 0; j < newCols; ++j) {
                if (i < rows && j < cols) {
                    newMatrix[i][j] = matrix[i][j]; // Copy from old matrix
                } else {
                    newMatrix[i][j] = initialValue; // Initialize new elements
                }
            }
        }

        //Deallocate old matrix
        if (matrix) {
            for (int i = 0; i < rows; ++i) {
                delete[] matrix[i];
            }
            delete[] matrix;
        }

        matrix = newMatrix;
        rows = newRows;
        cols = newCols;
    }

    // Transpose Matrix
    void transpose() {
        int** newMatrix = new int*[cols];
        for (int i = 0; i < cols; ++i) {
            newMatrix[i] = new int[rows];
            for (int j = 0; j < rows; ++j) {
                newMatrix[i][j] = matrix[j][i];
            }
        }

        //Deallocate old matrix
        if (matrix) {
            for (int i = 0; i < rows; ++i) {
                delete[] matrix[i];
            }
            delete[] matrix;
        }

        swap(rows, cols);
        matrix = newMatrix;
    }

    // Print Matrix
    void print() const {
        if (!matrix) {
            cout << "Matrix is empty." << endl;
            return;
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if ((i * cols + j) % 2 != 0) {
                  cout << matrix[i][j] + 2 << " ";
                } else {
                  cout << matrix[i][j] << " ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    // Example usage
    DynamicMatrix matrix(3, 4);
    cout << "Original Matrix:" << endl;
    matrix.print();

    matrix.resize(5, 6, 1); // Resize to 5x6, now all new elements with 1 val
    cout << "\nResized Matrix:" << endl;
    matrix.print();

    matrix.transpose();
    cout << "\nTransposed Matrix:" << endl;
    matrix.print();

    return 0;
}