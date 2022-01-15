#include "config.h"

void Config::InitLogger(){
  boost::log::add_file_log("sampleee.log");
  boost::log::core::get()->set_filter(boost::log::trivial::severity >= boost::log::trivial::info);
}
