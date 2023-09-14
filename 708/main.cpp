#include <iostream>
#include <fstream>
#include <algorithm>
#include <unordered_map>
using namespace std;

ifstream fin("anagrame.in");
ofstream fout("anagrame.out");

int length;
char letters[11];
char anagram[11];
bool vf[11];
unordered_map<string, bool> m;

void solution()
{
    string res = "";
    for(int i = 1; i <= length; i++)
        res += anagram[i];
    if(!m[res]) {
        m[res] = true;
        fout << res << '\n';
    }
}

void back(int k)
{
    for(int i = 1; i <= length; i++) {
        if(!vf[i]) {
            anagram[k] = letters[i];
            vf[i] = true;
            if(k == length)
                solution();
            else
                back(k + 1);
            vf[i] = false;
        }
    }
}

int main(void)
{
    string s;

    fin >> s;

    length = s.size();

    for(int i = 0; i < length; i++)
        letters[i + 1] = s[i];

    sort(letters + 1, letters + length + 1);

    back(1);

    return 0;
}