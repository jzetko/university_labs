#include <cstdlib>
#include <iostream>

using namespace std;

int prv(int n)
{
    register int d;

    for (d=2; d<=n/2; d++)
        if (n%d==0)
            return 0;
    return 1;
}

int main(int argc, char *argv[])
{
    int N;
    cout<<"N: ";
    cin>>N;

    cout<<"Simples prime divisors of "<<N<<": ";
    for (int del=2;N>1;del++)
        if (prv(del))
            if (N%del==0)
            {
                N/=del;
                cout<<del<<" ";
                del--;
            }
    return 0;
}
