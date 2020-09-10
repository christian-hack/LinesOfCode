//
//  main.cpp
//  LinesOfCode
//
//  Created by Christian Hackelman on 9/9/20.
//  Copyright © 2020 Christian Hackelman. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
using namespace std;
bool isSourceCode (string curLine) {
    for (int i = 0; i < curLine.size(); ++i) {
        if (curLine.at(i) == '/') {
            if (curLine.at(i + 1) == '/') {
                return false;
            }
        }
        else if (curLine.at(i) == ';' || curLine.at(i) == '{' || curLine.at(i) == '}') {
            return true;
        }
    }
    return false;
}
bool isCommentCode (string curLine) {
    for (int i = 0; i < curLine.size(); ++i) {
        if (curLine.at(i) == '/') {
            if (curLine.at(i + 1) == '/' || curLine.at(i + 1) == '*') {
                return true;
            }
        }
    }
    return false;
}
int main(int argc, const char * argv[]) {
    string input, line;
    bool stillComment = false;
    int sourceCount = 0, commentCount = 0, lineCount = 0;
    // insert code here...
    cout << "Welcome to my CodeCounter!\n";
    while (input != "n") {
        cout << "Please enter the file directory for analysis:\n";
        cin >> input;
        ifstream ifs;
        ifs.open(input);
        while (getline(ifs, line)) {
            if (!line.empty()) {
                ++lineCount;
                if (isCommentCode(line)) {
                    ++commentCount;
                    stillComment = true;
                    while (stillComment) {
                        getline(ifs, line);
                        if (!isSourceCode(line)) {
                            ++commentCount;
                            ++lineCount;
                        }
                        else {
                            stillComment = false;
                            ++sourceCount;
                            ++lineCount;
                        }
                    }
                }
                else {
                    if (isSourceCode(line)) {
                        ++sourceCount;
                    }
                }
            }
        }
        cout << "Total lines: " << lineCount << ", Comment lines: " << commentCount << ", Source code lines: " << sourceCount << "\nANALYSIS COMPLETE\nWould you like to enter another file?\nYes('y') or No('n')?\n";
        cin >> input;
    }
    cout << "Thank you for using my LineCounter!\n";
    return 0;
}
