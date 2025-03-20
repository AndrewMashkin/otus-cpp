#include "version_api/version_api.h"
#include <iostream>


//int main() {
//    // Сообщение пользователю
//    std::cout << "Введите данные в формате: text1 \\t text2 \\t text3" << std::endl;
//    std::cout << "Для завершения ввода нажмите Ctrl+D (Linux/Mac) или Ctrl+Z (Windows)." << std::endl;

//    // Чтение данных от пользователя
//    std::vector<std::string> ipAddresses = readIPv4Addresses(std::cin);

//    // Вывод результата
//    std::cout << "Найденные IPv4-адреса:" << std::endl;
//    for (const auto& ip : ipAddresses) {
//        std::cout << ip << std::endl;
//    }

//    return 0;
//}



int main() {
	
    std::cout << "Version: " << VersionAPI::getVersion() << std::endl;
    std::cout << "Hello, world!" << std::endl;
	
	return 0;
}
