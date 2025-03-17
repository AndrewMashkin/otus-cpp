#pragma once

#include "ip.h"

struct IIPFilter{
    virtual IPTable filter(const IPTable& ipTable)=0;
    virtual ~IIPFilter()=default;
};

