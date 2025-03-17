#include "ip.h"
#include <tuple>

IP::IP(uint8_t n1,uint8_t n2,uint8_t n3, uint8_t n4):ip{n1,n2,n3,n4}{}

uint8_t IP::operator [](size_t index)const{
    if(index>=maxAddrCount){
        throw std::out_of_range("max index for get some point of IP is 3");
    }

    return ip[index];
}

bool IP::operator <(const IP& other)const{
    return std::tie(ip[0],ip[1],ip[2],ip[3])<
            std::tie(other.ip[0],other.ip[1],other.ip[2],other.ip[3]);
}

bool IP::operator ==(const IP& other)const{
    return std::tie(ip[0],ip[1],ip[2],ip[3])==
            std::tie(other.ip[0],other.ip[1],other.ip[2],other.ip[3]);
}

std::ostream& operator << (std::ostream &os, const IP &ip){
    return os<<(int)ip[0]<<"."<<(int)ip[1]<<"."<<(int)ip[2]<<"."<<(int)ip[3];
}
std::ostream& operator << (std::ostream &os, const IpTable &ipTable){
    for(const auto& ip:ipTable){
        os<<ip;
    }
    return os ;
}
