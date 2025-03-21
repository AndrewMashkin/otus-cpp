#pragma once

#include "ip.h"
#include <memory>

struct IFilter{
    virtual IPTable filter(const IPTable& ipTable) const = 0;
    virtual  ~IFilter() =default;
};

using Cascade=std::vector<std::shared_ptr<IFilter>>;
