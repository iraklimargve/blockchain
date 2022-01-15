#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>


class Config{
public:
  static Config& GetInstance(){
    static Config instance;
    return instance;
  }
  void InitLogger();
private:
  Config() = default;
public:
  Config(Config const&) = delete;
  void operator=(Config const&) = delete;
};
