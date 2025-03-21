#include "ip.h"
#include <tuple>


IP::IP(uint8_t n1,uint8_t n2,uint8_t n3, uint8_t n4):addrs{n1,n2,n3,n4}{}

uint8_t IP::operator [](size_t index)const{
    if(index>=maxAddrCount){
        throw std::out_of_range("max index for get some point of IP is 3");
    }

    return addrs[index];
}

bool IP::operator <(const IP& other)const{
    return std::tie(addrs[0],addrs[1],addrs[2],addrs[3])<
            std::tie(other.addrs[0],other.addrs[1],other.addrs[2],other.addrs[3]);
}

bool IP::operator ==(const IP& other)const{
    return std::tie(addrs[0],addrs[1],addrs[2],addrs[3])==
            std::tie(other.addrs[0],other.addrs[1],other.addrs[2],other.addrs[3]);
}

std::ostream& operator << (std::ostream &os, const IP &ip){
    return os<<(int)ip[0]<<"."<<(int)ip[1]<<"."<<(int)ip[2]<<"."<<(int)ip[3];
}
std::ostream& operator << (std::ostream &os, const IPTable &ipTable){
    for (auto it = ipTable.begin(); it != ipTable.end(); ++it) {
        os << *it;
        if (std::next(it) != ipTable.end()) {
            os << std::endl;
        }
    }
    return os;
}
