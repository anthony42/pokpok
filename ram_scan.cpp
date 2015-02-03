#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <limits>      // new line
using namespace std;

/* Premier code de test */
/*********************************************************************/
/*********************************************************************/
/*********************************************************************/

int Memory(int long Address, int Value, bool _w, DWORD av_pid)
{
   DWORD PROC_ID;
   HANDLE PROC_HANDLE;

   // GetWindowThreadProcessId(MyWindow, &PROC_ID);
   PROC_HANDLE = OpenProcess(PROCESS_ALL_ACCESS, false, av_pid);
    if (PROC_HANDLE == NULL){
        std::cout << ("PID not found");
   }
   if(_w)
      WriteProcessMemory(PROC_HANDLE, (LPVOID)Address, &Value, sizeof(long int), NULL);
   else{
      ReadProcessMemory(PROC_HANDLE, (LPVOID)Address, &Value, sizeof(long int), NULL);
        // for (int i = 0; i < sizeof(long int); ++i)
        // {
            printf("%d ", Value);
        // }
    }
   CloseHandle(PROC_HANDLE);
   return Value;
}

int main(int ac, char **av)
{
   SetConsoleTitle("Memory Search");
   register unsigned long long int x;   // registering the most used variables
   /*** maximizing the case ***/
   LPVOID MyLPVOID;
   
   // char Caption[1000] = "anthonyninihihi";
//   cout << "Enter the caption of the window: ";
//   cin.getline(Caption, 1000);
   // HWND Test = FindWindow(NULL, Caption);
   // if (!Test){
   //    cout << "\nCannot find window \"" << Caption << "\"!"<<endl;
   //    system("pause");
   //    return 1;
   // }
   LPVOID Address = (void*)0x00010000;
//   cout << "\nEnter the address to start at: ";
//   cin >> Address;

   register unsigned long long int Limit = ((numeric_limits<unsigned long long int>::max())/2)-((long int)Address+1);
      /*** IMPORTANT ***/
   
   int WhatToFind = 10;
   // cout << "\nWhat number are you trying to find: ";
   // cin >> WhatToFind;
   
   for (x=0;x<Limit; x++){   // and now this
      int AtAddress = Memory( ((long int)Address + x), 0, false, atoi(av[1]));
      if (AtAddress == WhatToFind){
         cout << "\n\nFound it at address: " << (LPVOID)((long int)Address + x);
         break;  // when found !
      }
   }
   cout << endl;
   system("pause");
   return 0;
}


/*********************************************************************/
/*********************************************************************/
/*********************************************************************/



/* Deuxieme code de test */
/*********************************************************************/
/*********************************************************************/
/*********************************************************************/

 
// VOID DumpBuffer(const unsigned char* pBuffer, size_t sz)
// {
//     for (size_t i = 0; i < sz; ++i)
//         if (pBuffer[i])
//             printf("%c ", pBuffer[i]);
// }
 
// BOOL DumpProcessMemory(DWORD dwPid)
// {
//     HANDLE pHandle;
//     SYSTEM_INFO si; 
//     MEMORY_BASIC_INFORMATION mbi;
//     LPVOID lpMem;
//     DWORD dwReturn, dwTotalRead;
 
//     pHandle = OpenProcess(PROCESS_ALL_ACCESS, 0, dwPid);
//     if (pHandle == NULL)
//     {
//         printf("OpenProcess failed for PID: %d\n",dwPid); 
//         return FALSE;
//     }
//     GetSystemInfo(&si);
//     lpMem = si.lpMinimumApplicationAddress;
//     while (lpMem < si.lpMaximumApplicationAddress)
//     {
//         mbi.RegionSize = 0;
//         dwReturn = VirtualQueryEx(pHandle, lpMem, &mbi, sizeof(mbi));
//         if (dwReturn == sizeof(mbi)) {
//             if ((mbi.Type == MEM_PRIVATE) && (mbi.State == MEM_COMMIT))
//             { 
//                 if (mbi.RegionSize > 0)
//                 {
//                     const BYTE* cbBuffer = (BYTE*)HeapAlloc(GetProcessHeap(), NULL, mbi.RegionSize);
//                     if (cbBuffer == NULL) 
//                     {
//                         printf ("HeapAlloc failed\n");
//                         return FALSE;
//                     }
//                     ReadProcessMemory(pHandle, mbi.BaseAddress, (LPVOID)cbBuffer, mbi.RegionSize, &dwTotalRead);
//                     DumpBuffer(cbBuffer, mbi.RegionSize);
//                     HeapFree(GetProcessHeap(), NULL, (LPVOID)cbBuffer);
//                 } 
//             } 
//             lpMem = (LPVOID)((DWORD)mbi.BaseAddress + mbi.RegionSize);
//         } 
//         else break;
//     }
//     CloseHandle(pHandle);
//     return TRUE;
// }
 
// INT main(INT argc, CHAR **argv)
// {
//     DumpProcessMemory(atoi(argv[1]));
//     return 0;
// }

