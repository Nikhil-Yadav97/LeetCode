from functools import cache
class Solution:
    def stoneGame(self, piles: List[int]) -> bool:

        @cache
        def fn(st, end):
            if st >= end:
                return 0

            takefirst = piles[st] + min(fn(st + 2, end), fn(st + 1, end - 1))
            takelast = piles[end] + min(fn(st + 1, end - 1), fn(st, end - 2))
            return max(takefirst, takelast)

        alicescore = fn(0, len(piles) - 1)
        totalscore = sum(piles)
        bobscore = totalscore - alicescore
        return alicescore > bobscore
