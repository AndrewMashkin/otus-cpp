#pragma once

#include "i_ip_filter.h"
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

struct Filter : public IFilter{
    explicit  Filter(const FilterInfo& filterInfo,const Strategy& strategy);

    IPTable filter(const IPTable& ipTable) const override;
    ~Filter() override =default;
private:
    std::vector<FilterInfo::FilterPair> filterCoef;

    using Checker=std::function<bool(const IP& ip)>;
    Checker checker;

};

