from functools import lru_cache

def solve():
    nums = [int(x) for x in input().split()]
    a, b = [], []
    for i in range(0, len(nums) - 2, 2):
        a.append(nums[i])
        b.append(nums[i + 1])
    c, d = nums[-2], nums[-1]

    @lru_cache(maxsize=None)
    def f(x, y):
        if x <= 0 or y <= 0:
            return d
        ans = c
        for ai, bi in zip(a, b):
            ans += f(x - ai, y - bi)
        return ans

    query_nums = nums = [int(x) for x in input().split()]
    for i in range(0, len(query_nums), 2):
        x = query_nums[i]
        y = query_nums[i + 1]
        print(f(x, y))
    print("")

t = int(input())
for _ in range(t):
    solve()
