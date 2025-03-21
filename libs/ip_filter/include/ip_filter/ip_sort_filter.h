#pragma once

#include "i_ip_filter.h"

struct SortFilter : public IFilter{
    IPTable filter(const IPTable& ipTable) const override;
    ~SortFilter() override =default;
private:

};

