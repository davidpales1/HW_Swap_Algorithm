#include <iostream> // input and out put to interact with the concole
#include <string> //  to manipulate characters within the string
#include <algorithm> // to sort the array
#include <vector>

#include <sstream>

using namespace std;



// Variable - START
//	define variables that are global between the two Variable markers
constexpr int MAX_ARRAY_SIZE = 1;
string input;
string sort_type;
int arrInt[MAX_ARRAY_SIZE];
string arrStr[MAX_ARRAY_SIZE];

// Variable - END

// Function/Method Declaration - START
//	define function/method declaration signatures between the two markers
// function to trim the value 
string trim(string s) {
    // Find first non-whitespace/null character
    size_t first = s.find_first_not_of(" \0");
    if (first == string::npos) {
        // String is all whitespace/null characters
        return "";
    }
    // Find last non-whitespace/null character
    size_t last = s.find_last_not_of(" \0");
    // Return trimmed substring
    return s.substr(first, last - first + 1);

}
// function to sort an array of string
void sort_strings(string arr[], int size) {
    sort(arr, arr + size);
}
// function to sort an array of int
void sort_integers(int arr[], int size) {
    sort(arr, arr + size);
}
// fuction to get the size of the array
int getArraySize() {
    while (true) {
        int arraySize = 0;
        // Get user input
        cout << "Enter the number of elements in the array(The number should be between 0-100): ";
        cin >> arraySize;
        if (arraySize > 0 && arraySize < 100)
        {
            return arraySize;
        }
        else {
            continue;
        }
    }
}
// function to check if the value is number
bool isNumber(string s)
{
    std::stringstream ss(s);
    float x;
    return (ss >> x) && ss.eof();
}
void createArray(int choice, int arraySize) {
    
    int* arrInt = new int[arraySize];
    string* arrStr = new string[arraySize];

    if (choice == 1) {
        
        // create an integer array
        if (arraySize >= 0 && arraySize < 100) {
            for (int i = 0; i < arraySize; i++) {
                cout << "Enter an integer value for element " << i << ": ";
                cin >> arrInt[i];
            }
        }
        else {
            cout << "The maximam size of the array should not exceed 100";
        }

        
        sort_integers(arrInt, arraySize);
        // print the integer array
        cout << "The integer array you created is: ";
        for (int i = 0; i < arraySize; i++) {
            cout << arrInt[i] << " ";
        }
    }
    else if (choice == 2) {
      
        // create a string array
        if (arraySize >= 0 && arraySize < 100) {
            for (int i = 0; i < arraySize; i++) {
                cout << "Enter a string value for element " << i << ": ";
                cin >> arrStr[i];
            }
        }
        else {
            cout << "The maximam size of the array should not exceed 100";
        }
        sort_strings(arrStr, arraySize);
        // print the string array
        cout << "The string array you created is: ";
        for (int i = 0; i < arraySize; i++) {
            cout << arrStr[i] << " ";
        }
    }
    else {
        cout << "Invalid choice. Please enter 1 for integer or 2 for string." << endl;
    }
    delete[] arrInt;
    delete[] arrStr;
}
// Function/Method Declaration - END

// main function
int main() {
    int choice;
    cout << "What type of array do you want to create!\nIf string it will sort out alphabetically and if it's int it will sort out numerically or alphabetically\n(1 for integer, 2 for string): ";
    cin >> choice;
    int arraySize = getArraySize();
    createArray(choice, arraySize);
    return 0;
}

// Function/Method Definition - START
//	define function/method declaration signatures between the two markers

// Function/Method Definition - END
