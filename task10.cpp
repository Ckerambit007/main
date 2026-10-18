#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char S[] = "This is a test, accses, intermediate";
    const char* sep = " ,!&:;";
    char scopy[256];
    strcpy(scopy, S);
    cout << scopy << endl;

    char* buf = strtok(S, sep);
    while (buf != NULL) {
        int n = strlen(buf);
        bool has_double = false;
        for (int i = 0; i < n - 1; i++) {
            bool find = false;
            for (int j = i + 1; j < n - 1; j++) {
                if (buf[i] == buf[j]) {
                    has_double = true;
                    find = true;
                    break;
                }
            }
            if (find) {
                break;
            }
        }

        if (has_double) {
            char* found = strstr(scopy, buf);
                int k = found - scopy;
                int len_scopy = strlen(scopy);
                for (int i = k; i <= len_scopy; i++) {
                    scopy[i] = scopy[i + n];
            }
        }

        buf = strtok(NULL, sep);
    }

    cout << "Result: " << scopy << endl;

    return 0;
}