#include <qi/applicationsession.hpp>

// Boost includes.
#include <boost/program_options.hpp>

#include "naoqi_navigation_gui.h"

using namespace naoqi_navigation_gui;

namespace po = boost::program_options;

int main(int argc, char **argv){

  std::string pepper_ip = "";
  if (std::getenv("PEPPER_IP") != NULL)
    pepper_ip = std::getenv("PEPPER_IP");
  
  po::options_description description("Options");
  description.add_options()
    ("help", "Displays this help message")
    ("pip", po::value<std::string>()->default_value(pepper_ip), "Robot IP address. Set IP here or for convenience, define PEPPER_IP as environment variable. On robot or Local Naoqi: use '127.0.0.1'.")
    ("pport", po::value<int>()->default_value(9559), "Naoqi port number.")
    ("map", po::value<std::string>(), "Map used for localization in YAML format with extension.")
    ("use_d2l", po::value<bool>()->default_value(false), "use depth2laser data.")
    ;
  
  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, description), vm);
  po::notify(vm);
  
  // --help option
  if (vm.count("help")){ 
    std::cout << description << std::endl; 
    return 0; 
  }

  // --map option
  std::string mapname;
  if (!vm.count("map")){ 
    std::cout << "No map provided. Exiting." << std::endl; 
    return 0; 
  }else {
    mapname =  vm["map"].as<std::string>();
  }

  bool use_d2l = vm["use_d2l"].as<bool>();
     
  ////////////
  //NAOqi session initialization
  const std::string pip = vm["pip"].as<std::string>();
  int pport = vm["pport"].as<int>();

  if (pip == ""){
    std::cerr << "PEPPER_IP not defined. Please, set robot ip through program options" << std::endl;
    exit(0);
  }
    
  std::string tcp_url("tcp://"+pip+":"+std::to_string(pport));

  qi::ApplicationSession app(argc, argv, 0, tcp_url);
  try {
    app.startSession();
  }
  catch (qi::FutureUserException e) {
    std::cerr << "Connection refused." << std::endl;
    exit(1);
  }

  std::cerr << "Connected to robot." << std::endl;

  qi::SessionPtr session = app.session();

  NAOqiNavigationGUI* navigation_gui = new NAOqiNavigationGUI(session);

  //get map
  navigation_gui->readMap(mapname);

  navigation_gui->initGUI();
  navigation_gui->setUseD2L(use_d2l);
  
  navigation_gui->subscribeServices();
  app.run();
  navigation_gui->unsubscribeServices();
  
}
