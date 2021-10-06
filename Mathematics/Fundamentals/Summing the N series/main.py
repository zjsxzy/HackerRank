def solve():
    n = int(input())
    mod = 1000000007
    print(n * n % mod)


if __name__ == "__main__":
    ts = int(input())
    for i in range(ts):
        solve()
