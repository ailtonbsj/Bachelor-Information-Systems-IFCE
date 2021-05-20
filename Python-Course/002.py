inp = "?ba??b"

s = list(inp)
for index in range(len(s)):
    if s[index] == '?':
        if index == 0:
            next_letter = s[index + 1]
            s[index] = 'b' if next_letter == 'a' else 'a'
        else:
            prev_letter = s[index - 1]
            s[index] = 'b' if prev_letter == 'a' else 'a'''
out = ''.join(s)

print(inp)
print(out)
