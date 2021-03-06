/*
    BOJ 2908 상수
    https://www.acmicpc.net/problem/2908

    세자리의 수 2개가 입력으로 주어지고, 
    두 수를 거꾸로 뒤집은뒤 뒤집은 두 수 중 큰놈을 출력하는 문제
*/

#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string str1, str2;

    cin >> str1 >> str2;

    string str3, str4;

    for (int i = 2; i > -1; i--) {
        str3.push_back(str1[i]);
        str4.push_back(str2[i]);
    }

    if (str3 > str4) {
        cout << str3;
    } else {
        cout << str4;
    }

    return 0;
}