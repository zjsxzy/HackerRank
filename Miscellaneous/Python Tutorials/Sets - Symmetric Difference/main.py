def not_in_both(l, l2):
    seta, setb = set(l), set(l2)
    return sorted(seta.symmetric_difference(setb))

if __name__ == "__main__":
    _ = input()
    l = map(int, raw_input().split())
    _ = input()
    l2 = map(int, raw_input().split())
    for i in not_in_both(l, l2):
        print i