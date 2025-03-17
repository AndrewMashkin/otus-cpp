#pragma once

#include "i_ip_filter.h"
#include <optional>

struct FilterInfo{
    using FilterPair=std::pair<size_t,uint8_t>;
    std::array<std::optional<FilterPair>,IP::maxAddrCount> filterCoef;
};

/// filter для случая хотябы 1


struct SimpleFilter : public IIPFilter{
    explicit  SimpleFilter(const FilterInfo& filterInfo);

    IpTable filter(const IpTable& ipTable) override;
    ~SimpleFilter() override=default;
private:
    std::vector<FilterInfo::FilterPair> filterCoef;
    bool checkIp(const IP& ip) const;
};
