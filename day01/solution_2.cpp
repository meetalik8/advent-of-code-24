#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


int similarityScore(vector<int>& left, vector<int>& right){
    int score=0;
    unordered_map<int,int> mpp;
    // right num->occurance
    int n=right.size();

    for(int i=0; i<n;i++){
        mpp[right[i]]++;
    }
    int m=left.size();
    for(int i=0;i<m;i++){
        if(mpp.find(left[i])!=mpp.end()){
            score = score + left[i] * mpp[left[i]];
        }
    }
    return score;
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

    int result = similarityScore(col1, col2);
    cout<< result;

    return 0;
}
