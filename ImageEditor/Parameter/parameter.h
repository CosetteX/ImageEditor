#ifndef PARAMETER_H
#define PARAMETER_H

#include "Common/etl.h"

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

class ZoomParameter : public ICommandParameter
{
public:
    explicit ZoomParameter(int flag) : sx(0), sy(0), flag(flag) {}
    explicit ZoomParameter(double sx, double sy) : sx(sx), sy(sy), flag(0) {}

    double sx;
    double sy;
    int flag;        // 0:Zoom 1:ZoomIn 2:ZoomOut
};


#endif // PARAMETER_H
