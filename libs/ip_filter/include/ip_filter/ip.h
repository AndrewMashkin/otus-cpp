#pragma once

#include <array>
#include <vector>
#include <cstddef>
#include <iostream>

struct IP{
    static const size_t maxAddrCount{4};

    IP(uint8_t n1,uint8_t n2,uint8_t n3, uint8_t n4);

    uint8_t operator [](size_t index)const;

    bool operator <(const IP& other)const;

    bool operator ==(const IP& other)const;

private:
    const std::array<uint8_t,maxAddrCount> addrs;
};

using IPTable=std::vector<IP>;

std::ostream& operator << (std::ostream &os, const IP &ip);
std::ostream& operator << (std::ostream &os, const IPTable &ipTable);
