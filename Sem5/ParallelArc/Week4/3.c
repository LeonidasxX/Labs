#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int rank, size, a[3][3], b[3], sum=0, finalCount=0, find;
    MPI_Init(&argc, &argv);
    
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    if(rank==0){
        fprintf(stdout, "Enter the matrix:\n");
        fflush(stdout);
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                scanf("%d", &a[i][j]);
            }
        }
        fprintf(stdout, "Enter matrix is:\n");
        fflush(stdout);
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                fprintf(stdout, "%d\t", a[i][j]);
                fflush(stdout);
            }
        }
        fprintf(stdout, "Enter the element to search for: ");
        fflush(stdout);
        scanf("%d", &find);
    }

    MPI_Bcast(&find,1,MPI_INT,0,MPI_COMM_WORLD);
    MPI_Scatter(a, 3, MPI_INT, b, 3, MPI_INT, 0, MPI_COMM_WORLD);

    // for (int i = 0; i < 3; i++)
    // {
    //     for(int j=0;j<3;j++){
    //         if(a[i][j] == find){
    //             sum += 1;
    //         }
    //     }
    // }
    for (int i = 0; i < 3; i++)
    {
            if(b[i] == find){
                sum += 1;
            }
    }
    
    MPI_Reduce(&sum,&finalCount,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
    if(rank==0){
        fprintf(stdout, "Total Count: %d\n", finalCount);
        fflush(stdout);
    } 
    MPI_Finalize();
    return 0;
}