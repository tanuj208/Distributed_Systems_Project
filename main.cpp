/* MPI Program Template */

#include "headers.h"

int main( int argc, char **argv ) {
    int rank, numprocs;

    /* start up MPI */
    MPI_Init( &argc, &argv );

    MPI_Comm_rank( MPI_COMM_WORLD, &rank );
    MPI_Comm_size( MPI_COMM_WORLD, &numprocs );
    
    /*synchronize all processes*/
    MPI_Barrier( MPI_COMM_WORLD );
    double tbeg = MPI_Wtime();

    /* write your code here */
    
    int x;
    if(rank == root_process)
    {
        cout<<"Enter index of random number generator you want to use\n";
        cout<<"0. LCG Parallel - Idea 1\n";
        cout<<"1. LCG Parallel - Idea 2\n";
        cout<<"2. LCG Parallel - Idea 3\n";
        cout<<"3. Ecuyer’s Multiple Recursive Generator\n";
        cin>>x;
        MPI_Bcast(&x, 1, MPI_INT, root_process, MPI_COMM_WORLD);
    }
    else
    {
        MPI_Bcast(&x, 1, MPI_INT, root_process, MPI_COMM_WORLD);
    }
    MPI_Barrier( MPI_COMM_WORLD );

    function < vector<long long> (int, int) > generate_random_numbers;

    if(x == 0)
    {
        LCG_Parallel1 rcg(numprocs);
        generate_random_numbers = bind(&LCG_Parallel1::generate_random_numbers, rcg, _1, _2);
    }
    else if(x == 1)
    {
        LCG_Parallel2 rcg(numprocs);
        generate_random_numbers = bind(&LCG_Parallel2::generate_random_numbers, rcg, _1, _2);
    }
    else if(x == 2)
    {
        LCG_Parallel3 rcg(numprocs);
        generate_random_numbers = bind(&LCG_Parallel3::generate_random_numbers, rcg, _1, _2);
    }
    else if(x == 3)
    {
        Ecuyer rcg(numprocs);
        generate_random_numbers = bind(&Ecuyer::generate_random_numbers, rcg, _1, _2);
    }

    Monte_Carlo m(numprocs, generate_random_numbers);
    cout<<m.generate_pi()<<endl;

    MPI_Barrier( MPI_COMM_WORLD );
    double elapsedTime = MPI_Wtime() - tbeg;
    double maxTime;
    MPI_Reduce( &elapsedTime, &maxTime, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD );
    if ( rank == 0 ) {
        printf( "Total time (s): %f\n", maxTime );
    }

    /* shut down MPI */
    MPI_Finalize();
    return 0;
}