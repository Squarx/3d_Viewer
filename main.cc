#include <fstream>
#include <iomanip>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

bool ProcessVertex(std::vector<double> &vertex_, std::string line) {
  if (line[0] == 'v' && line[1] == ' ') {
    std::string shifted_line = line.substr(2);
    std::istringstream iss(shifted_line);
    while (getline(iss, shifted_line, ' ')) {
      vertex_.push_back(std::stod(shifted_line));
    }
    return true;
  }
  return false;
}


void ReadFacet(const std::string &line) {
  std::istringstream iss(line);
  iss.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
  std::vector<unsigned int> facets_{};
  int vertex_index{}, prev_vertex_index{}, first_vertex_index{};
  bool first_iteration = true;

  while (iss >> vertex_index) {
    vertex_index -= 1;
    //        if (vertex_index < 0) {
    //            vertex_index += vertexes_.size() + 1;
    //        }
    if (!first_iteration) {
      facets_.push_back(prev_vertex_index);
      facets_.push_back(vertex_index);
    } else {
      first_vertex_index = vertex_index;
      first_iteration = false;
    }
    prev_vertex_index = vertex_index;

    iss.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
  }
  facets_.push_back(prev_vertex_index);
  facets_.push_back(first_vertex_index);

  for (auto i : facets_) {
    std::cout << i << std::endl;
  }
}

// int main() {
// std::string s{"f 1 4 2"};
//     ReadFacet(s);
//
// }

int main() {
  std::vector<double> vertex_{};
  std::vector<unsigned int> facets_{};
  std::string line;
  std::ifstream in("cube.obj");
  //^v(\s(-?(0|([1-9]\d*))(\.\d+)?)){3}$

  if (in.is_open()) {
    std::regex v_pattern(R"(^v(\s(-?(0|([1-9]\d*))(\.\d+)?)){3})");

    while (std::getline(in, line)) {
      if (!ProcessVertex(vertex_, line)) {
        if (line.compare(0, 2, "f ") == 0) {
          std::cout << line << "\n";
          std::string shifted_line = line.substr(2);
          std::istringstream iss(shifted_line);
          std::string token;
          bool first_iteration = true;
          int first_id{};
          int prev_id{};

          while (getline(iss, token, ' ')) {
            int a = std::stoi(token);
            a-=1;
            if (first_iteration) {
              first_id = a;
              first_iteration = false;
            } else {
              facets_.push_back(prev_id);
              facets_.push_back(a);
            }
            prev_id = a;
            std::cout << a << std::endl;
          }
            facets_.push_back(prev_id);
            facets_.push_back(first_id);
        }
      }
    }

    in.close();
  } else {
    std::cerr << "Unable to open file cube.obj" << std::endl;
    return 1;
  }

  printf("===================VERTEX===================\n");
  for (auto i = 0; i < vertex_.size(); ++i) {
    if (i % 3 == 0) {
      std::cout << std::endl;
    }
    printf("%-10f ", vertex_[i]);
  }
  printf("=============================================\n");

  printf("===================FACETS===================\n");
  for (auto i = 0; i < facets_.size(); ++i) {
    if (i % 6 == 0) {
      std::cout << std::endl;
    }
    printf("%-4u ", facets_[i]);
  }
  printf("=============================================\n");
  return 0;
}