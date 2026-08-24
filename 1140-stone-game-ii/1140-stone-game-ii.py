from functools import cache
class Solution:
    def stoneGameII(self, piles: List[int]) -> int:

        @cache
        def fn(ind, chance, M):

            if ind >= len(piles):
                return 0
            result = float("-inf") if chance else float("inf")

            sum = 0
            for i in range(ind, min(len(piles), 2 * M + ind)):
                X=i-ind+1
                sum += piles[i]
                if chance:
                    result = max(result, sum + fn(ind + X, not chance, max(X, M)))
                else:
                    result = min(result, fn(ind + X, not chance, max(X, M)))
            return result

        return fn(0, 1, 1)
