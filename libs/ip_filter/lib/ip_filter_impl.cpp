#include "ip_filter_impl.h"

Filter::Filter(const FilterInfo& filterInfo, const Strategy &strategy){

    for(const auto& coef:filterInfo.filterCoef){
        if(coef.has_value()){

            if(coef.value().first>=IP::maxAddrCount){
                throw std::out_of_range("max index for get some ip addr is 3");
            }

            filterCoef.push_back(coef.value());
        }
    }

    if(strategy==Strategy::givenOrder){
        checker=[this](const IP& ip)->bool
        {
            for(const auto& coef:filterCoef){
                if(ip[coef.first]!=coef.second){
                    return false;
                }
            }
            return true;
        };
    }else{
        checker=[this](const IP& ip)->bool
        {
            for(const auto& coef:filterCoef){
               for(size_t addr=0;addr<IP::maxAddrCount;++addr){
                    if(ip[addr]==coef.second){
                        return true;
                    }
               }

            }
            return false;
        };
    }


}

IPTable Filter::filter(const IPTable& ipTable) const {
    IPTable resTable;
    for(const auto& ip:ipTable){
        if(checker(ip)){
            resTable.push_back(ip);
        }
    }

    return resTable;
}
