#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        cerr << "Error: Could not open the file." << endl;
        return 1;
    }
    // Datastructure to format the data
    // vector<int> col1, col2; 
    // int num1, num2;        

    // while (inputFile >> num1 >> num2) { 
    //     col1.push_back(num1);
    //     col2.push_back(num2);
    // }

    // inputFile.close();

    return 0;
}
