def calc_lps(s):
    lps = [0]*len(s)
    i = 1
    l = 0
    m = len(s)

    while i<m:
        if s[i]==s[l]:
            l+=1
            lps[i]=l
            i+=1
        else:
            if l:
                l = lps[l-1]
            else:
                lps[i]=0
                i+=1

    return lps

def check_pattern(txt,pat):
    i=0
    j=0
    n = len(txt)
    m=len(pat)
    lps = calc_lps(pat)
    while i<n:
        if txt[i]==pat[j]:
            i+=1
            j+=1

        else:
            if j!=0:
                j = lps[j-1]
            else:
                i+=1
        if j==m:
            print(i-j)
            j  = lps[j-1]




txt = "ONIONIONSONIONIONS"
s = "ONIONS"
print(calc_lps(s))
check_pattern(txt,s)
