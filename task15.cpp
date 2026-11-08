#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
    char A[256];
    ofstream file1("text_1.txt");
    for (int i = 0; i < 7; i++) {
        cin >> A;
        file1 << A << ", ";
    }
    file1.close();

    ifstream read1("text_1.txt");
    if (!read1.is_open()) {
        cout << "Error file1 not open";
    }

    char trans[256] = "";

    while (!read1.eof()) {
        read1.getline(trans, 256);
    }
    read1.close();

    ofstream file2("text_2.txt");
    const char* sep = " ,!&:;";
    char* buf = strtok(trans, sep);
    while (buf != NULL) {
        file2 << buf << endl;
        buf = strtok(NULL, sep);
    }
    file2.close();


    char result[256];
    ifstream read2("text_2.txt");
    if (!read2.is_open()) {
        cout << "Error file2 not open";
    }
    while (!read2.eof()) {
        read2 >> result;
        cout << result << endl;
    }
    read2.close();

    return 0;
}
