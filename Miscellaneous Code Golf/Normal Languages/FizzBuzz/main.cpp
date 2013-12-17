#include <iostream>
using namespace std;
int main()
{
    for(int i=1;i<=100;i++){
        if((i%3 == 0) && (i%5==0)) puts("FizzBuzz");
        else if(i%3 == 0) puts("Fizz");
        else if(i%5 == 0) puts("Buzz");
        else printf("%d\n", i);
     }
    return 0;
}
