#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
/* Take a buffer size 12 to allot 10 storage space to values and 2 shared memory to in and out. */
#define BUFFER_SIZE 12

int main () {

 	int fd;
 	int *bptr;
	

	
 	/* Open the Shared Buffer for reading / writing by Consumer */
    /* we also have to give writing access to the consumer so that the consumer can update the values of in and out. */
 	fd = shm_open("/myBuffer", O_RDWR, 0666);

 	if (fd == -1)
  	 {  
		/* Handle error */;
  		printf("No Shared Buffer Exists\n");
   		return -1;
   	 }

  	/* Map shared memory object to process’ address space */
    /* we also have to give writing access to the consumer so that the consumer can update the values of in and out. */
  	bptr = mmap(NULL, sizeof(int)*BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  	if (bptr == MAP_FAILED)
    	{
      		printf("Error in mapping Shared Buffer\n");
      		return -1;
    	}
    
    /* initialise in and out pointers to the address of the last spaces of the shared buffer. */
	int *in = &bptr[BUFFER_SIZE-1], *out = &bptr[BUFFER_SIZE-2];
    
	while(1)
	{
        /* when in and out points to same address space then the producer wants to write to the same space from where consumer wants to read, in that case the consumer can't read anything from that space and therefore has to wait and do nothing. */
		while(*in == *out)
		{
			
		}
        
        /* otherwise, the consumer reads from the space and increments the value of out. */
		printf("Consumer with PID: %d reading %d from %dth slot.\n",getpid(), bptr[*out], *out);
		*out = (*out+1) % (BUFFER_SIZE-2);
	}
  	shm_unlink("/myBuffer");
  	return 0;
}
