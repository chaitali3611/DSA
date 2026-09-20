# Number of students
n = int(input())

students = []

# Taking input
for _ in range(n):
    name = input()
    score = float(input())
    students.append([name, score])

# Get all unique scores and sort them
scores = sorted(set([s[1] for s in students]))

# Second lowest score
second_lowest = scores[1]

# Get names with second lowest score
names = [s[0] for s in students if s[1] == second_lowest]

# Sort names alphabetically
names.sort()

# Print result
for name in names:
    print(name)