#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function prototypes
void identifyToken(const string& token);
bool isKeyword(const string& token);
bool isDataType(const string& token);
bool isSpecialChar(char c);
bool isNumber(const string& token);

int main() {
    string inputCode;
    string token;

    cout << "Enter the C++ code:\n";
    getline(cin, inputCode);

    for (char c : inputCode) {
        if (isalnum(c) || c == '_') {
            token += c;
        } else {
            if (!token.empty()) {
                identifyToken(token);
                token.clear(); // Reset token
            }
            if (isSpecialChar(c)) {
                string specialToken(1, c);
                identifyToken(specialToken);
            }
        }
    }

    if (!token.empty()) {
        identifyToken(token);
    }

    cout << "Lexical analysis completed.\n";

    return 0;
}

// Function to identify tokens
void identifyToken(const string& token) {
    if (token.size() == 1 && isSpecialChar(token[0])) {
        char c = token[0];
        switch (c) {
            case '+':
                cout << token << " is a plus.\n";
                break;
            case '-':
                cout << token << " is a minus.\n";
                break;
            case '*':
                cout << token << " is a multiplication.\n";
                break;
            case '/':
                cout << token << " is a division.\n";
                break;
            case '=':
                cout << token << " is an equal sign.\n";
                break;
            case '<':
                cout << token << " is a less than sign.\n";
                break;
            case '>':
                cout << token << " is a greater than sign.\n";
                break;
            case '(':
                cout << token << " is a left parenthesis.\n";
                break;
            case ')':
                cout << token << " is a right parenthesis.\n";
                break;
            case '{':
                cout << token << " is a left curly brace.\n";
                break;
            case '}':
                cout << token << " is a right curly brace.\n";
                break;
            case '[':
                cout << token << " is a left square bracket.\n";
                break;
            case ']':
                cout << token << " is a right square bracket.\n";
                break;
            case ';':
                cout << token << " is a semicolon.\n";
                break;
            case ',':
                cout << token << " is a comma.\n";
                break;
            default:
                cout << token << " is an unknown special character.\n";
        }
    } else if (isKeyword(token)) {
        cout << token << " is a keyword.\n";
    } else if (isDataType(token)) {
        cout << token << " is a data type.\n";
    } else if (isNumber(token)) {
        cout << token << " is a number.\n";
    } else {
        cout << token << " is an identifier.\n";
    }
}

// Function to check if a token is a keyword
bool isKeyword(const string& token) {
    static const string keywords[] = {"for", "while", "do", "int", "float", "char", "double", "static", "switch", "case"};
    for (const string& keyword : keywords) {
        if (token == keyword) {
            return true;
        }
    }
    return false;
}

// Function to check if a token is a data type
bool isDataType(const string& token) {
    static const string dataTypes[] = {"int", "float", "char"};
    for (const string& dataType : dataTypes) {
        if (token == dataType) {
            return true;
        }
    }
    return false;
}

// Function to check if a character is a special character or arithmetic operator
bool isSpecialChar(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '=' || c == '<' || c == '>' || c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']' || c == ';' || c == ',');
}

// Function to check if a token is a number
bool isNumber(const string& token) {
    for (char c : token) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}
