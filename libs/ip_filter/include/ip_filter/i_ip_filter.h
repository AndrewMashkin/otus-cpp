#pragma once

#include "ip.h"

struct IIPFilter{
    virtual IpTable filter(const IpTable& ipTable)=0;
    virtual ~IIPFilter()=default;
};

