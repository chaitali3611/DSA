# Enter your code here. Read input from STDIN. Print output to STDOUT

n, m = map(int, input().split())

for i in range(n // 2):
    pattern = '.|.' * (2 * i + 1)
    print(pattern.center(m, '-'))

print('WELCOME'.center(m, '-'))

for i in range(n // 2 - 1, -1, -1):
    pattern = '.|.' * (2 * i + 1)
    print(pattern.center(m, '-'))