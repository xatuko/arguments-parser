#include "arg_parser.hpp"

bool ArgParser::init(int argc, char ** argv)
{
    if (argc < 1)
        return false;

    m_app_path = argv[0];

    std::string tmp;
    for (int i = 1; i < argc; i++)
    {
        tmp = argv[i];
        if (m_args.find(tmp) == m_args.end())
            return false;

        if (m_args[tmp].type == typeid(nullptr))
            m_args[tmp].value = "set";
        else if (i+1 < argc)
        {
            if (m_args.find(argv[i+1]) != m_args.end())
                return false;

            m_args[tmp].value = argv[i+1];
            i++;
        }
        else return false;
    }

    return true;
}

std::optional<std::string> ArgParser::getVal(const std::string & arg_name)
{
    std::optional<std::string> res;

    if (m_args.find(arg_name) != m_args.end())
        res = m_args[arg_name].value;

    return res;
}

std::optional<int> ArgParser::getInt(const std::string & arg_name)
{
    std::optional<int> res;
    auto tmp = getVal(arg_name);

    if (tmp.has_value() && !tmp.value().empty())
        res = std::stoi(tmp.value());

    return res;
}

std::optional<int> ArgParser::getHex(const std::string & arg_name)
{
    std::optional<int> res;
    auto tmp = getVal(arg_name);

    if (tmp.has_value() && !tmp.value().empty())
        res = std::stoi(tmp.value(), nullptr, 16);

    return res;
}

std::optional<std::string> ArgParser::getString(const std::string & arg_name)
{
    std::optional<std::string> res;
    auto tmp = getVal(arg_name);
    if (tmp.has_value() && !tmp.value().empty())
        res = tmp.value();

    return res;
}

std::optional<bool> ArgParser::getBool(const std::string & arg_name)
{
    std::optional<bool> res;
    auto tmp = getVal(arg_name);
    if (tmp.has_value() && !tmp.value().empty())
    {
        if (tmp.value() == "true") res = true;
        else if (tmp.value() == "false") res = false;
        else
        {
            // wrong value
        }
    }

    return res;
}
