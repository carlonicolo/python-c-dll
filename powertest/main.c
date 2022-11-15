#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef void (*powArr)(int*, int*, int, int);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
    HINSTANCE powDLL;
    powDLL = LoadLibrary("power.dll");
    const int SZ = 5;
    int lArray[] = {1,2,3,4,5};
    int result[SZ];
    
    if(powDLL != 0){
              //use the typedef
              powArr power;
              
              // obtain the powArr function from the DLL,
              // and cast it to the typedef
              power = (powArr) GetProcAddress(powDLL, "powArr");
              // call the function powArr provided by the DLL
              power(lArray, result, SZ, 2);
              int i=0;
              for (i=0; i < SZ; i++) {
                  printf("result[%d] = %d\n", i, result[i]);
                  }
              FreeLibrary(powDLL);
    }else {
          printf("pow dll not loaded: %d \n", GetLastError());          
    }
  
  system("PAUSE");	
  return 0;
}