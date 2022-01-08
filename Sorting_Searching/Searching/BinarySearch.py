n1 = int(input())
lista = []
for i in range(n1):
    x = int(input())
    lista.append(x)

lista.sort()

N1 = int(input())


def BinarySearch(list1, x):
    l = 0
    r = len(list1)
    while(l <= r):
        mid = int(l + (r-l)/2)
        if(list1[mid] == x):
            print("Found")
            return mid
        elif(list1[mid] < x):
            l = mid + 1
        else:
            r = mid - 1
    return -1
                
                
print(BinarySearch(lista, N1))  