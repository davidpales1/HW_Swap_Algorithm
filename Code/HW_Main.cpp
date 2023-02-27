#include <iostream> // input and out put to interact with the concole
#include <string> //  to manipulate characters within the string
#include <algorithm> // to sort the array
#include <vector>

#include <sstream>

using namespace std;



// Variable - START
//	define variables that are global between the two Variable markers
std::string* arr;
int* int_arr;
string input;

string sort_type;
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
    int arraySize = 10; // variable to store the size of the array
    // Get user input
    cout << "Enter the number of elements in the array: ";
    cin >> arraySize;
    return arraySize;
}
// function to check if the value is number
bool isNumber(string s)
{
    std::stringstream ss(s);
    float x;
    return (ss >> x) && ss.eof();
}
// Function/Method Declaration - END

// main function
int main() {
    int arraySize = getArraySize();
    arr = new std::string[arraySize];
    int_arr = new int[arraySize];

    // The line you mentioned above
    int i = 0; // Initialize i to 0
    while (arraySize) {
        cout << "Enter the " << i + 1 << " element number or string:" << endl;
        cin >> input; // add to array
        if (isNumber(trim(input)))
        {
            int_arr[i] = stoi(trim(input));
        }
        else {
            arr[i] = trim(input);
        }
        i = i + 1; // increment the initialize
        arraySize = arraySize - 1; // Decrement size
    }

    // Determine whether to sort numerically or alphabetically
    cout << "Sort the array numerically or alphabetically? (N/A): ";

    cin >> sort_type;
    // Sort the array
    if (sort_type == "numerically" || sort_type == "N" || sort_type == "n") {
        // Sort numerically
        int size = sizeof(int_arr);
        sort_integers(int_arr, size);
        cout << "Sorted array (numerically):" << endl;
        for (int i = 0; i < size; i++) {

            cout << int_arr[i] << " ";
            
        }
        cout << endl;
    }
    else {
        int size = sizeof(arr);
        // Sort alphabetically
        sort_strings(arr, size);
        cout << "Sorted array (alphabetically):" << endl;
        for (int i = 0; i < size; i++) {

            cout << arr[i] << " ";
        }
 
        cout << endl;
    }
    return 0;
}

// Function/Method Definition - START
//	define function/method declaration signatures between the two markers

// Function/Method Definition - END
