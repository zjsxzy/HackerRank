def sort_age(func):
    def inner(persons):
        persons = sorted(persons, key = lambda x: x[1])
        return [func(name, sex) for (name, age, sex) in persons]
    return inner

@sort_age
def list_name(name, sex):
    title = {"M": "Mr. ", "F": "Ms. "}
    return title[sex] + name

if __name__ == "__main__":
    persons = []
    for i in range(input()):
        data = raw_input().split()
        name, age, sex = data[0] + ' ' + data[1], int(data[2]), data[3]
        persons.append([name, age, sex])

    print '\n'.join(list_name(persons))