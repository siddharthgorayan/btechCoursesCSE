/*
 * Program: Speedup calculation of matrix multiplication with
 *          multi-processing and multi-threading.
 * Author:  Ananya Mantravadi & Siddharth Saini
 * Roll# :  CS19B1004 & CS19B1024
 */
 
#include <stdlib.h> /* for exit, atoi */
#include <stdio.h>  /* for fprintf */
#include <errno.h>  /* for error code eg. E2BIG */
#include <getopt.h> /* for getopt */
#include <assert.h> /* for assert */
#include <pthread.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/shm.h>
#include <stdbool.h>
#include <sys/wait.h>

/*
 * Forward declarations
 */
 
void usage(int argc, char *argv[]);
void input_matrix(int *mat, int nrows, int ncols);
void output_matrix(int *mat, int nrows, int ncols);
void init_matrix(int *mat, int rows, int cols);
unsigned long long multi_thread_mm(void);
unsigned long long single_thread_mm(void);
unsigned long long multi_process_mm(void);
void *threadPortion(void* arg);
 
int *A, *B, *C;
int crows, ccols;
int arows, acols, brows, bcols;
char interactive = 0;
 
int main(int argc, char *argv[])
{
    int c, i;
 
 
    /* Loop through each option (and its's arguments) and populate variables */
    while (1) {
        int this_option_optind = optind ? optind : 1;
        int option_index = 0;
        static struct option long_options[] = {
            {"help",    no_argument,        0, 'h'},
            {"ar",        required_argument,    0, '1'},
            {"ac",        required_argument,    0, '2'},
            {"br",        required_argument,    0, '3'},
            {"bc",        required_argument,    0, '4'},
            {"interactive",    no_argument,         0, '5'},
            {0,        0,            0,  0 }
        };
 
        c = getopt_long(argc, argv, "h1:2:3:4:5", long_options, &option_index);
        if (c == -1)
            break;
 
        switch (c) {
        case 0:
            fprintf(stdout, "option %s", long_options[option_index].name);
            if (optarg)
                fprintf(stdout, " with arg %s", optarg);
                fprintf(stdout, "\n");
            break;
 
        case '1':
            arows = atoi(optarg);
            break;
 
        case '2':
            acols = atoi(optarg);
            break;
 
        case '3':
            brows = atoi(optarg);
            break;
 
        case '4':
            bcols = atoi(optarg);
            break;
 
        case '5':
            interactive = 1;
            break;
 
        case 'h':
        case '?':
            usage(argc, argv);
 
        default:
            fprintf(stdout, "?? getopt returned character code 0%o ??\n", c);
            usage(argc, argv);
        }
    }
 
    if (optind != argc) {
        fprintf(stderr, "Unexpected arguments\n");
        usage(argc, argv);
    }
 
    if(acols!=brows) {
        fprintf(stderr, "Matrix multiplication not feasible\n");
        exit(EXIT_FAILURE);
    }
 
    unsigned long long time_single, time_multi_process, time_multi_thread;
    /* Add your code here */
   
    crows = arows;
    ccols = bcols;
    A = (int*)malloc((arows*acols)*sizeof(int));
    B = (int*)malloc((brows*bcols)*sizeof(int));
    C = (int*)malloc((arows*bcols)*sizeof(int));
    
    /* initialising the reusltant array to zero. */
    for(i=0; i<arows*bcols; i++)
    {
        *(C+(i)) = 0;
    }
 
    time_single = single_thread_mm();
     
    /* initialising the reusltant array to zero, as it contains the output after single_thread mm. */
    for(i=0; i<arows*bcols; i++)
    {
        *(C+(i)) = 0;
    }
    
    time_multi_thread = multi_thread_mm();
    
    /* initialising the reusltant array to zero, as it contains the output after multi thread mm. */
    for(i=0; i<arows*bcols; i++)
    {
        *(C+(i)) = 0;
    }
    
    time_multi_process = multi_process_mm();
 
    /* TODO */
 
    fprintf(stdout, "Time taken for single threaded: %llu us\n",
            time_single);
    fprintf(stdout, "Time taken for multi process: %llu us\n",
            time_multi_process);
    fprintf(stdout, "Time taken for multi threaded: %llu us\n",
            time_multi_thread);
    fprintf(stdout, "Speedup for multi process : %4.2f x\n",
            (double)time_single/time_multi_process);
    fprintf(stdout, "Speedup for multi threaded : %4.2f x\n",
            (double)time_single/time_multi_thread);
    exit(EXIT_SUCCESS);
}
 
