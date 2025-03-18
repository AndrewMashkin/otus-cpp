#include "ip_parser.h"
#include <sstream>

using namespace IPFilter;


IP IPParser::parse(const std::string& strIp){

    std::string token;
    std::istringstream strStram(strIp);
    std::vector<uint8_t> ipValues;


    while(std::getline(strStram,token,'.')){
        ipValues.push_back(std::stoi(token));
        if(ipValues.size()==IP::maxAddrCount){
            break;
        }

    }

    if(ipValues.size()<IP::maxAddrCount){
        throw std::runtime_error("invalid str ip, need to str like - 124.33.5.6, but have = "+strIp);
    }

    return IP(ipValues[0],ipValues[1],ipValues[2],ipValues[3]);

}


IPTable IPParser::parse(std::vector<std::string>&& strTable){

    IPTable table;
    table.reserve(strTable.size());

    for(const auto& strIp:strTable){
        table.push_back(IPParser::parse(strIp));
    }

    return table;

}



