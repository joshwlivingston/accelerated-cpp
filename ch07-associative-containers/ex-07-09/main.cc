#include <ctime>
#include <cstdlib>
#include <iostream>

#include "random.h"

using std::cin;
using std::cout;
using std::endl;
using std::srand;
using std::time;

int main()
{
    srand(time(0));
    int n;
    cin >> n;
    cout << nrand(n) << endl;
    return 0;
}
