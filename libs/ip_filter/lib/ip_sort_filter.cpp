#include "ip_sort_filter.h"
#include <algorithm>


IPTable SortFilter::filter(const IPTable& ipTable) const {

    auto table=ipTable;
    std::sort(table.begin(), table.end(), [](const IP& a, const IP& b) {
        return b < a;
    });

    return table;
}
