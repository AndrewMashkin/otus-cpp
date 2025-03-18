#pragma once
#include "ip.h"

namespace IPFilter{

struct IPParser{
    static IP parse(const std::string& strIp);
    static IPTable parse( std::vector<std::string>&& strTable);
};

}
