#pragma once
#include "ip.h"


struct IPReader{
    static std::vector<std::string> read(std::istream& input);
private:
   static bool isValidIPv4(const std::string& ip);

};
