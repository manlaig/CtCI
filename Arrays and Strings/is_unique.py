def is_unique(s) -> bool:
    dict = {}
    for letter in s:
        if letter in dict:
            return False
        else:
            dict[letter] = True
    return True

print(is_unique("hel"))
print(is_unique("hell"))
print(is_unique("helol"))
print(is_unique(""))