#include "version_api/version_api.h"
#include "ip_utility/ip_reader.h"
#include "ip_utility/ip_filter_impl.h"
#include "ip_utility/ip_sort_filter.h"
#include "ip_utility/ip_convertor.h"

int main() {

    Cascade cascade;

    FilterInfo firtsFilterInfo;
    firtsFilterInfo.filterCoef.at(0)=std::make_pair(0,1);

    FilterInfo secondFilterInfo;
    secondFilterInfo.filterCoef.at(0)=std::make_pair(0,46);
    secondFilterInfo.filterCoef.at(1)=std::make_pair(1,70);

    FilterInfo lastilterInfo;
    lastilterInfo.filterCoef.at(0)=std::make_pair(0,46);

    cascade.push_back(std::make_shared<SortFilter>());
    cascade.push_back(std::make_shared<Filter>(firtsFilterInfo,Strategy::givenOrder));
    cascade.push_back(std::make_shared<Filter>(secondFilterInfo,Strategy::givenOrder));
    cascade.push_back(std::make_shared<Filter>(lastilterInfo,Strategy::atLeastOne));

    std::cout << "ip filter, version: " << VersionAPI::getVersion() << std::endl;
    std::cout << "pls input data, format: text1 \\t text2 \\t text3" << std::endl;
    std::cout << "for end input work -  Ctrl+D (Linux/Mac) или Ctrl+Z (Windows)" << std::endl;

    try{
        auto ipAddresses = IPReader::read(std::cin);
        auto ipTable=IPConvertor::convert(std::move(ipAddresses));

        for(const auto& filter:cascade){
            std::cout<<filter->filter(ipTable)<<std::endl;
        }

    }catch(...){
        std::cerr<<"somthing wrong, cathc error"<<std::endl;
        return -1;
    }
    return 0;
}
