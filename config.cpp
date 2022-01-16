#include "config.h"

void Config::InitLogger(){

  boost::log::add_file_log(
    boost::log::keywords::file_name = "sampleee.log",
    boost::log::keywords::open_mode = std::ios_base::app,
    boost::log::keywords::format = "[%TimeStamp%]: %Message%",
    boost::log::keywords::auto_flush = true
  );
  // boost::log::core::get()->add_global_attribute("TimeStamp", boost::log::attributes::local_clock());

  // boost::log::core::get()->set_filter(boost::log::trivial::severity >= boost::log::trivial::info);
}
