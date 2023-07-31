#include<mpi.h>
#include<stdio.h>
#include<math.h>

int main(int argc, char *argv[])
{
    int x = 10, y = 20;
    int rank;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if(rank==0){
        printf("Rank: %d, Sum = %d\n",rank, x+y);
    } else if(rank == 1 ){
        printf("Rank: %d, Diff = %d\n",rank, x-y);
    } else if(rank == 2 ){
        printf("Rank: %d, Product = %d\n",rank, x*y);
    } else if(rank == 3){
        printf("Rank: %d, Quoatient = %d\n",rank, x/y);
    } else if(rank == 4 ){
        printf("Rank: %d, Remainder = %d\n",rank, x%y);
    }
    MPI_Finalize();
    return 0;
}
