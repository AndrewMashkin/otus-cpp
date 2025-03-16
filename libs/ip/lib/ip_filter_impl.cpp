#include "ip_filter_impl.h"

SimpleFilter::SimpleFilter(const FilterInfo& filterInfo){

    for(const auto& coef:filterInfo.filterCoef){
        if(coef.has_value()){

            if(coef.value().first>=IP::maxAddrCount){
                throw std::out_of_range("max index for get some ip addr is 3");
            }

            filterCoef.push_back(coef.value());
        }
    }
}
bool SimpleFilter::checkIp(const IP& ip) const{

    for(const auto& coef:filterCoef){
        if(ip[coef.first]!=coef.second){
            return false;
        }
    }
    return true;
}

IpTable SimpleFilter::filter(const IpTable& ipTable) {
    IpTable resTable;
    for(const auto& ip:ipTable){
        if(checkIp(ip)){
            resTable.push_back(ip);
        }
    }

    return resTable;
}
