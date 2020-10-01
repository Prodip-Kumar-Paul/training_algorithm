# 백준 2920 음계
# https://www.acmicpc.net/problem/2920
scale = [int(x) for x in input().strip().split()]

cnt = 0

for i in range(len(scale) - 1):
    if scale[i] < scale[i + 1]:
        cnt += 1
    else:
        cnt -= 1

if cnt == 7:
    print("ascending")
elif cnt == -7:
    print("descending")
else:
    print("mixed")


scales = list(map(int, input().split(' ')))

ascending = True
descending = True

for i in range(len(scales) - 1):
    if scales[i] < scales[i + 1]:
        descending = False
    elif scales[i] > scales[i + 1]:
        ascending = False

if ascending:
    print("ascending")
elif descending:
    print("descending")
else:
    print("mixed")
