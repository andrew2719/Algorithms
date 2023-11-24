# base = 10

# def hash(s):
#     h = 0
#     base = 10
#     for i in range(len(s)):
#         h+=ord(s[i]) *(base**(len(s)-i-1))
#     return h

# def rabin_karp(txt,pat):
    
#     n = len(txt)
#     m = len(pat)
#     p = hash(pat)
#     t = hash(txt[:m])
#     for i in range(n-m+1):
#         if t == p:
#             if txt[i:i+m] == pat:
#                 return i
#         if i < n-m:
#             t = base*(t-ord(txt[i])*base**(m-1))+ord(txt[i+m])
#     return -1

# txt = "GEEKS FOR GEEKS"
# pat = "GEEK"
# print(rabin_karp(txt,pat))

# Rabin-Karp algorithm in python


d = 10

def search(pattern, text, q):
    m = len(pattern)
    n = len(text)
    p = 0
    t = 0
    h = 1
    i = 0
    j = 0

    for i in range(m-1):
        h = (h*d) % q

    # Calculate hash value for pattern and text
    for i in range(m):
        p = (d*p + ord(pattern[i])) % q
        t = (d*t + ord(text[i])) % q

    # Find the match
    for i in range(n-m+1):
        if p == t:
            for j in range(m):
                if text[i+j] != pattern[j]:
                    break

            j += 1
            if j == m:
                print("Pattern is found at position: " + str(i+1))

        if i < n-m:
            t = (d*(t-ord(text[i])*h) + ord(text[i+m])) % q

            if t < 0:
                t = t+q


text = "GEEKS FOR GEEKS"
pattern = "GEEK"
q = 13
search(pattern, text, q)