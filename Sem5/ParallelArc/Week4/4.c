// colsum 2nd method
#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int rank, size, a[4][4], b[4], sum=0, finalCount=0, find, colSum[4];
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    if(rank==0){
        fprintf(stdout, "Enter the matrix:\n");
        fflush(stdout);
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                scanf("%d", &a[i][j]);
            }
        }
        fprintf(stdout, "Enter matrix is:\n");
        fflush(stdout);
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                fprintf(stdout, "%d\t", a[i][j]);
                fflush(stdout);
            }
            fprintf(stdout, "\n");
            fflush(stdout);
        }
    }

    MPI_Scatter(&a, 4, MPI_INT, &b, 4, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scan(&b, &colSum, 4, MPI_INT, MPI_SUM,MPI_COMM_WORLD);
    MPI_Gather(&colSum, 4, MPI_INT, &a[rank], 4, MPI_INT, 0, MPI_COMM_WORLD);
    
    
    
    if(rank==0){
        fprintf(stdout, "Enter matrix is:\n");
        fflush(stdout);
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                fprintf(stdout, "%d\t", a[i][j]);
                fflush(stdout);
            }
            fprintf(stdout, "\n");
            fflush(stdout);
        }
        
    } 
    MPI_Finalize();
    return 0;
}