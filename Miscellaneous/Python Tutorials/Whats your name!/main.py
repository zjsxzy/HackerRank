def into_python(firstname, lastname):
    return "Hello {0} {1}! You just delved into python.".format(firstname, lastname)

if __name__ == "__main__":
    firstname = raw_input()
    lastname = raw_input()
    print into_python(firstname, lastname)