
# assuming that 'largest number' means in 32 bits
def next_number(num):
    num += 1
    count = 0

    while num > 0:
        count += 1 if num % 2 == 1 else 0
        num //= 2

    smallest = (1 << count) - 1
    print("\nSmallest: ", smallest)
    print("Smallest in base 2: ", str(bin(smallest))[2:])
    
    largest = smallest << (32 - count)
    
    print("\nLargest: ", largest)
    print("Largest in base 2: ", str(bin(largest))[2:])

next_number(5)