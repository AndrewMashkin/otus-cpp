#include "ip_filter/ip_sort_filter.h"
#include "gtest/gtest.h"

TEST(IPSortFilter, Filter_FilterValidTable_Success)
{
    IPTable ipTable = {
        {192, 168, 1, 1},
        {10, 0, 0, 1},
        {172, 16, 254, 1},
        {192, 168, 1, 2},
        {10, 0, 0, 2}
    };

    IPTable etalonTable = {
        {192, 168, 1, 2},
        {192, 168, 1, 1},
        {172, 16, 254, 1},
        {10, 0, 0, 2},
        {10, 0, 0, 1}
    };

    SortFilter filter;
    auto newTable=filter.filter(ipTable);

    ASSERT_EQ(newTable.size(),5);

    for(size_t i=0;i<newTable.size();++i){
        ASSERT_EQ(newTable[i],etalonTable[i]);
    }
}

TEST(IPSortFilter, Filter_EmptyTable_EmptyOutput)
{
    IPTable ipTable = {  };

    SortFilter filter;
    auto newTable=filter.filter(ipTable);

    ASSERT_TRUE(newTable.empty());

}
