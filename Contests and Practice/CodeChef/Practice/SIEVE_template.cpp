#include <iostream>
#include <vector>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    //cin.tie(NULL);                    \
    //cout.tie(NULL); // to get output after all input is done
#define endl '\n'
vector<bool> is_prime;
unsigned long long N; //define this N for the range of primes in [0-N].
void sieve()
{
    for (int i = 0; i < N; i++)
        is_prime.push_back(1);
    is_prime[0] = 0;
    is_prime[1] = 0;
    int i = 2;
    while (i * i <= N)
    {
        if (is_prime[i] == 0)
        {
            i++;
            continue;
        }
        int j = 2 * i;
        while (j < N)
        {
            is_prime[j] = 0;
            j += i;
        }
        i++;
    }
}
int main()
{
    fastio
        N = 1000000;
    sieve();
    for (int i = 0; i < ::N; i++)
    {
        if (is_prime[i])
            cout << i << endl;
    }
}
