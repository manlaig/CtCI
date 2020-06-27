
def flip_bit(num, base):
    if base != 10 and base != 2:
        print("either base 10 or base 2")
        return

    if base == 10:
        num = bin(num)[2:]

    s = str(num)

    encode = ""
    count = 0
    for c in s:
        if c == '1':
            count += 1
        else:
            if count > 0:
                encode += str(count)
                encode += ' '
            count = 0
            encode += '0 '
    if count > 0:
        encode += str(count)

    print("encoding: ", encode)
    encode = encode.split(' ')
    most = 0
    for i in range(len(encode)):
        if encode[i] == '0':
            left = int(0 if i-1 < 0 else encode[i-1])
            right = int(0 if i+1 >= len(encode) else encode[i+1])
            most = max(most, left + right)
        else:
            most = max(most, int(encode[i]))

    return most

print(flip_bit(1775, 10))
print(flip_bit(1001110110011111111111, 2))
print(flip_bit(100111011001111, 2))