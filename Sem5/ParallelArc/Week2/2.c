#include<mpi.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int rank, size, x;
    char c[5] = "hello";
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Status status;
    if(rank==0){
        fprintf(stdout,"This is the master process...\n");
        fflush(stdout);
        MPI_Ssend(&c,strlen(c),MPI_CHAR,1,1,MPI_COMM_WORLD);
        fprintf(stdout,"I have sent %s from process 0\n",c);
        MPI_Recv(&c,strlen(c),MPI_CHAR,1,1,MPI_COMM_WORLD,&status);
        fprintf(stdout,"I have received %s in process %d\n",c, rank);
        fflush(stdout);
        
    }
    else{
        MPI_Recv(&c,strlen(c),MPI_CHAR,0,1,MPI_COMM_WORLD,&status);
        fprintf(stdout,"I have received %s in process %d\n",c, rank);
        for (int i = 0; i < strlen(c); i++)
        {
            c[i] = c[i] - 32;
        }
        
        MPI_Ssend(&c,strlen(c),MPI_CHAR,0,1,MPI_COMM_WORLD);
        fflush(stdout); 
    }
    MPI_Finalize();
    return 0;
}