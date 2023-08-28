#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int rank, size, fact, sum, prod, count = 1;
    MPI_Init(&argc, &argv);
    MPI_Errhandler_set(MPI_COMM_WORLD, MPI_ERRORS_RETURN);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    prod = rank+1;
    MPI_Scan(&prod, &fact, count, MPI_INT, MPI_PROD,MPI_COMM_WORLD);
    MPI_Reduce(&fact,&sum,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
    if(rank==0){
        printf("Sum of all factorial = %d", sum);
    } 
    MPI_Finalize();
    return 0;
}