/*
 * Show usage of the program
 */
void usage(int argc, char *argv[])
{
    fprintf(stderr, "Usage:\n");
    fprintf(stderr, "%s --ar <rows_in_A>  --ac <cols_in_A>"
            " --br <rows_in_B>  --bc <cols_in_B>"
            " [--interactive]",
            argv[0]);
    exit(EXIT_FAILURE);
}
 
/*
 * Input a given 2D matrix
 */
void input_matrix(int *mat, int rows, int cols)
{
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            fscanf(stdin, "%d", mat+(i*cols+j));
        }
    }
}
 
/*
 * Output a given 2D matrix
 */
void output_matrix(int *mat, int rows, int cols)
{
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            fprintf(stdout, "%d ", *(mat+(i*cols+j)));
        }
        fprintf(stdout, "\n");
    }
}
 
void init_matrix(int *mat, int rows, int cols)
{
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            *(mat+(i*cols+j)) = rand() % 100;
        }
    }
}
 
/* Matrix Multiplication using Single Thread. */
unsigned long long single_thread_mm()
{
    /* if interactive isn't chosen, we take input from random number generator. */
    if(interactive == 0)
    {
    init_matrix( A,  arows,  acols);
    init_matrix( B,  brows,  bcols);
    }
    
    /* if interactive is chosen, we ask the user to input. */
    else
    {
    fprintf(stdout, "Enter A:\n");
    input_matrix(A, arows, acols);
    fprintf(stdout, "Enter B:\n");
    input_matrix(B, brows, bcols);
    }
    
    /* note the time when computation begins. */
    clock_t begin = clock();

    for(int i=0; i<arows; i++)
    {
        for(int j=0; j<bcols; j++)
        {
            for(int k=0; k<acols; k++)
            {
                *(C + (bcols)*i + j) += *(A + (acols)*i + k) * (*(B + (bcols)*k + j));
            }
        }
    }

    /* note the time when computation ends. */
    clock_t end = clock();
    clock_t clockTimeSpent = end - begin;
    unsigned long long time_spent = 1000000*((double)clockTimeSpent/(unsigned long long)CLOCKS_PER_SEC);

    /* if interactive is selected, we also print the output of resultant matrix. */
    if(interactive == 1)
    {
    fprintf(stdout, "Result:\n");
    output_matrix(C, crows, ccols);
    }
    
    return time_spent;
}

/* Funtion to compute each row in the resultant matrix using threads.*/
void *threadPortion(void* arg)
{
    int* dataForThread = (int*) arg;
    int i, j;
    int k = *dataForThread;
    
    for(i=0; i<bcols; i++)
    {
        for(j=0; j<acols; j++)
        {
           *(C+k*bcols+i) += *(A+k*acols+j) * (*(B+j*bcols+i));
        }
    }
    pthread_exit(NULL);
}
  
