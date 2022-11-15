import ctypes

dll = ctypes.CDLL("./power.dll")

length = 5

FiveIntegers = ctypes.c_int * length
numArray = FiveIntegers(1,2,3,4,5)

for i in numArray: print(i, end=" ")
print()
resArray = FiveIntegers()

dll.powArr(numArray, resArray, length, 3)
for i in resArray: print(i, end=" ")