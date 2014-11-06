def get_index_substring(string, substr):
    count = 0
    while substr in string:
        count += 1
        string = string[string.index(substr) + 1: ]
    return count

if __name__ == "__main__":
    string = raw_input()
    substr = raw_input()
    print get_index_substring(string, substr)