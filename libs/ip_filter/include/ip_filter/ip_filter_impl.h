#pragma once

#include "ip.h"
#include <optional>
#include <functional>

struct FilterInfo{
    using FilterPair=std::pair<size_t,uint8_t>;
    std::array<std::optional<FilterPair>,IP::maxAddrCount> filterCoef;
};

enum class Strategy{
    givenOrder,
    atLeastOne
};

struct Filter{
    explicit  Filter(const FilterInfo& filterInfo,const Strategy& strategy);

    IPTable filter(const IPTable& ipTable) const;
    ~Filter() =default;
private:
    std::vector<FilterInfo::FilterPair> filterCoef;

    using Checker=std::function<bool(const IP& ip)>;
    Checker checker;

};

