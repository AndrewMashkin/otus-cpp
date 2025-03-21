#include "ip_filter/ip_sort_filter.h"
#include "gtest/gtest.h"

TEST(IPSortFilter, DISABLED_Filter_FilterByOneValue_Success)
{
    IPTable ipTable{{127,13,55,4},{127,4,33,4},
                    {9,13,55,4} };

    SortFilter filter;
    auto newTable=filter.filter(ipTable);

    ASSERT_EQ(newTable.size(),2);
    ASSERT_EQ(newTable.at(0),ipTable.at(0));
    ASSERT_EQ(newTable.at(1),ipTable.at(1));

}