/* Matrix Multiplication using Multi-Thread. */
unsigned long long multi_thread_mm()
{
    /* if interactive isn't chosen, we take input from random number generator. */
    if(interactive == 0)
    {
    init_matrix( A,  arows,  acols);
    init_matrix( B,  brows,  bcols);
    }
    
    /* if interactive is chosen, we ask the user to input. */
    else
    {
    fprintf(stdout, "Enter A:\n");
    input_matrix(A, arows, acols);
    fprintf(stdout, "Enter B:\n");
    input_matrix(B, brows, bcols);
    }

    int i;
 
    /* we create threads equal to the number of rows in matrix A. */
    pthread_t* threads;
    threads = (pthread_t*)malloc(arows*sizeof(pthread_t));
    
    /* we initialise an array to store the data to be transfered to each thread everytime for computation. */
    int* dataForThread[arows];
    
    /* creating threads and passing the data for computation of one row at a time. */
    for(i=0; i<arows; i++)
    {
        dataForThread[i] = (int*)malloc(sizeof(int));
        *dataForThread[i] = i;
        pthread_create(&threads[i], NULL, threadPortion, (void*)(dataForThread[i]));
    }

    /* note the time when computation begins. */
    clock_t begin = clock();
    
    for(i=0; i<arows; i++)
    {
        pthread_join(threads[i], NULL);
    }
    
    /* note the time when computation ends. */
    clock_t end = clock();
    clock_t clockTimeSpent = end - begin;
    unsigned long long time_spent = 1000000*((double)clockTimeSpent/(unsigned long long)CLOCKS_PER_SEC);
    
    /* if interactive is selected, we also print the output of resultant matrix. */
    if(interactive == 1)
    {
    fprintf(stdout, "Result:\n");
    output_matrix(C, crows, ccols);
    }
    
    return time_spent;
}
 
unsigned long long multi_process_mm()
{
    int i, j, k, startRow, endRow, noOfProcesses = arows;
    clock_t begin, end, clockTimeSpent;
    unsigned long long time_spent;
    pid_t pid;
    
    /* creating a shared memory segment and allocating it a space equal to the size of Matrix A, Matrix B, Matrix C. */
    int segmentID = shmget(IPC_PRIVATE, sizeof(int)*((arows*acols)+(brows*bcols)+(arows*bcols)), IPC_CREAT|0666);
    
    /* passing the shared memory to the partition to compute a partition at a time. */
    int* partition = (int*)shmat(segmentID, NULL, 0);
    
     /* if interactive isn't chosen, we take input from random number generator. */
    if(interactive == 0)
    {
    init_matrix( A,  arows,  acols);
    init_matrix( B,  brows,  bcols);
    }
    
     /* if interactive is chosen, we ask the user to input. */
    else
    {
    fprintf(stdout, "Enter A:\n");
    input_matrix(A, arows, acols);
    fprintf(stdout, "Enter B:\n");
    input_matrix(B, brows, bcols);
    }
    
    /* we fork() the process equal to the number of times of the rows. */
    for(i=0; i<noOfProcesses; i++)
    {
        /* we fork a new process only when it's a parent process. */
        if(pid != 0)
        {
            pid = fork();
        }
    }
    
    /* child process: computes each row at a time in every child process. */
    if(pid == 0)
    {
        /* initialise the row from where we need to start computation and row where we need to end. */
        startRow = (*partition * arows)/noOfProcesses;
        endRow = ((*partition+1)*arows)/noOfProcesses;
        
        /* note the time when computation begins. */
        begin = clock();
        
        for(i = startRow; i<=endRow; i++ )
        {
            for(j=0; j<bcols; j++)
            {
                for(k=0; k<acols; k++)
                {
                    *(C + (bcols)*i + j) += *(A + (acols)*i + k) * (*(B + (bcols)*k + j));
                }
            }
        }
        
        /* notes the time when computation ends. */
        end = clock();
        clockTimeSpent = end - begin;
        time_spent = 1000000*((double)clockTimeSpent/(unsigned long long)CLOCKS_PER_SEC);
    }
    

    /* parent process: */
    else
    {
        /* waits for all the child processes to execute first. */
        wait(NULL);
    }
    
    if(interactive == 1)
    {
    fprintf(stdout, "Result:\n");
    output_matrix(C, crows, ccols);
    }
    
    return time_spent;
}
 

