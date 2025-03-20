#include "ip_filter/ip_convertor.h"
#include "gtest/gtest.h"

TEST(IPConvertor, Parse_ValidIp_SuccessEq)
{
    std::string ip="134.22.1.2";

    IP etalonIp(134,22,1,2);

    IP res=IPConvertor::convert(ip);

    ASSERT_EQ(etalonIp,res);
}

TEST(IPConvertor, Parse_InValidIp_CatchRunTimeError)
{
    std::string ip="134,22.1.2";

    ASSERT_THROW(IPConvertor::convert(ip),std::runtime_error);

}

TEST(IPConvertor, Parse_ShortIp_CatchRunTimeError)
{
    std::string ip="134.22.1";

    ASSERT_THROW(IPConvertor::convert(ip),std::runtime_error);

}

TEST(IPConvertor, Parse_EmptyStr_CatchRunTimeError)
{
    std::string ip="";

    ASSERT_THROW(IPConvertor::convert(ip),std::runtime_error);

}

TEST(IPConvertor, Parse_ValidIpTable_SuccessEq)
{
    std::vector<std::string> ip={"134.22.1.2",
                                "2.5.6.7","88.22.13.5"};

    IPTable etalonTable{{134,22,1,2},{2,5,6,7,},{88,22,13,5}};

    IPTable res=IPConvertor::convert(std::move(ip));

    ASSERT_EQ(etalonTable.size(),res.size());

    for(size_t i=0;i<etalonTable.size();++i){
        ASSERT_EQ(etalonTable[i],res[i]);

    }

}

TEST(IPConvertor, Parse_EmptyIpTable_SuccessEq)
{
    std::vector<std::string> ip={};

    IPTable res=IPConvertor::convert(std::move(ip));

    ASSERT_TRUE(res.empty());

}

