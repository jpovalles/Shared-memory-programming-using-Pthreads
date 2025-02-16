#include <iostream>
#include <cstdlib> 
#include <pthread.h>
#include <ctime>
using namespace std;

int inCircle = 0;
int nThreads, nTosses, tossesPerThread;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* monteCarlo(void* arg){
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
    for(int i = 0; i < intTosses; i++){
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;
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
    srand(time(NULL));

    nThreads = atoi(argv[1]);
    nTosses = atoi(argv[2]);
    tossesPerThread = nTosses / nThreads;
    
    pthread_t threads[nThreads];

    for (int i = 0; i < nThreads; i++) {
        pthread_create(&threads[i], NULL, monteCarlo, NULL);
    }

    for (int i = 0; i < nThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    double pi = 4.0 * inCircle / atoi(argv[2]);
    cout << "The value of pi is: " << pi << endl;
    
    pthread_mutex_destroy(&mutex);
    return 0;
}
