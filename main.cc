#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>



int main() {

  std::vector<double> vertex_{};
  std::string line;
  std::ifstream in("cube.obj");
//^v(\s(-?(0|([1-9]\d*))(\.\d+)?)){3}$
  if (in.is_open()) {
    std::regex v_pattern(R"(^v(\s(-?(0|([1-9]\d*))(\.\d+)?)){3})");

    while (std::getline(in, line)) {
      std::smatch match_;

      if (std::regex_search(line, match_, v_pattern)) {
        std::cout << line << std::endl;

        std::string shifted_line = line.substr(2);
        std::istringstream iss(shifted_line);
        std::string token;

        while (std::getline(iss, token, ' ')) {
          vertex_.push_back(std::stod(token));
        }
      }

    }

    in.close();
  } else {
    std::cerr << "Unable to open file cube.obj" << std::endl;
    return 1;
  }

  for(auto& i: vertex_) {
    std::cout << i << std::endl;
  }
  return 0;
}