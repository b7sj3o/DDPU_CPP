#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int rowCount = 8;
const int colCount = 6;
const int Low = -26;
const int High = 23;

void generateRandomMatrix(int matrix[rowCount][colCount]);
void printMatrix(const int matrix[rowCount][colCount], const char* title);
bool meetsCriterion(int value);
int countElementsMeetingCriterion(const int matrix[rowCount][colCount]);
int sumElementsMeetingCriterion(const int matrix[rowCount][colCount]);
void replaceElementsMeetingCriterionWithZeros(int matrix[rowCount][colCount]);
void sortMatrix(int matrix[rowCount][colCount]);
void copyMatrix(const int source[rowCount][colCount], int destination[rowCount][colCount]);

int main() {
    srand((unsigned)time(NULL));
    
    int matrix[rowCount][colCount] = {};
    
    generateRandomMatrix(matrix);
    printMatrix(matrix, "Original matrix");
    
    // Task 1
    int count = countElementsMeetingCriterion(matrix);
    int sum = sumElementsMeetingCriterion(matrix);
    
    cout << "Number of elements meeting the criterion (all except positive even): " << count << "/" << rowCount*colCount << "\n";
    cout << "Sum of elements meeting the criterion: " << sum << "\n\n";
    
    int modifiedMatrix[rowCount][colCount];
    copyMatrix(matrix, modifiedMatrix);
    replaceElementsMeetingCriterionWithZeros(modifiedMatrix);
    printMatrix(modifiedMatrix, "Matrix with elements meeting the criterion replaced with zeros");
    
    // Task 2
    int sortedMatrix[rowCount][colCount];
    copyMatrix(matrix, sortedMatrix);
    sortMatrix(sortedMatrix);
    printMatrix(sortedMatrix, "Sorted matrix (by columns)");
    return 0;
}


void generateRandomMatrix(int matrix[rowCount][colCount]) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            matrix[i][j] = Low + rand() % (High - Low + 1);
        }
    }
}


void printMatrix(const int matrix[rowCount][colCount], const char* title) {
    cout << title << ":\n";
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}


bool meetsCriterion(int value) {
    return !(value > 0 && value % 2 == 0);
}


int countElementsMeetingCriterion(const int matrix[rowCount][colCount]) {
    int count = 0;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            if (meetsCriterion(matrix[i][j])) {
                count++;
            }
        }
    }
    return count;
}


int sumElementsMeetingCriterion(const int matrix[rowCount][colCount]) {
    cout << matrix << endl;
    int sum = 0;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            if (meetsCriterion(matrix[i][j])) {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}


void replaceElementsMeetingCriterionWithZeros(int matrix[rowCount][colCount]) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            if (!meetsCriterion(matrix[i][j])) {
                matrix[i][j] = 0;
            }
        }
    }
}


void changeMatrixColumns(int matrix[rowCount][colCount], int col1, int col2) {
    for (int i = 0; i < rowCount; i++) {
        int tmp = matrix[i][col1];
        matrix[i][col1] = matrix[i][col2];
        matrix[i][col2] = tmp;
    }
}


void sortMatrix(int matrix[rowCount][colCount]) {
    for (int i = 0; i < colCount - 1; i++) {
        for (int j = 0; j < colCount - i - 1; j++) {
            bool swapNeeded = false;

            if (matrix[0][j] > matrix[0][j + 1]) {
                swapNeeded = true;
            } else if (matrix[0][j] == matrix[0][j + 1]) {
                if (matrix[1][j] < matrix[1][j + 1]) {
                    swapNeeded = true;
                } else if (matrix[1][j] == matrix[1][j + 1]) {
                    if (matrix[2][j] > matrix[2][j + 1]) {
                        swapNeeded = true;
                    }
                }
            }

            if (swapNeeded) {
                changeMatrixColumns(matrix, j, j + 1);
            }
        }
    }
}


void copyMatrix(const int source[rowCount][colCount], int destination[rowCount][colCount]) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            destination[i][j] = source[i][j];
        }
    }
}


