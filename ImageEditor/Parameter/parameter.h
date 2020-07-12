#ifndef PARAMETER_H
#define PARAMETER_H

#include "Common/etl.h"

class StringParameter : public ICommandParameter
{
public:
    explicit StringParameter(const std::string s) : str(s) {}

    std::string str;
};

class BlurParameter : public ICommandParameter
{
public:
    explicit BlurParameter(int ksize, int anchor) : ksize(ksize), anchor(anchor) {}

    int ksize = 3;
    int anchor = -1;
};

#endif // PARAMETER_H
