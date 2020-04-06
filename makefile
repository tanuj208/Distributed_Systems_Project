main : main.cpp ecuyer.cpp lcg_parallel1.cpp lcg_parallel2.cpp lcg_parallel3.cpp Monte_Carlo.cpp
	mpic++ -o main main.cpp ecuyer.cpp lcg_parallel1.cpp lcg_parallel2.cpp lcg_parallel3.cpp Monte_Carlo.cpp
