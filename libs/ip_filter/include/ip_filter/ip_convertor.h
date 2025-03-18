#pragma once
#include "ip.h"


struct IPConvertor{
    static IP convert(const std::string& strIp);
    static IPTable convert( std::vector<std::string>&& strTable);
};


