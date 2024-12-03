#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
#include <string>

int validMultiplications(string s){
    int result=0;
    // xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5))
    string pattern = "mul(";

    bool found=false;
    for(int i=0;i<s.size();i++){
        if(s[i]=='m'){
            found=true;
            int t=0;
            while(i < s.size()&& s[i]==pattern[t]){
                i++;
                t++;
            }
            if(t!=4){
                continue;
            } else{
                if(isdigit(s[i])){
                    string num="";
                    num +=s[i];
                    i++;
                   while(i < s.size() && isdigit(s[i])){
                        num+=s[i];
                        i++;
                   }
                   if(s[i]==','){
                        i++;

                    if(isdigit(s[i])){
                    string num2="";
                    num2+=s[i];
                    i++;
                    while(i < s.size()&& isdigit(s[i])){
                        num2+=s[i];
                        i++;
                   }
                   if(s[i]==')'){
                    int num1 = stoi(num);
                    int numb2 = stoi(num2);

                    int prod = num1 * numb2;
                    result = prod + result;
                   }
                   } else{
                    continue;
                   }
                }
            }

        }
    }
    }
    return result;
}

int main() {
    ifstream inputFile("sample.txt");

    if (!inputFile.is_open()) {
        cerr << "Error: Could not open the file." << endl;
        return 1;
    }
    // Datastructure to format the data
    string s="";
    char c;
    while (inputFile >> c) { 
        s.push_back(c);

    }
    inputFile.close();

    int result= validMultiplications(s);

    cout<<result;

    return 0;
}
