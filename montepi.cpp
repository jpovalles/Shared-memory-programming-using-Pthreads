#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <cmath>
using namespace std;

int monteCarlo(int nTosses){
    int inCircle = 0;
    for(int i = 0; i < nTosses; i++){
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;
        if(x * x + y * y <= 1){
            inCircle++;
        }
    }
    return inCircle;
}

int main(int argc, char* argv[]){
	clock_t iniCpu = clock();
    time_t iniReal = time(NULL);
	
	
    srand(time(NULL));
    int nTosses = atoi(argv[1]);

    int inCircle = monteCarlo(nTosses);

    double pi = 4.0 * inCircle / atoi(argv[1]);
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
