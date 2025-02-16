#include <iostream>
#include <cstdlib> 
#include <ctime>
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
    srand(time(NULL));
    int nTosses = atoi(argv[1]);

    int inCircle = monteCarlo(nTosses);

    double pi = 4.0 * inCircle / atoi(argv[1]);
    cout << "Number of tosses in circle " << inCircle << endl;
    cout << "The value of pi is: " << pi << endl;
    return 0;
}