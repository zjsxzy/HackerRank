def get_percentage_of(students, name):
    return float(sum(students[name]) / len(students[name]))

if __name__ == "__main__":
    n = input()
    students = dict()
    for i in range(n):
        name, scores = raw_input().split(' ', 1)
        students[name] = map(float, scores.split())
    target = raw_input()
    print "{0:0.2f}".format(get_percentage_of(students, target))