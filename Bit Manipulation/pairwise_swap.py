def swap(num):
    s = list(bin(num))[2:]

    for i in range(0, len(s)-1, 2):
        s[i], s[i+1] = s[i+1], s[i]
    
    return ''.join(s)

print(swap(8))  # 1000 -> 0100
print(swap(10)) # 1010 -> 0101