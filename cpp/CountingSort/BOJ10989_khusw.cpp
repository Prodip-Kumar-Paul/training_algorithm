/*
    BOJ 10989번 수 정렬하기 3
    https://www.acmicpc.net/problem/10989
    이 문제는 입력되는 숫자의 갯수가 최대 천만개까지 들어 올 수 있다고 정의되어 있다.
    보통 백만개를 넘기는 경우라면, O(NlogN) 을 쓰더라도 (즉, 퀵정렬, 병합정렬, 힙정렬)
    PS 에서 시간초과라고 뜬다.
    이 문제의 조건을 잘 보면, '이 수는 만 보다 작거나 같은 자연수 이다' 라는게 있는데
    이런 "조건이 주어진" 정렬 문제라면, 계수 정렬을 의심해 봐야한다.
    입력 조건도 꽤나 크게 주어지고, 이처럼 조건식이 주어지는 문제는 계수 정렬일 가능성이 크다.
    (참고로 계수 정렬은 O(N) 이다)
*/

#include <iostream>

using namespace std;

int n;
int a[10001];  // 왜 10001 개 가 들어가냐면, 조건식이 만보다 작거나 같은 자연수라 했기 때문이다.
// 전역변수로 배열을 선언하는경우, 기본적으로 0 으로 초기화됨

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;  // 입력되는 수를 받아서
        a[x]++;    // 그 수에 해당하는 인덱스만 증가
    }
    for (int i = 0; i < 10001; i++) {
        while (a[i] != 0) {
            cout << i << '\n';
            a[i]--;
        }
    }
}