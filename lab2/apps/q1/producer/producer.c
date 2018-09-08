#include "lab2-api.h"
#include "usertraps.h"
#include "misc.h"

#include "q1.h"

void main (int argc, char *argv[])
{
  	shared_mem * smem;       
  	uint32 h_mem;            // Handle to the shared memory page
  	sem_t s_procs_completed; // Semaphore to signal the original process that we're done
	int i;
	char hello[12] = "Hello World";		
	int next;

  	if (argc != 3) { 
    	Printf("Usage: "); Printf(argv[0]); Printf(" <handle_to_shared_memory_page> <handle_to_page_mapped_semaphore>\n"); 
    	Exit();
  	} 

  	// Convert the command-line strings into integers for use as handles
  	h_mem = dstrtol(argv[1], NULL, 10);
  	s_procs_completed = dstrtol(argv[2], NULL, 10);

 	// Map shared memory page into this process's memory space
  	if ((smem = (shared_mem *)shmat(h_mem)) == NULL) {
    	Printf("Could not map the virtual address to the memory in "); 
		Printf(argv[0]); 
		Printf(", exiting...\n");
    	Exit();
 	}
 
  	// Now print a message to show that everything worked
  	Printf("producer: This is one of the %d instances you created.  ", smem->numprocs);
  	
  	Printf("producer: My PID is %d\n", Getpid());

	// add 12 chars to circular buffer here
	

	/*if((smem->head + 1) % (smem->maxbuf) == (smem->tail))
	{
		sem_wait(s_procs_completed);
	}*/

	for (i=0; i<12; i++)
	{
		next = (smem->head)+1;
		if (next >= smem->maxbuf)
		{
			next = 0;
			smem->head = next;
		}

		smem->buffer[smem->head] = hello[i];
		smem->head = next;
		//Printf("work!");
		Printf("Producer %d inserted: %c\n",(Getpid(), smem->buffer[smem->head]));
	}

  	// Signal the semaphore to tell the original process that we're done
  	Printf("producer: PID %d is complete.\n", Getpid());
  
  	if(sem_signal(s_procs_completed) != SYNC_SUCCESS) 
	{
	    	Printf("Bad semaphore s_procs_completed (%d) in ", s_procs_completed); 
		Printf(argv[0]); 
		Printf(", exiting...\n");
	    	Exit();
  	}
}
