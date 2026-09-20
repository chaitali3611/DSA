from collections import Counter

# Read input
n = int(input())
sizes = list(map(int, input().split()))
customers = int(input())

# Count shoes
inventory = Counter(sizes)

total = 0

# Process each customer
for _ in range(customers):
    size, price = map(int, input().split())
    
    if inventory[size] > 0:
        total += price
        inventory[size] -= 1

# Output total money earned
print(total)