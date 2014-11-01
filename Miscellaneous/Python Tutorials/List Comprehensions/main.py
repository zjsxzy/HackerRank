def get_lists(x, y, z, n):
    return [[a, b, c] for a in range(x + 1) for b in range(y + 1) for c in range(z + 1) if a + b + c != n]

if __name__ == "__main__":
    x = input()
    y = input()
    z = input()
    n = input()
    print get_lists(x, y, z, n)