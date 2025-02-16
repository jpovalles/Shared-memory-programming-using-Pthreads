# Shared-memory-programming-using-Pthreads
This repository contains the source code for a hands-on workshop on multithreaded parallel programming using Pthreads. It includes implementations for estimating the value of π (Pi) using different methods:  
* Taylor Series Approximation (taylorpi.cpp)
* Monte Carlo Method with Threads (carlopi.cpp) 
* Monte Carlo Method without Threads (montepi.cpp)

The project compares execution times and accuracy across different implementations, analyzing the performance impact of parallel processing. Instructions for execution and performance evaluation are also included.


# Compilation Instructions

To compile each program using `g++`, use the following commands:

## Taylor Series Approximation (taylorpi.cpp)
```sh
g++ -o taylorpi taylorpi.cpp
```

## Monte Carlo Method with threads (carlopi.cpp)
```sh
g++ -pthread -o carlopi carlopi.cpp
```

## Monte Carlo Method without threads (montepi.cpp)
```sh
g++ -o montepi montepi.cpp
```

# Running the Programs
Once compiled, you can execute the programs using:
```sh
./taylorpi <upper_bound>
./carlopi <num_threads> <num_tosses>
./montepi <num_tosses>
```
Replace <upper_bound>, <num_threads>, and <num_tosses> with the desired numerical values.
