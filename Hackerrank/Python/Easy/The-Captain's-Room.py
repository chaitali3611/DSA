# Enter your code here. Read input from STDIN. Print output to STDOUT

k = int(input())
rooms = list(map(int, input().split()))

captain_room = (sum(set(rooms)) * k - sum(rooms)) // (k - 1)

print(captain_room)