#include <iostream>
#include <cstdlib>  // For rand() function
using namespace std;

class MagicSquare {
public:
    virtual void generateMagicSquare() = 0;
    virtual void printMagicSquare() = 0;
    virtual ~MagicSquare() {}  // Add a virtual destructor for proper cleanup
};

class MagicSquare3x3 : public MagicSquare {
private:
    int userNum;
    int array[3][3];

public:
    MagicSquare3x3(int num) : userNum(num) {}

    void generateMagicSquare() override {
        if (userNum < 15) {
            int num1 = userNum / 3;
            for (int i = 0; i < 3; i++) {
                for (int m = 0; m < 3; m++) {
                    array[i][m] = num1;
                }
            }
        } else {
            int middle = userNum / 3;
            int left, top, right, bottom, a, b, c, d;

            a = middle + 3; b = middle - 3;
            c = middle + 1; d = middle - 1;

            left = userNum - (a + b);
            top = userNum - (a + c);
            right = userNum - (b + c);
            bottom = userNum - (b + d);

            array[0][0] = a; array[0][1] = top; array[0][2] = c; //row 1
            array[1][0] = left; array[1][1] = middle; array[1][2] = right; //row 2
            array[2][0] = d; array[2][1] = bottom; array[2][2] = b; //row 3
        }
    }

    void printMagicSquare() override {
        for (int i = 0; i < 3; i++) {
            for (int m = 0; m < 3; m++) {
                cout << array[i][m] << " ";
            }
            cout << endl;
        }
    }
};

class MagicSquare4x4 : public MagicSquare {
private:
    int userNum;
    int array[4][4];

public:
    MagicSquare4x4(int num) : userNum(num) {}

    void generateMagicSquare() override {
        int sum = 0;

        while (sum != userNum) {
            sum = 0;
            for (int i = 0; i < 4; i++) {
                array[i][i] = rand() % userNum;
            }

            for (int i = 0; i < 4; i++) {
                sum += array[i][i];
            }
        }
    }

    void printMagicSquare() override {
        // printing array
        int sumNum = 0;
        cout << endl;
        for (int i = 0; i < 4; i++) {
            sumNum = 0;
            cout << endl << "\t";
            for (int m = 0; m < 4; m++) {
                cout << array[i][m] << "   ";
                sumNum += array[i][m];
            }
            cout << "  " << sumNum << endl;
        }

        cout << endl << endl;
        cout << "   " << sumNum << "   " << userNum << "  " << userNum << "  " << userNum << "  " << userNum << "     " << userNum << endl;
    }
};

class MagicSquare6x6 : public MagicSquare {
private:
    int userNum;
    int array2D[6][6];

public:
    MagicSquare6x6(int num) : userNum(num) {}

    void generateMagicSquare() override {
        int sum = 0;
        int array[6];
        while (sum != userNum) {
            sum = 0;
            for (int i = 0; i < 6; i++) {
                array[i] = rand() % userNum;
                sum += array[i];
            }
        }

        int a, b, c, d, e, f;
        a = array[0]; b = array[1]; c = array[2]; d = array[3]; e = array[4]; f = array[5];

        // assigning the a, b, c, d, e, f position in magic square to align with rules
        array2D[0][0] = b; array2D[0][1] = f; array2D[0][2] = a; array2D[0][3] = e; array2D[0][4] = d; array2D[0][5] = c;
        array2D[1][0] = e; array2D[1][1] = c; array2D[1][2] = d; array2D[1][3] = f; array2D[1][4] = b; array2D[1][5] = a;
        array2D[2][0] = a; array2D[2][1] = b; array2D[2][2] = f; array2D[2][3] = d; array2D[2][4] = c; array2D[2][5] = e;
        array2D[3][0] = c; array2D[3][1] = d; array2D[3][2] = e; array2D[3][3] = a; array2D[3][4] = f; array2D[3][5] = b;
        array2D[4][0] = d; array2D[4][1] = a; array2D[4][2] = b; array2D[4][3] = c; array2D[4][4] = e; array2D[4][5] = f;
        array2D[5][0] = f; array2D[5][1] = e; array2D[5][2] = c; array2D[5][3] = b; array2D[5][4] = a; array2D[5][5] = d;
    }

    void printMagicSquare() override {
        // printing array
        for (int i = 0; i < 6; i++) {
            for (int m = 0; m < 6; m++) {
                cout << array2D[i][m] << "  ";
            }
            cout << endl;
        }
    }
};

class MagicSquare2x2 : public MagicSquare {
private:
    int userNum;
    int arr2[2][2];

public:
    MagicSquare2x2(int num) : userNum(num) {}

    void generateMagicSquare() override {
        int sum = 0;

        while (sum != userNum) {
            sum = 0;

            for (int i = 0; i < 2; i++) {
                arr2[i][i] = rand() % userNum;
            }

            for (int i = 0; i < 2; i++) {
                sum += arr2[i][i];
            }
        }
    }

    void printMagicSquare() override {
        // printing array
        int sumNum = 0;
        cout << endl;
        for (int i = 0; i < 2; i++) {
            sumNum = 0;
            cout << endl << "\t";
            for (int m = 0; m < 2; m++) {
                cout << arr2[i][m] << "   ";
                sumNum += arr2[i][m];
            }
            cout << "  " << sumNum << endl;
        }

        cout << endl << endl;
        cout << "   " << sumNum << "   " << userNum << "  " << userNum << "     " << userNum << endl;
    }
};

int main() {
    int userChoice, userNum;

    cout << "Enter the number: ";
    cin >> userNum;

    cout << "Choose the magic square type:" << endl;
    cout << "1. 3x3 Magic Square" << endl;
    cout << "2. 4x4 Magic Square" << endl;
    cout << "3. 6x6 Magic Square" << endl;
    cout << "4. 2x2 Magic Square" << endl;

    cin >> userChoice;

    MagicSquare *magicSquare = nullptr;  // Initialize to nullptr

    switch (userChoice) {
        case 1:
            magicSquare = new MagicSquare3x3(userNum);
            break;
        case 2:
            magicSquare = new MagicSquare4x4(userNum);
            break;
        case 3:
            magicSquare = new MagicSquare6x6(userNum);
            break;
        case 4:
            magicSquare = new MagicSquare2x2(userNum);
            break;
        default:
            cout << "Invalid choice." << endl;
            return 1;
    }

    magicSquare->generateMagicSquare();
    magicSquare->printMagicSquare();

    delete magicSquare;  // Release memory

    return 0;
}
