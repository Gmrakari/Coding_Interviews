

/*
 * DATE:10 November 2021 9:08 AM
 * FILENAME:05_打卡_vector_相邻元素相加.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

template <class T>
struct display {
    void operator()(const T& x) {
        cout << x << ' ';
    }
};

/*
 * 判断，当array的长度 > 2的时候进行相邻元素合并
 */
int sumOfAdjacentElements(vector<int> array) {
    if (array.size() == 0)
        return 0;
    vector<int> ret;
    int temp = 0,j = 0, ans = 0;
    while (array.size() > 2) {
        for (int i = 0;i < (int)array.size() / 2;i++) {
            temp = array[j] + array[j + 1];
            j += 2;
            ret.push_back(temp);
        }
				//如果是奇数，就把最后的一个元素加上
        if (array.size() % 2 != 0) {
            ret.push_back(array[array.size() - 1]);
        }
        j = 0;
        array.swap(ret);
        ret.clear();
    }
    for (int i = 0;i < (int)array.size();i++) {
        ans += array[i] * array[i];
    }
    return ans;
}

vector<int> init() {
    vector<int> vec = {1,2,3,4,5,6,7,8,9};
    return vec;
}

void test() {
    vector<int> vec = init();
    cout << sumOfAdjacentElements(vec) << endl;

}

int main() {
    test();
}



