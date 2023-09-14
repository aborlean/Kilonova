#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("parcare.in");
ofstream fout("parcare.out");

long long n, m, t;
long long parcare[200005];
long long arrival[200005];

int main(void)
{
    fin >> n >> m >> t;

    long long curent = 0, x, y;

    fin >> x >> y;

    do {
        curent++;
        if(x == curent) {
            int i = 1;
            while(parcare[i] > x && i <= n)
                i++;
            if(parcare[i] <= x && i <= n) {
                parcare[i] = y;
                arrival[i] = x;
                fout << i << '\n';
            }
            else
                fout << -1 << '\n';
            fin >> x >> y;
        }
    } while(curent < t);

    for(int i = 1; i <= n; i++)
        if(parcare[i] > t)
            fout << arrival[i] << ' ';
        else
            fout << -1 << ' ';

    return 0;
}