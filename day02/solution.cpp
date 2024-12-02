#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

bool safeReport(vector<int>& row){
    int n=row.size();
    bool inc = row[0] <= row[1];
    bool isSafeRow = true;
    for(int c=0;c<n-1;c++ ){
            int res =row[c] - row[c+1];
            if((res > 0 && inc) ||(res< 0 && !inc) || res==0){
               isSafeRow = false;
               break;
            } else {
                if((abs(res) >=1) && (abs(res) <=3)){
                    isSafeRow= true;
                } else {
                    isSafeRow=false;
                    break;
                }
            }
        }
        return isSafeRow;
}

int numOfSafeReports(vector<vector<int>>& matrix){
    int count=0;
    int m=matrix.size();

    for(int r=0; r<m; r++){
        if(safeReport(matrix[r])){
            count++;
        }
    }
    return count;
}

int numOfSafeReportsWithTolerance(vector<vector<int>>& matrix){
    int count=0;
    int m=matrix.size();

    for(int r=0; r<m; r++){
        if(safeReport(matrix[r])){
            count++;
            continue;
        }

        int n = matrix[r].size();
        bool canBeSafe=false;
        for(int i=0;i<n;i++){
            vector<int> tempRow =matrix[r];
            tempRow.erase(tempRow.begin()+i);
            bool safe = true;
            if(safeReport(tempRow)){
                canBeSafe=true;
                break;
            }
        }
        if(canBeSafe){
            count++;
        }
    }
    return count;
}


int main() {
    ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        cerr << "Error: Could not open the file." << endl;
        return 1;
    }
    vector<vector<int>> matrix;
    string line;

    while (getline(inputFile, line)) {
        vector<int> row;
        stringstream ss(line); 
        int num;

        while (ss >> num) {
            row.push_back(num);
        }

        matrix.push_back(row);
    }

    inputFile.close();

    // int result = numOfSafeReports(matrix);
    int result = numOfSafeReportsWithTolerance(matrix);
    cout<< result;

    return 0;
}
