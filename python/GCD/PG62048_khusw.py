'''
    멀쩡한 사각형 (Programmers Level 2)
    https://programmers.co.kr/learn/courses/30/lessons/62048

    가로 w , 세로 h 인 직사각형이 주어진다.
    직사각형 내부에는 1 by 1 의 크기인 정사각형들로 구성되어 있다.
    이 직사각형의 대각선을 이어서 반으로 쪼갠다.
    그러면 두개의 삼각형이 된다.
    이 대각선이 거쳐가는 정사각형의 갯수를 구해서 전체 갯수(W * H)에서 빼는 문제다

    이 문제는 최대 공약수를 구하는 문제다.
    본래 주어진 w (가로) , h (세로) 의 최대 공약수를 구해서 이 w, h 를 나누고
    작은 직사각형에서 겹치는 정사각형 갯수에 최대 공약수를 곱하면 결국 같은 값이 된다.
    즉 큰 문제를 작게 쪼개서 파악하는 방법이다.

    사실 이게 왜 최대 공약수 문제인지 아무리 봐도 도저히 알지 못했다.
    그러다 한참 고민 한 후에, 다른 이들의 답을 보고서 알았다.
    level 2 부터 이렇게 어렵다니
    앞이 캄캄하다..
'''


def solution(w, h):
    answer = 1
    maxValue = 0
    for index in range(1, max(w, h) + 1):
        if w % index == 0 and h % index == 0:  # 공약수 구하기
            commonDivisor = index
            if maxValue < commonDivisor:
                maxValue = commonDivisor  # 최대 공약수 지정

    remove = w + h - maxValue  # 쓰지 못하는 정사각형 부분, 즉 대각선이 가로지르는 정사각형 갯수를 의미한다.
    # remove, answer 에 대한 설명은 아래 주석에 다시 쓴다.
    answer = w * h - remove

    return answer


'''
    왜 remove 와 answer 의 공식이 저렇게 나오는가?

    1. W * H 의 크기인 직사각형에서 대각선 정사각형 갯수를 구하지 말고 
    최대공약수로 나눈 값으로 직사각형을 나눠서 나중에 최대공약수 곱해서 구한다.

    최대공약수로 나눈 가로 세로 값을 각각 w' , h' 라 치면,
    대각선은 세로줄 중 w' - 1 번째의 세로줄을 지나고, 가로줄 중 h' - 1 을 지난다.
    W, H 가 각각 8, 12 일 때, GCD (최대 공약수) = 4, w' = 2, h' = 3 이 된다.
    2 * 3 직사각형을 그려서 대각선을 직접 그려보면, w' - 1 번째 세로줄, h' - 1 번째 가로줄을 지난 것을 알 수 있다.
    이에 기반하여 대각선이 지나는 정사각형 갯수를 구하게 되면,
    1 + (w' - 1) + (h' - 1) 이 된다 (1은 첫 정사각형을 말한다.)
    즉, w' + h' - 1 이 되며, 이는 GCD 로 나눈 값이므로, GCD 를 곱한다
    그렇게 되면 remove = W + H - maxValue(=GCD) 가 나오게 되는 것.

    즉, remove 가 대각선이 지나게 되는 총 정사각형의 갯수를 의미하고,
    answer 는 전체 정사각형에서 remove 를 빼면 되는 것이므로
    answer = W * H - remove 가 된다.
'''
