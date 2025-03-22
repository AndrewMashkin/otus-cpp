#include "ip_utility/ip.h"
#include "gtest/gtest.h"


TEST(IP, Constructor_Create_NoThrow)
{
    ASSERT_NO_THROW(IP(120,22,1,5));
}

TEST(IP, GetValue_GetWithValidIndex_Success)
{
    IP ip(1,2,3,4);
    ASSERT_EQ(ip[0],1);
}

TEST(IP, GetValue_GetWithInvalidIndex_CatchThrow)
{
    IP ip(1,2,3,4);
    ASSERT_THROW(ip[4],std::out_of_range);
}

TEST(IP, Print_PrintIpAddr_SuccessOutputShow)
{
    IP ip(132,11,22,5);
    std::cerr<<ip<<std::endl;
}
