// File: A2_S2_20220183_4.cpp
// Purpose: find all the prime numbers up to some upper limit N.
// Author: Abdelrahman Wael
// Section: S1,2
// ID: 20220183
// TA: Maya Ahmed Kamal
// Date: 27 Oct 2023

#include <bits/stdc++.h>
using namespace std;

void sieve(int N)
{
    const int n = N;
    bool prime[n];

    //Consider every number is prime exept 0,1
    memset(prime, 1, sizeof prime);
    prime[0] = prime[1] = 0;

    //If a number is prime, then any number that is divisible by it is not prime
    for (int i = 2; i < n/i ; ++i) {
        if(prime[i])
            for (int j = i * i; j < n; j+=i)
                prime[j] = 0;
    }
    //Print a list of the prime numbers
    for (int i = 0; i < n; ++i) {
        if(prime[i])
            cout<<i<<" ";
    }
}

int main(){
    int N;
    cin>>N;
    sieve(N);
    return 0;
}
