#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

//Clear Input Buffer
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {

    //Request User Varying String Length (RNG)
    srand(time(nullptr));

    for (int i = 0; i < 3; ++i) {
        string input1, input2;

        int length1 = rand() % 10 + 1;
        int length2 = rand() % 10 + 1;

        cout << "Enter string 1 (up to " << length1 << " characters): ";
        getline(cin, input1);

        //Check Input Length
        if (input1.length() != length1) {
            cout << "Invalid input length. Please try again." << endl;
            --i;
            continue;
        }

        cout << "Enter string 2 (up to " << length2 << " characters): ";
        getline(cin, input2);


        if (input2.length() != length2) {
            cout << "Invalid input length. Please try again." << endl;
            --i;
            continue;
        }

        //Concat strings
        string concatenated = input1 + input2;

        //Printing result
        cout << "Concatenated string: " << concatenated << endl;

        //Error Validation
        if (cin.fail()) {
            cout << "Invalid input. Please try again." << endl;
            clearInputBuffer();
            --i;
        }
    }

    return 0;
}