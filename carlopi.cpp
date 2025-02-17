#include <iostream>
#include <cstdlib> 
#include <pthread.h>
#include <ctime>
#include <cmath>
using namespace std;

int inCircle = 0;
int nThreads, nTosses, tossesPerThread;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* monteCarlo(void* arg){
	long rank = (long) arg;
    int intTosses;
    int localInCircle = 0;
    
    pthread_mutex_lock(&mutex);
    if(nTosses == 0){
	pthread_mutex_unlock(&mutex);
        pthread_exit(NULL);
    }else if (nTosses < tossesPerThread){
        intTosses = nTosses;
        nTosses = 0;
    }else{
        intTosses = tossesPerThread;
        nTosses -= tossesPerThread;
    }
    pthread_mutex_unlock(&mutex);
    unsigned int seed = time(NULL) + rank;
    for(int i = 0; i < intTosses; i++){
        double x = (double) rand_r(&seed) / RAND_MAX * 2.0 - 1.0;
		double y = (double) rand_r(&seed) / RAND_MAX * 2.0 - 1.0;
        if(x * x + y * y <= 1){
            localInCircle++;
        }
    }
    pthread_mutex_lock(&mutex);
    inCircle += localInCircle;
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main(int argc, char* argv[]){
	
	clock_t iniCpu = clock();
    time_t iniReal = time(NULL);
	
    nThreads = atoi(argv[1]);
    nTosses = atoi(argv[2]);
    tossesPerThread = nTosses / nThreads;
    
    pthread_t threads[nThreads];

    for (long i = 0; i < nThreads; i++) {
        pthread_create(&threads[i], NULL, monteCarlo, (void*) i);
    }

    for (int i = 0; i < nThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    double pi = 4.0 * inCircle / atoi(argv[2]);
    
    pthread_mutex_destroy(&mutex);
    
    clock_t finCpu = clock();
    time_t finReal = time(NULL);
    
    double error = fabs(pi - M_PI);
    
    cout << "El valor aproximado de pi es: " << pi << endl;
    
    cout << "El error es igual a: " << error << endl;
    double tiempoCpu = (double)(finCpu - iniCpu) / CLOCKS_PER_SEC;
    double tiempoReal = difftime(finReal, iniReal);

    cout << "Tiempo CPU: " << tiempoCpu << " s, Tiempo Real: " << tiempoReal << " s" << endl;
    return 0;
}
