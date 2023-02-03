import math

def bubbleSort(arr):
    n = len(arr)
 
    # Traverse through all array elements
    for i in range(n):
 
        # Last i elements are already in place
        for j in range(0, n-i-1):
 
            # traverse the array from 0 to n-i-1
            # Swap if the element found is greater
            # than the next element
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]


# x = [[1,2],[3,4],[5,6]]
# y = [[4,5],[7,1],[9,5]]
# z= []
# for i in range(0,3):
#     z.append(math.dist(x[i], y[i]))

x = [1,2,3,4,5]
y = [4,7,3,5,1]
z= []
for i in range(0,5):
    z.append((y[i]-x[i]))

bubbleSort(z)
 
print("Sorted array is:")
for i in range(len(z)):
    print("%d" % z[i], end=" ")
