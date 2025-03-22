#include "ip_utility/ip_filter_impl.h"
#include "gtest/gtest.h"


TEST(IPFilter, Constructor_InvalidInfo_CatchThrow)
{
    FilterInfo info;
    info.filterCoef.at(0)=std::make_pair(5,127);
    bool err{false};

    try{
        Filter filter(info,Strategy::givenOrder);
    }catch(const std::out_of_range&){
        err=true;
    }

    ASSERT_TRUE(err);
}

TEST(IPFilter, Filter_FilterByOneValue_Success)
{
    IPTable ipTable{{127,13,55,4},{127,4,33,4},
                    {9,13,55,4} };

    FilterInfo info;
    info.filterCoef.at(0)=std::make_pair(0,127);

    Filter filter(info,Strategy::givenOrder);
    auto newTable=filter.filter(ipTable);
    std::cerr<<newTable<<std::endl;

    ASSERT_EQ(newTable.size(),2);
    ASSERT_EQ(newTable.at(0),ipTable.at(0));
    ASSERT_EQ(newTable.at(1),ipTable.at(1));

}

TEST(IPFilter, Filter_FilterByTwoValue_Success)
{

    IPTable ipTable{{127,13,55,4},{127,4,33,4},
                    {9,13,55,4}, {1,13,9,4} };

    FilterInfo info;
    info.filterCoef.at(0)=std::make_pair(1,13);
    info.filterCoef.at(1)=std::make_pair(3,4);


    Filter filter(info,Strategy::givenOrder);
    auto newTable=filter.filter(ipTable);

    ASSERT_EQ(newTable.size(),3);
    ASSERT_EQ(newTable.at(0),ipTable.at(0));
    ASSERT_EQ(newTable.at(1),ipTable.at(2));
    ASSERT_EQ(newTable.at(2),ipTable.at(3));

}

TEST(IPFilter, Filter_FilterByAll_Success)
{
    IP ip(127,13,55,4);

    IPTable ipTable{{127,13,55,4},{127,4,33,4},
                    {9,13,55,4} };
    FilterInfo info;
    info.filterCoef.at(0)=std::make_pair(0,9);
    info.filterCoef.at(1)=std::make_pair(1,13);
    info.filterCoef.at(2)=std::make_pair(2,55);
    info.filterCoef.at(3)=std::make_pair(3,4);

    Filter filter(info,Strategy::givenOrder);
    auto newTable=filter.filter(ipTable);

    ASSERT_EQ(newTable.size(),1);
    ASSERT_EQ(newTable.at(0),ipTable.at(2));

}


TEST(IPFilter, Filter_NotFoundIp_Success)
{
    IP ip(127,13,55,4);

    IPTable ipTable{{127,13,55,4},{127,4,33,4},
                    {9,13,55,4} };

    FilterInfo info;
    info.filterCoef.at(0)=std::make_pair(0,8);

    Filter filter(info,Strategy::givenOrder);
    auto newTable=filter.filter(ipTable);

    ASSERT_TRUE(newTable.empty());

}


TEST(IPFilter, Filter_FilterByAtLeastStrategy_Success)
{

    IPTable ipTable{{1,127,55,4},{1,4,33,127},
                    {127,2,55,4}, {1,13,127,4} };

    FilterInfo info;
    info.filterCoef.at(0)=std::make_pair(0,127);

    Filter filter(info,Strategy::atLeastOne);
    auto newTable=filter.filter(ipTable);

    ASSERT_EQ(newTable.size(),4);
    ASSERT_EQ(newTable.at(0),ipTable.at(0));
    ASSERT_EQ(newTable.at(1),ipTable.at(1));
    ASSERT_EQ(newTable.at(2),ipTable.at(2));
    ASSERT_EQ(newTable.at(3),ipTable.at(3));

}
