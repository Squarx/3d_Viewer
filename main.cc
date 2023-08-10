#include <fstream>
#include <iomanip>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

class ObjReader {
 public:
  ObjReader() = default;
  ObjReader(const std::string &file_path) : file_path_(file_path) {}
  void PrintFacets();
  void PrintVertex();
  int ParseFile();

 private:
  std::vector<double> vertex_{};
  std::vector<unsigned int> facets_{};
  std::string file_path_;
  bool ProcessVertex(const std::string &line);
  bool ProcessFacets(const std::string &line);
};

int ObjReader::ParseFile() {
  std::string line{};
  std::ifstream in(file_path_);

  if (in.is_open()) {
    while (std::getline(in, line)) {
      if (!ProcessVertex(line) && !ProcessFacets(line)) {
        continue;
      }
    }

    in.close();
  } else {
    std::cerr << "Unable to open file: " << file_path_ << std::endl;
    return 1;
  }
  return 0;
}

void ObjReader::PrintVertex() {
  printf("===================VERTEX===================\n");
  for (auto i = 0; i < vertex_.size(); ++i) {
    if (i % 3 == 0) {
      std::cout << std::endl;
    }
    printf("%-10f ", vertex_[i]);
  }
  std::cout << std::endl;

  printf("=============================================\n");
}

void ObjReader::PrintFacets() {
  printf("===================FACETS===================\n");
  for (auto i = 0; i < facets_.size(); ++i) {
    if (i % 6 == 0) {
      std::cout << std::endl;
    }
    printf("%-4u ", facets_[i]);
  }
  std::cout << std::endl;
  printf("=============================================\n");
}

bool ObjReader::ProcessFacets(const std::string &line) {
  if (line.compare(0, 2, "f ") == 0) {
    std::string shifted_line = line.substr(2);
    std::istringstream iss(shifted_line);
    std::string token;
    int added{};
    int first_id{};
    int prev_id{};

    int a = 0;

    getline(iss, token, ' ');
    if (token[0] != '/') {
      a -= 1;
      if (a < 0) {
        a += vertex_.size() / 3 + 1;
      }
      first_id = a;
      prev_id = a;
    }

    while (getline(iss, token, ' ')) {
      if (token[0] == '/') continue;
      int a = std::stoi(token);
      a -= 1;

      if (a < 0) {
        a += vertex_.size() / 3UL + 1;
      }

      facets_.push_back(prev_id);
      facets_.push_back(a);
      added += 2;
      prev_id = a;
    }

    if (added <= 2) {
      throw std::runtime_error("To low vertexes");
    }

    facets_.push_back(prev_id);
    facets_.push_back(first_id);
    return true;
  }
  return false;
}

bool ObjReader::ProcessVertex(const std::string &line) {
  if (line.compare(0, 2, "v ") == 0) {
    std::string shifted_line = line.substr(2);
    std::istringstream iss(shifted_line);
    while (getline(iss, shifted_line, ' ')) {
      vertex_.push_back(std::stod(shifted_line));
    }
    return true;
  }
  return false;
}

int main() {
  std::string line{"cube.obj"};
  ObjReader a{line};
  a.ParseFile();
  a.PrintVertex();
  a.PrintFacets();

  return 0;
}
