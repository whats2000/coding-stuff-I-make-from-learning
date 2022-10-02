# the function will return the closest number from left to right in the array
def find_nearby_num(arr, target):
    # store the distance of the target and element
    distance = [0 for i in range(len(arr))]
    shotest = 0

    # calculate the distance and found the closest
    for i in range(len(arr)):
        distance[i] = abs(arr[i] - target)

        # find the closest element value
        if i == 0:
            shortest = distance[i]
        elif distance[i] < distance[i-1]:
            shortest = distance[i]

    # use index to find the number in original array
    return arr[distance.index(shortest)]


# input array
arr = [float(item) for item in input('Enter the list items : ').split()]

print('There is an array: ', arr, '\n')

# search loop
while True:
    target = float(input('Enter a target number: '))

    print('Output: ', find_nearby_num(arr, target))

    print('---------------------------------------------')
