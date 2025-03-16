#pragma once
#include <array>

#include <cstddef>
namespace IpLoader {

struct IP{
    IP(size_t n1,size_t n2,size_t n3, size_t n4);
    std::array<size_t,4 > ip;
};





class IpLoader{
public:

    virtual
    virtual ~IpLoader() = default;


};


}
