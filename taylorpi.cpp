#include <iostream>
#include <cstdlib> 
using namespace std;

int main(int argc, char *argv[]){
    int i = atoi(argv[1]);
    double pi = 0;

    for (int n = 0; n < i; n++){
        pi +=  (1 - 2.0 * (n % 2)) / (2.0 * n + 1);
    }
    pi *= 4.0;
    cout << "The value of pi is: " << pi << endl;
    return 0;
}