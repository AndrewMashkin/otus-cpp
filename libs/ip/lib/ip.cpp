#include "ip.h"

IP::IP(uint8_t n1,uint8_t n2,uint8_t n3, uint8_t n4):ip{n1,n2,n3,n4}{}

uint8_t IP::operator [](size_t index)const{
    if(index>=maxAddrCount){
        throw std::out_of_range("max index for get some point of IP is 3");
    }

    return ip[index];
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
