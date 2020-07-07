def draw_line(arr, width, x1, x2, y):
    if len(arr) <= 0:
        return
    
    height = len(arr) // (width // 8)
    if y >= height:
        return
    y = height - y - 1

    for i in range(x1, x2+1, 1):
        index = i // 8 + y * (width // 8)
        lst = list(arr[index])
        lst[i % 8] = '1'
        arr[index] = ''.join(lst)

    for i in range(len(arr)):
        if i % (width // 8) == 0:
            print()
        print(arr[i], end=' ')
    print()


draw_line(["10000000", "00000001",
           "00000000", "00000001"], 16, 3, 8, 0)

draw_line(["10000000", "00000001",
           "00000000",  "00000000",
           "00000001", "00000000"], 16, 3, 8, 2)