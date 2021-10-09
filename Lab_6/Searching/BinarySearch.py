n1 = int(input())
lista = []
for i in range(n):
    x = int(input())
    lista[i].append(x)

lista.sort()

N1 = int(input())


flag2 = 0


def BinarySearch(n,N,list1,flag):
    flag1 = 0
    if(n==1 and N!=list1[0]):
        print("not found")
        flag1 = 1
    if(flag==0):
        if(n%2!=0):
            if(N==list1[((n+1)/2)-1]):
                print("found")
                flag = flag+1
                print(flag)
                flag1 = 1
            elif(N<list1[((n+1)/2)-1]):
                for i in range(list1[0]+((n+1)/2)), list1[n]): 
                    list1.remove(i)
                n = len(list1)
                flag = flag + 1
                BinarySearch(n,N,list1,flag)
            elif(N>list1[((n+1)/2)-1]):
                for i in range(list1[0],list1[0]+((n-1)/2)):
                    list1.remove(i)
                n = len(list1)
                flag = flag + 1
                BinarySearch(n,N,list1,flag)
    else:
        if(N==list1[(n/2)]):
            print("found")
            flag = flag+1
            print(flag)
            flag1 = 1
        elif(N<list1[(n/2)+1]):
            for i in range(list1[0]+(n/2),list1[n]:
                list1.remove(i)
            n = len(list1)
            flag = flag + 1
            BinarySearch(n,N,list1,flag)
        elif(N>list1[(n/2)+1]):
            for i in range(list1[0],list1[0]+(n/2):
                list1.remove(i)
            n = len(list1)
            flag = flag + 1
            BinarySearch(n,N,list1,flag)
                
                
BinarySearch(n1, N1, lista, flag2)    