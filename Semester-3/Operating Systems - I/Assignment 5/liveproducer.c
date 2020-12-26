#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
/* Take a buffer size 12 to allot 10 storage space to values and 2 shared memory to in and out. */
#define BUFFER_SIZE 12

int main () 
{

 	int fd;
  	int *bptr;
 	int value;
	
 	/* Create shared memory object and set its size */
  	fd = shm_open("/myBuffer", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);

 	 if (fd == -1)
  	 {  
		/* Handle error */;
  	  	printf("Error in creating Shared Buffer\n");
  	 	return -1;
   	 }
	
 	 if (ftruncate(fd, sizeof(int)*BUFFER_SIZE) == -1) //set Size
   	 {
     	 	printf("Errror in setting the size of Shared Buffer\n"); /* Handle error */
      		return -1;
    	 }

 	/* Map shared memory object to process’ address space */
 	 bptr = mmap(NULL, sizeof(int)*BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
 	 if (bptr == MAP_FAILED)
  	 {
    	  	printf("Error in mapping Shared Buffer\n");
    	  	return -1;
   	 }
    
  /* initialise in and out pointers to the address of the last spaces of the shared buffer. */
	int *in = &bptr[BUFFER_SIZE-1], *out = &bptr[BUFFER_SIZE-2];
    
	/* Now we can refer to mapped region using fields of bptr */
  	while(1)
	{
        /* when in points to a space where there is already a value present and the consumer hasn't consumed it yet, then the producer can't produce at such a place and therefore has to wait and do nothing. */
		while((*in+1) % (BUFFER_SIZE-2) == *out)
		{	

		}
        
        /* Otherwise, the console asks the user for input and store the value in shared memory. */
		printf("Enter the value to write in the buffer: ");
		scanf("%d",&value);
		bptr[*in] = value;
		/* Test that writing is successful */
		printf("Producer with PID: %d writing %d to the %dth slot of the Buffer.\n",getpid(), bptr[*in], *in);
		/* increment in */
		*in = (*in+1)%(BUFFER_SIZE-2);
	}
  	shm_unlink("/myBuffer");
  	return 0;
}
