# Factorization-Primality

Fastest single-file factorization and primality testing for 32-bit and 64-bit integers on x86.

Primality testing:

```
bool IsPrime(U32 x);
bool IsPrime(U64 x);
```

Factorization:

```
FactorizeResult32 Factorize(U32 x);
FactorizeResult64 Factorize(U64 x);
```

Up to about 2<sup>38</sup>, it is possible to test for primality even faster if you're okay with consuming a bunch of memory, using a fast prime sieve. See https://github.com/komrad36/PrimeSieve
