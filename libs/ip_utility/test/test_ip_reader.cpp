#include "ip_utility/ip_reader.h"
#include "gtest/gtest.h"

TEST(IPReader, Read_InputIps_SuccessEq)
{
    std::string testData =
            "192.168.1.1\tignore\tignore\n"
            "10.0.0.1\tignore\tignore\n"
            "256.0.0.1\tignore\tignore\n"  // Некорректный IP
            "172.16.254.1\tignore\tignore\n";


    std::istringstream input(testData);

    std::vector<std::string> result = IPReader::read(input);

    std::vector<std::string> expected = {
        "192.168.1.1",
        "10.0.0.1",
        "172.16.254.1"
    };

    ASSERT_TRUE(expected==result);

}


TEST(IPReader, Read_InvalidFormat_SuccessEq)
{
    std::string testData =
            "192.168.1.1\tignore\tignore\n"
            "10.0.0.1\tignore\n";

    std::istringstream input(testData);

    std::vector<std::string> result = IPReader::read(input);

    std::vector<std::string> expected = {
        "192.168.1.1",
    };

    ASSERT_TRUE(expected==result);

}
