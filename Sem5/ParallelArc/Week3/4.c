#include<mpi.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int rank, size, N, A[10], chunk,j,l;
    char c1[10];
    char c2[10];
    char str[20];
    char str3[20];
    char B[20];
    char str2[20];
    int nv = 0;
    int ll = 0;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    if(rank == 0) {
        N = size;
        fprintf(stdout, "Enter string 1:\n");
        fflush(stdout);
        scanf("%s", str);
        fprintf(stdout, "Enter string 2:\n");
        fflush(stdout);
        scanf("%s", str2);
        fprintf(stdout, "Entered string: %s\n", str);
        fflush(stdout);
        fprintf(stdout, "Entered string2: %s\n", str2);
        fflush(stdout);
        chunk = strlen(str)/N;
    }
    MPI_Bcast(&chunk,1, MPI_INT,0,MPI_COMM_WORLD);
    for(int i=0; i<chunk;i++){
        MPI_Scatter(str,1,MPI_CHAR,c1,1,MPI_CHAR,0,MPI_COMM_WORLD);
        MPI_Scatter(str2,1,MPI_CHAR,c2,1,MPI_CHAR,0,MPI_COMM_WORLD);
    }
    
    
    fprintf(stdout, "I have recieved %s in process %d\n", c1, rank);
    fflush(stdout);
    fprintf(stdout, "I have recieved %s in process %d\n", c2, rank);
    fflush(stdout);

    str3[ll] = *c1;
    str3[ll+1] = *c2;
    ll+=2;
    fprintf(stdout, "I have made %s in process %d\n", str3, rank);
    fflush(stdout);
    l = strlen(str3);
    MPI_Gather(str3, l, MPI_INT, B, l, MPI_CHAR, 0, MPI_COMM_WORLD);

    if(rank==0){
    fprintf(stdout,"\nThe sum gathered in the root: %s\n", B);
    fflush(stdout);
    }

    MPI_Finalize();
    return 0;
}
