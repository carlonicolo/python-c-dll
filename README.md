# Using C DLL in Python

In this simple toy project i have created a C dll in DEV++ that compute the power of elements contained into an array.

This approach could be very uself to speed up some tasks in python taking advance of C language.  

```python
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
```

You can see the **power.dll** inside the folder /powerDLL and check how it works. 