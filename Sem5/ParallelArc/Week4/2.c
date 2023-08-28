#include <stdio.h>
#include <mpi.h>

double f(double x){
    return (4.0 / 1.0+( x*x));
}

int main(int argc, char *argv[])
{
    int rank, size, n=0, done = 0;
    double h, x, y, pi, sum = 0,P;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(my, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    while(!done){
        if(rank==0){
            if(n==0) n=1000;
            else n = 0;
        }
        MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
        if (n == 0)
            done = 1;
        else{
            h = 1.0 / (double)n;
    for (int i = rank+1; i <=n; i+= size)
    {
        x = h * ((double)i - 0.5);
        sum += f(x);
    }
    pi = h*sum;
    MPI_Reduce(&pi, &P, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
        }
    }
    
    
    // MPI_Scan(&prod, &fact, count, MPI_INT, MPI_PROD,MPI_COMM_WORLD);
    // MPI_Reduce(&fact,&sum,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
    if(rank==0){
        printf("Sum of all factorial = %f", P);
    } 
    MPI_Finalize();
    return 0;
}