#ifndef PARAMETER_H
#define PARAMETER_H

#include "Common/etl.h"

// FIXED: 用any会不会好点？
//class IntParameter : public ICommandParameter
//{
//public:
//    explicit IntParameter(int v) : value(v) {}

//    int value;
//};

template <typename T>
class BasicParameter : public ICommandParameter
{
public:
    explicit BasicParameter(T v) : value(v) {}

    T value;
};

class StringParameter : public ICommandParameter
{
public:
    explicit StringParameter(const std::string s) : str(s) {}

    std::string str;
};

class BlurParameter : public ICommandParameter
{
public:
    explicit BlurParameter(int ksize = 3, int anchor = -1) : ksize(ksize), anchor(anchor) {}

    int ksize;
    int anchor;
};

#endif // PARAMETER_H
