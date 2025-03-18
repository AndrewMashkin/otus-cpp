#include "ip_filter/ip_parser.h"
#include "gtest/gtest.h"

TEST(IPParser, Parse_ValidIp_SuccessEq)
{
    std::string ip="134.22.1.2";

    IP etalonIp(134,22,1,2);

    IP res=IPFilter::IPParser::parse(ip);

    ASSERT_EQ(etalonIp,res);
}

TEST(IPParser, Parse_InValidIp_CatchRunTimeError)
{
    std::string ip="134,22.1.2";

    ASSERT_THROW(IPFilter::IPParser::parse(ip),std::runtime_error);

}

TEST(IPParser, Parse_ShortIp_CatchRunTimeError)
{
    std::string ip="134.22.1";

    ASSERT_THROW(IPFilter::IPParser::parse(ip),std::runtime_error);

}

TEST(IPParser, Parse_EmptyStr_CatchRunTimeError)
{
    std::string ip="";

    ASSERT_THROW(IPFilter::IPParser::parse(ip),std::runtime_error);

}


TEST(IPParser, Parse_ValidIpTable_SuccessEq)
{
    std::vector<std::string> ip={"134.22.1.2",
                                "2.5.6.7","88.22.13.5"};

    IPTable etalonTable{{134,22,1,2},{2,5,6,7,},{88,22,13,5}};

    IPTable res=IPFilter::IPParser::parse(std::move(ip));

    ASSERT_EQ(etalonTable.size(),res.size());

    for(size_t i=0;i<etalonTable.size();++i){
        ASSERT_EQ(etalonTable[i],res[i]);

    }

}

TEST(IPParser, Parse_EmptyIpTable_SuccessEq)
{
    std::vector<std::string> ip={};

    IPTable res=IPFilter::IPParser::parse(std::move(ip));

    ASSERT_TRUE(res.empty());

}

