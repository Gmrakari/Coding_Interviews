
/**
 *
 * @filename:strcpy_and_filterstr.cpp
 * @function:
 * @return:
 * @author:Zhanyou Zhou (gmrakari@outlook.com)
 * @date:2022/5/26 22:37
 *
 */

#include "../include/langCHeader.h"

char* m_strcpy(char *strDest, const char* strStr) {
    if (strStr == NULL) return NULL;
    memset(strDest, 0, sizeof(strDest));

    for (int i = 0; strStr[i] != '\0';i++) {
        strDest[i] = strStr[i];
    }
    return strDest;
}

void test_strcpy() {
    char strStr[] = "abc";
    char *strDest;
    m_strcpy(strDest, strStr);

    int i = 0;

    for (int i = 0; strDest[i] != '\0';i++) {
        printf("%c", strDest[i]);
    }
    printf("\n");
}

void fliterStr(char *linputStr, long lInputLen, char *lOutputStr) {
    if (linputStr == NULL || lInputLen < 0) return;
    long k = 0;
    //memset(lOutputStr, 0, sizeof(lOutputStr));
    for (long i = 0; i < lInputLen; i++) {
       for (int j = 1; j < lInputLen - 1; j++) {
           if (linputStr[i] != linputStr[j]) {
               m_strcpy(lOutputStr, linputStr);
               k++;
               //lOutputStr[k++] = linputStr[i];
               break;
           } {
               continue;
           }
       }
    }
}

void test_str() {
    char *str = "abc";
    for (int i = 0; i < sizeof(str) / sizeof(str[0]); i++) {
        strcpy(str, 'a');
    }
    printf("%s\n", *str);

}

void test_fliterStr() {
    char input[] = "abababa";
    char *output;
    long len = sizeof(input) / sizeof(input[0]);
    fliterStr(input, len, output);

    for (int i = 0; output[i] != '\0';i++) {
        printf("%c", output[i]);
    }
    printf("\n");

}

/*
 * @date:2022-05-27 12:59
 * todo : 测试字符赋值操作
 * char *str 是怎么赋值的
 *
 */

int main() {
    //test_fliterStr();
    test_str();
}