#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
#include <string>

int validMultiplications(string s){
    int result=0;
    // xmul(2,4)%&mul[3,7]!@^don't()_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5))
    string pattern = "mul(";

    bool dont = false;
    for(int i=0;i<s.size();i++){
        if(s[i]=='m'){
            //I am checking if the whole mul( is there
            int t=0;
            while(i < s.size()&& s[i]==pattern[t]){
                i++;
                t++;
            }
            //checking if while broke because s[i] was no longer matching my pattern, in that case next iteration
            if(t!=4){
                continue;
            } else{
                // after pattern i want a digit
                if(isdigit(s[i])){
                    string num="";
                    num +=s[i];
                    i++;
                    while(i < s.size() && isdigit(s[i])){
                            num+=s[i];
                            i++;
                    }

                    // after 1st digit ends it should be a comma
                    if(s[i]==','){
                        i++;
                        //ignore the comma and it should be 2nd digit
                        if(isdigit(s[i])){
                        string num2="";
                        num2+=s[i];
                        i++;
                        while(i < s.size()&& isdigit(s[i])){
                            num2+=s[i];
                            i++;
                        }

                        // after the 2nd digit it should be )
                        if(s[i]==')' && !dont){
                        int num1 = stoi(num);
                        int numb2 = stoi(num2);

                        int prod = num1 * numb2;
                        result = prod + result;
                        }
                    }
                    }
                }
            }
        }
        if(s[i]=='d' && i<s.size() &&(i+2) <s.size() && s[i+2]=='n'){
            dont = true;
        } else if(s[i]=='d' && i<s.size() && (i+1) <s.size() && s[i+1]=='o'){
            dont=false;
        }
    }
    return result;
}

int main() {
    ifstream inputFile("input.txt");

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
