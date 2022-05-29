
/**
 *
 * @filename:fliterStr.cpp
 * @function:
 * @return:
 * @author:Zhanyou Zhou (gmrakari@outlook.com)
 * @date:2022/5/27 23:24
 *
 */

#include "../include/headers.h"

class Str {
public:
    void fliterStr(char *inputStr, long lInputStrLen, char *outputStr) {
        if (inputStr == NULL || lInputStrLen < 0) return ;
        set<char> setRet;

        for (int i = 0; inputStr[i] != '\0';i++) {
            setRet.insert(inputStr[i]);
        }

        auto it = setRet.begin();

        char arr[1024];
        int k = 0;
        while (it != setRet.end()) {
            arr[k++] = *it;
            it++;
        }
        outputStr = arr;

        printf("%s", outputStr);
    }
};

void test() {
    Str t;
    char input[] = "abcababcb";
    long inputLen = sizeof(input) / sizeof(input[0]);
    char *output;
    t.fliterStr(input, inputLen, output);
    cout << endl;
}

int main() {
    test();
}