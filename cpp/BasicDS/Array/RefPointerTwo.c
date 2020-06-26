/*
    동적으로 할당 되는 배열

    RefPointerOne 에서도 언급했지만
    이차원 배열 사용시에 메모리 값을 고정시키는 것은
    메모리 낭비를 초래한다.

    One 에서 처럼 연속적으로 메모리를 저장하는 것은
    값을 추가할때, 메모리를 재할당 해야 하는 작업을 요구한다.
    이는 성능 하락을 초래하고, 비효율적이다.

    동적으로 문자열 배열을 위한 메모리 할당을 할 때는 아래의 사항을 고려해야 한다
    
    1. 문자열 배열은 char** 타입으로 지정하며, 문자열의 적정 갯수 혹은 최소 갯수에서 시작한다.
    초기 상태에서 문자열을 저장하기 위한 메모리 공간은 할당하지 않은 채로 시작한다 (배열선언 시에 대괄호 안에 값 안넣는다 는 뜻)

    2. 문자열 배열에 새로운 문자열을 삽입하려면, 넣으려는 문자열을 저장할 저장할 메모리를 동적으로 할당하며,
    이 동적으로 할당된 부분에 문자열을 복사한다. 
    그리고 문자열 배열의 i 번째의 칸은 새롭게 할당한 지점의 포인터를 저장한다.

    3. 1,2 번 처럼 구성하면, 배열 자체가 문자열 포인터를 저장하는 연속적인 구간이 됨
    각 포인터가 가르키는 곳은 별도로 할당된 메모리 영역을 말하게 된다.

    말로는 잘 이해가 안되니 아래 코드로 알아보자
*/

#include <stdio.h>
#include <stdlib.h> // 메모리 할당 함수
#include <string.h> // 문자열 복사 및 길이

int main()
{
    int arraySize = 4; // 문자열 배열의 크기
    char *names[4];    // 포인터들이 담긴 배열은 최초에 메모리가 정적 할당 된다.
    char buffer[30];   // 입력을 위한 버퍼
    int n = 0;
    int len = 0;

    while (n < arraySize)
    {
        // 새로운 문자열을 입력 받고 그 값을 buffer 에 저장한다
        scanf("%s", buffer);
        len = strlen(buffer);
        if (len > 0)
        { // 입력받은 데이터가 존재하면
            // 문자열을 가르키는 포인터를 작성하고, 그 사이즈는 문자열 데이터의 + 1 한 사이즈로
            char *newStrPtr = (char *)malloc(sizeof(char) * (len + 1));
            strcpy(newStrPtr, buffer);
            // 입력 받은 값 즉, 버퍼에 들어간 값의 내용을 새로 할당된 메모리(newStrPtr) 에 복사한다
            names[n] = newStrPtr;
            // 새로 할당한 값의 시작 위치를 배열에 추가.
            n++;
        }
        else
        {
            break;
        }
    }

    // 배열의 각 원소를 전부 순회하면서 문자열을 출력함
    // 다 출력한 이후엔 free 함수로 메모리 할당 해제

    for (n = 0; n < arraySize; n++)
    {
        printf("%02d: %s\n", n, names[n]);
        free(names[n]);
    }
    return 0;
}

/*
    이 내용은 아래의 사이트를 참조
    https://soooprmx.com/archives/4113
*/