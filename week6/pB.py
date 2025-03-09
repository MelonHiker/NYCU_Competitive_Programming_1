from decimal import Decimal

def main():
    t = [Decimal(x) for x in input().split()]
    target = Decimal(input())
    target *= Decimal("3")
    t.sort()
    if t[1] + t[2] + t[3] <= target:
        print("infinite")
        return
    ans = target - t[1] - t[2]
    if ans >= t[0] and ans <= t[3]:
        print("{:.2f}".format(ans))
        return
    print("impossible")

if __name__ == '__main__':
    main()