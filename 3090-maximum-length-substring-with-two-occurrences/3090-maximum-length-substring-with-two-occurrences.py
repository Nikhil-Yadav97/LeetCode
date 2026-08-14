class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        seen = {}
        l, r = 0, 0
        n = len(s)
        maxlen = 1
        while r < n:
            seen[s[r]] = seen.get(s[r], 0) + 1
            while seen[s[r]] > 2:
                seen[s[l]] -= 1
                if seen[s[l]] == 0:
                    del seen[s[l]]
                l += 1
            maxlen = max(maxlen, r - l + 1)
            r += 1

        return maxlen
