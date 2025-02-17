#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <cmath>
using namespace std;
int main(int argc, char *argv[]){
	clock_t iniCpu = clock();
    time_t iniReal = time(NULL);
    int i = atoi(argv[1]);
    double pi = 0;

    for (int n = 0; n < i; n++){
        pi +=  (1 - 2.0 * (n % 2)) / (2.0 * n + 1);
    }
    pi *= 4.0;
    
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
