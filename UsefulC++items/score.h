/*
THIS ONE HAS THE MATE SCORE!!! 
 */

#ifndef SCORE_H
#define SCORE_H

#include "definitions.h"

struct Score
{
    Score() : mg(0), eg(0) {}
    Score(int val) : mg(val), eg(val) {}
    Score(int mg, int eg) : mg(mg), eg(eg) {}

    int value(int phase, int max_phase) const;
    int value() const;

    const Score operator-() const;

    const Score operator+(const Score& rhs) const;
    const Score operator-(const Score& rhs) const;
    const Score operator*(const Score& rhs) const;
    const Score operator/(const Score& rhs) const;

    const Score operator+(const int rhs) const;
    const Score operator-(const int rhs) const;
    const Score operator*(const int rhs) const;
    const Score operator/(const int rhs) const;

    const Score& operator+=(const Score& rhs);
    const Score& operator-=(const Score& rhs);
    const Score& operator*=(const Score& rhs);
    const Score& operator/=(const Score& rhs);

    const Score& operator+=(const int rhs);
    const Score& operator-=(const int rhs);
    const Score& operator*=(const int rhs);
    const Score& operator/=(const int rhs);

private:
    int mg;
    int eg;
};

inline int Score::value() const
{
    return mg;
}
inline int Score::value(int phase, int max_phase) const
{
    return ((mg * phase) + (eg * (max_phase - phase))) / max_phase;
}

inline const Score Score::operator-() const { return Score(-mg, -eg); }

inline const Score Score::operator+(const Score& rhs) const { return Score(mg + rhs.mg, eg + rhs.eg); }
inline const Score Score::operator-(const Score& rhs) const { return Score(mg - rhs.mg, eg - rhs.eg); }
inline const Score Score::operator*(const Score& rhs) const { return Score(mg * rhs.mg, eg * rhs.eg); }
inline const Score Score::operator/(const Score& rhs) const { return Score(mg / rhs.mg, eg / rhs.eg); }

inline const Score Score::operator+(const int rhs) const { return Score(mg + rhs, eg + rhs); }
inline const Score Score::operator-(const int rhs) const { return Score(mg - rhs, eg - rhs); }
inline const Score Score::operator*(const int rhs) const { return Score(mg * rhs, eg * rhs); }
inline const Score Score::operator/(const int rhs) const { return Score(mg / rhs, eg / rhs); }

inline const Score& Score::operator+=(const Score& rhs)
{
    mg += rhs.mg;
    eg += rhs.eg;
    return *this;
}
inline const Score& Score::operator-=(const Score& rhs)
{
    mg -= rhs.mg;
    eg -= rhs.eg;
    return *this;
}
inline const Score& Score::operator*=(const Score& rhs)
{
    mg *= rhs.mg;
    eg *= rhs.eg;
    return *this;
}
inline const Score& Score::operator/=(const Score& rhs)
{
    mg /= rhs.mg;
    eg /= rhs.eg;
    return *this;
}

inline const Score& Score::operator+=(const int rhs)
{
    mg += rhs;
    eg += rhs;
    return *this;
}
inline const Score& Score::operator-=(const int rhs)
{
    mg -= rhs;
    eg -= rhs;
    return *this;
}
inline const Score& Score::operator*=(const int rhs)
{
    mg *= rhs;
    eg *= rhs;
    return *this;
}
inline const Score& Score::operator/=(const int rhs)
{
    mg /= rhs;
    eg /= rhs;
    return *this;
}

inline Score S(int val) { return Score(val); }
inline Score S(int mg, int eg) { return Score(mg, eg); }

#endif
