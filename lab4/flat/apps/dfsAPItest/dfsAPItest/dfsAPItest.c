#include "usertraps.h"
#include "misc.h"
#include "files_shared.h"

void main (int argc, char *argv[])
{
    // Variable declarations
    int handle, i;
    char fname[] = "astpier";
    char wbuff[19] =  "ECE595: Intro to OS";
    char rbuff[19];

    Printf("");
    Printf("\n\n"); 
    Printf("============================================================\n"); 
    Printf(" dfsAPItest.c (PID: %d): Q6, user program to test DFS API\n", getpid()); 
    Printf("============================================================\n"); 

    // 1. Lets create a file, "andrewsFile"
    Printf("  Opening file \"andrewsFile\"... file_open(\"andrewsFile\", \"w\")\n"); 
    handle = file_open("astpier","w");
    //if(handle == FILE_FAIL) Printf(" dfsAPItest.c : FILE CREATION FAILED \n");

    // 2. Write "testStr" to this file
    Printf("  Writing to file \"andrewsFile\"... file_write(handle, testSt, dstrlen(testStr))\n");
    //if(file_write(handle,wbuff,19) != 19) Printf(" dfsAPItest.c : FILE WRITING FAILED\n");
    file_write(handle,wbuff,19);
    // 3. Close the file
    Printf("  Closing file \"andrewsFile\"... file_close(handle)\n");
    //if(file_close(handle) == FILE_FAIL) Printf(" dfsAPItest.c : FILE CLOSING FAILED\n");
    file_close(handle);
    
    // 4. Re-open the file, "andrewsFile"
    Printf("  RE-opening file \"andrewsFile\"... file_open(\"andrewsFile\", \"r\")\n"); 
    handle = file_open(fname, "r");
    //if(handle == FILE_FAIL) Printf(" dfsAPItest.c : FILE OPENING FAILED \n");
 
    // 5. Read strlen(testStr) bytes from file (should match testStr)
    Printf("  Reading from file \"andrewsFile\"... file_read(handle, buff, dstrlen(testStr))\n");
    //if(file_read(handle,buff,dstrlen(testStr)) != dstrlen(testStr)) Printf(" dfsAPItest.c : FILE READING FAILED\n");
    file_read(handle,rbuff,19);
    Printf("   Read from file:  ");
    for(i=0; i<19; i++) Printf("%c",rbuff[i]);
    Printf("\n");
    
    Printf("\n\n"); 
    Printf("============================================================\n"); 
    Printf(" dfsAPItest.c (PID: %d): DFS API test complete, process ending...\n", getpid()); 
    Printf("============================================================\n"); 
}
