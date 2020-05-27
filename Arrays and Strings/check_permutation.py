def check_permutation(s1, s2) -> bool:
    freq = {}
    for i in s1:
        freq[i] = freq[i] + 1 if i in freq else 1
    for i in s2:
        if i in freq and freq[i] > 0:
            freq[i] -= 1
        else:
            return False
    for i in freq:
        if freq[i] > 0:
            return False
    return True

print(check_permutation("hello", "ehlol"))
print(check_permutation("hello", "ehlol "))
print(check_permutation("hello", "ehlel"))
print(check_permutation("hello", ""))
print(check_permutation("heo", "ohe"))
print(check_permutation("heo", "heo"))