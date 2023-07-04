#include "arg_parser.hpp"

#include <iostream>

int main(int argc, char ** argv)
{
    ArgParser ap;
    if (!ap.init(argc, argv))
    {
        std::cout << "init error" << std::endl;
        return 1;
    }

    std::optional<int> itmp;
    std::optional<std::string> stmp;
    std::optional<bool> btmp;

    stmp = ap.getString("--help");
    if (stmp.has_value())
        std::cout << "Help: " << stmp.value() << std::endl;

    stmp = ap.getString("--own_ip");
    if (stmp.has_value())
        std::cout << "Own ip: " << stmp.value() << std::endl;

    itmp = ap.getInt("--own_port");
    if (itmp.has_value())
        std::cout << "Own port: " << itmp.value() << std::endl;

    stmp = ap.getString("--rem_ip");
    if (stmp.has_value())
        std::cout << "Remote ip: " << stmp.value() << std::endl;

    itmp = ap.getInt("--rem_port");
    if (itmp.has_value())
        std::cout << "Remote port: " << itmp.value() << std::endl;

    itmp = ap.getHex("--load_addr");
    if (itmp.has_value())
        std::cout << "Load address: " << std::hex << "0x" << itmp.value() << std::endl;

    btmp = ap.getBool("--debug");
    if (btmp.has_value())
        std::cout << "Debug: " << std::boolalpha << btmp.value() << std::endl;

    btmp = ap.getBool("--show_info");
    if (btmp.has_value())
        std::cout << "Show info: " << std::boolalpha << btmp.value() << std::endl;

    stmp = ap.getString("--some_arg");
    if (stmp.has_value())
        std::cout << "Some arg: " << stmp.value() << std::endl;

    return 0;
}