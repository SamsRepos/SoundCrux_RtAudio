#pragma once

namespace sc 
{

typedef double Sample;

struct StereoSample
{
public:
    Sample left;
    Sample right;

    StereoSample();
    StereoSample(Sample value);

    StereoSample& operator=(Sample value);
};

}
