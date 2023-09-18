#include <iostream>
#include <fstream>
#include <unordered_map>
#include <cmath>

using namespace std;

ifstream fin("arhitect.in");
ofstream fout("arhitect.out");

unordered_map <double, int> m;

int main(void)
{
    int n, cnt, x1, y1, x2, y2;
    double aux;

    fin >> n;

    for(int i = 1; i <= n; i++) {
        fin >> x1 >> y1 >> x2 >> y2;
        if(x1 == x2 || y1 == y2)
            cnt++;

        if(x1 < x2)
            aux = (double) abs(y1 - y2) / abs(x2 - x1);
        else
            aux = (double) abs(x1 - x2) / abs(y1 - y2);

        m[tan(aux)]++;
    }

    int ma = -1;

    for(auto i : m)
        ma = max(ma, i.second);

    fout << max(ma, cnt);

    return 0;
}