class Solution:
    def removeDuplicateLetters(self, s):
        last = {}

        # Store the last occurrence of each character
        for i in range(len(s)):
            last[s[i]] = i

        stack = []
        used = set()

        for i in range(len(s)):
            ch = s[i]

            # Skip if already present
            if ch in used:
                continue

            # Remove larger characters if they appear again later
            while stack and stack[-1] > ch and last[stack[-1]] > i:
                used.remove(stack.pop())

            stack.append(ch)
            used.add(ch)

        return ''.join(stack)