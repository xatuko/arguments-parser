#ifndef ARG_PARSER_HPP
#define ARG_PARSER_HPP

#include <string>
#include <unordered_map>
#include <typeindex>
#include <vector>
#include <optional>

struct argDescr_t
{
    std::type_index type;
    std::string     value;

    argDescr_t() : type(typeid(nullptr)), value("") { }
    argDescr_t(std::type_index ti, std::string val) : type(ti), value(val) { }
};

class ArgParser
{
  public:
    ArgParser(){ }
    ~ArgParser() { }

    bool init(int argc, char ** argv);
    std::optional<int> getInt(const std::string & arg_name);
    std::optional<int> getHex(const std::string & arg_name);
    std::optional<std::string> getString(const std::string & arg_name);
    std::optional<bool> getBool(const std::string & arg_name);

  private:
  // Fields
    std::string m_app_path;

    std::unordered_map<std::string, argDescr_t> m_args =
    {
        {"--help", {typeid(nullptr), ""}},
        {"--own_ip", {typeid(std::string), ""}},
        {"--own_port", {typeid(int), ""}},
        {"--rem_ip", {typeid(std::string), ""}},
        {"--rem_port", {typeid(int), ""}},
        {"--load_addr", {typeid(int), ""}},
        {"--debug", {typeid(bool), ""}},
        {"--show_info", {typeid(bool), ""}}
    };

  // Methods
    std::optional<std::string> getVal(const std::string & arg_name);

};

#endif // ARG_PARSER_HPP