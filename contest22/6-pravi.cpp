#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

typedef unsigned long long ull;

const int LIMIT = 10000000;

vector<int> primes;

void sieve() {
    vector<bool> isComposite(LIMIT + 1, false);

    for (int i = 2; i <= LIMIT; i++) {
        if (!isComposite[i]) {
            primes.push_back(i);

            if ((long long)i * i <= LIMIT) {
                for (long long j = (long long)i * i; j <= LIMIT; j += i) {
                    isComposite[(int)j] = true;
                }
            }
        }
    }
}

map<ull, int> factorize(ull n) {
    map<ull, int> factors;

    for (int i = 0; i < (int)primes.size(); i++) {
        ull p = primes[i];

        if (p * p > n) break;

        while (n % p == 0) {
            factors[p]++;
            n /= p;
        }
    }

    if (n > 1) {
        factors[n]++;
    }

    return factors;
}

void generateDivisors(
    const vector<pair<ull, int> >& factors,
    int index,
    ull current,
    vector<ull>& divisors
) {
    if (index == (int)factors.size()) {
        divisors.push_back(current);
        return;
    }

    ull p = factors[index].first;
    int power = factors[index].second;

    ull value = 1;

    for (int i = 0; i <= power; i++) {
        generateDivisors(factors, index + 1, current * value, divisors);
        value *= p;
    }
}

ull phi(ull n) {
    map<ull, int> factors = factorize(n);

    ull result = n;

    for (map<ull, int>::iterator it = factors.begin(); it != factors.end(); ++it) {
        ull p = it->first;
        result = result / p * (p - 1);
    }

    return result;
}

ull solve(ull N) {
    map<ull, int> factorMap = factorize(N);

    vector<pair<ull, int> > factors;

    for (map<ull, int>::iterator it = factorMap.begin(); it != factorMap.end(); ++it) {
        factors.push_back(*it);
    }

    vector<ull> divisors;
    generateDivisors(factors, 0, 1, divisors);

    ull answer = 0;

    for (int i = 0; i < (int)divisors.size(); i++) {
        ull d = divisors[i];
        answer += phi(d + 1);
    }

    return answer;
}

int main() {
    sieve();

    int T;
    cin >> T;

    while (T--) {
        ull N;
        cin >> N;

        cout << solve(N) << '\n';
    }

    return 0;
}