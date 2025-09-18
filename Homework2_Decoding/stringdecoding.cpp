#include "stringdecoding.h"
#include <iostream>
#include <string>
using namespace std;

string decode(string exp, string code) {
    string result = "";

    StackType<char> code_char;
    QueType<char> normal_char;

    //Use a stack for characters in 'code' and a queue for other characters
    for(int i = 0; i <exp.length(); i++){
        char current_char = exp.at(i);
        if(code.find(current_char) == string::npos){
            normal_char.Enqueue(current_char);
        } else {
            code_char.Push(current_char);
        }
    }

    //Reconstruct the decoded string
    while (!normal_char.IsEmpty()) {
        char temp_char;
        normal_char.Dequeue(temp_char);
        result += temp_char;
    }
    while (!code_char.IsEmpty()) {
        char temp_char = code_char.Pop();
        result += temp_char;
    }

    return result;
}