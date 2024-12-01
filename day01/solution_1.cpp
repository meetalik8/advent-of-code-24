#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


int sumOfDistances(vector<int>& left, vector<int>& right){
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int sum=0;
    int n = min(left.size(), right.size());
    int i=0;
    for (int i = 0; i < n / 2; i++) {
        int left_sum = abs(left[i] - right[i]);
        int right_sum = abs(left[n - i - 1] - right[n - i - 1]);
        sum += left_sum + right_sum;
    }
    if(n%2==1){
        sum = sum+abs(left[n/2]-right[n/2]);
    }
    return sum;
};


int main() {
    ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        cerr << "Error: Could not open the file." << endl;
        return 1;
    }

    vector<int> col1, col2; 
    int num1, num2;        

    while (inputFile >> num1 >> num2) { 
        col1.push_back(num1);
        col2.push_back(num2);
    }

    inputFile.close();

    int result = sumOfDistances(col1, col2);
    cout<< result;

    return 0;
}
