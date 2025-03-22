#include "ip_reader.h"
#include <sstream>
#include <algorithm>


bool IPReader::isValidIPv4(const std::string& ip) {

    std::istringstream iss(ip);
    std::string segment;
    int count = 0;

    while (std::getline(iss, segment, '.')) {
        try {
            int num = std::stoi(segment);
            if (num < 0 || num > 255) {
                return false;
            }
        } catch (const std::invalid_argument&) {
            return false;
        } catch (const std::out_of_range&) {
            return false;
        }
        count++;
    }

    return count == 4;
}

std::vector<std::string> IPReader::read(std::istream& input) {
    std::vector<std::string> ipAddresses;
    std::string line;

    while (std::getline(input, line)) {
        std::istringstream iss(line);
        std::string text1, text2, text3;

        if (std::getline(iss, text1, '\t') &&
                std::getline(iss, text2, '\t') &&
                std::getline(iss, text3, '\t')) {

            //std::cerr << "Прочитано: " << text1 << " | " << text2 << " | " << text3 << std::endl;

            if (isValidIPv4(text1)) {
                ipAddresses.push_back(text1);
            }
        }
    }

    return ipAddresses;
}
