n = int(input())

student_marks = {}

for _ in range(n):
    name, *marks = input().split()
    marks = list(map(float, marks))
    student_marks[name] = marks

query_name = input()

marks_list = student_marks[query_name]
average = sum(marks_list) / len(marks_list)

print("{:.2f}".format(average))