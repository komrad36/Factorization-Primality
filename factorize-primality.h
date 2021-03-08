/*******************************************************************
*
*	Author: Kareem Omar
*	kareem.h.omar@gmail.com
*	https://github.com/komrad36
*
*	Last updated Mar 5, 2021
*******************************************************************/

#pragma once

#include <cstdint>

//#define ENABLE_ASSERTS

#ifdef ENABLE_ASSERTS
#include <cstdio>
#define ASSERT(a) do { if (!(a)) { printf("ASSERTION FAILED: %s\n", #a); __debugbreak(); } } while (0)
#else
#define ASSERT(a) do {} while (0)
#endif

///////////////////////////////
///  Primality testing
///////////////////////////////

// querying primality of 0 or 1 is guaranteed to terminate in reasonable time but
// the return value is undefined

bool IsPrime(uint32_t x);
bool IsPrime(uint64_t x);


///////////////////////////////
///  Factorization
///////////////////////////////

// the behavior of factoring 0 or 1 is undefined

struct FactorInfo32
{
    uint32_t m_factor;
    uint32_t m_exp;

    FactorInfo32() = default;
    FactorInfo32(uint32_t factor, uint32_t exp) : m_factor(factor), m_exp(exp) {}
};

struct FactorizeResult32
{
    // a 32-bit quantity can only have up to 9 unique factors (otherwise it'd be more than 32 bits)
    FactorInfo32 m_infos[9];
    uint32_t m_numInfos;

    void Insert(const FactorInfo32& info)
    {
        ASSERT(m_numInfos < 9);
        m_infos[m_numInfos++] = info;
    }

    void Insert(uint32_t factor, uint32_t exp)
    {
        ASSERT(m_numInfos < 9);
        m_infos[m_numInfos++] = { factor, exp };
    }

    FactorizeResult32() : m_numInfos(0) {}
};

FactorizeResult32 Factorize(uint32_t x);

struct FactorInfo64
{
    uint64_t m_factor;
    uint64_t m_exp;

    FactorInfo64() = default;
    FactorInfo64(uint64_t factor, uint64_t exp) : m_factor(factor), m_exp(exp) {}
};

struct FactorizeResult64
{
    // a 64-bit quantity can only have up to 15 unique factors (otherwise it'd be more than 64 bits)
    FactorInfo64 m_infos[15];
    uint64_t m_numInfos;

    void Insert(const FactorInfo64& info)
    {
        ASSERT(m_numInfos < 15);
        m_infos[m_numInfos++] = info;
    }

    void Insert(uint64_t factor, uint64_t exp)
    {
        ASSERT(m_numInfos < 15);
        m_infos[m_numInfos++] = { factor, exp };
    }

    FactorizeResult64() : m_numInfos(0) {}
};

FactorizeResult64 Factorize(uint64_t x);
