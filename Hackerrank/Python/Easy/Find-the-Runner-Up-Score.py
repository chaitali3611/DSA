# Read input
n = int(input())
arr = list(map(int, input().split()))

# Remove duplicates and sort
unique_scores = list(set(arr))
unique_scores.sort()

# Runner-up score (second highest)
print(unique_scores[-2])