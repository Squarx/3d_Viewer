//
// Created by DimasX on 10.08.2023.
//

#include "filereader.h"

bool FileReader::ProcessFacets(const std::string &line) {
  if (line.compare(0, 2, "f ") == 0) {
    std::string shifted_line = line.substr(2);
    std::istringstream iss(shifted_line);
    std::string token;
    int added{};
    int first_id{};
    int prev_id{};
    bool is_first = true;
    int a = 0;

    while (getline(iss, token, ' ')) {
      if (token[0] == '/') continue;
      a = std::stoi(token);
      a -= 1;

      if (a < 0) {
        a += figure.GetVertices().size() / 3UL + 1;
      }
      if (is_first) {
        first_id = a;
        is_first = false;
      } else {
        figure.AddEdge(Edge(prev_id, a));
        added += 2;
      }
      prev_id = a;

    }

    if (added <= 2) {
      throw std::runtime_error("To low vertexes");
    }
    figure.AddEdge(Edge(prev_id, first_id));
    return true;
  }
  return false;
}

bool FileReader::ProcessVertex(const std::string &line) {
  if (line.compare(0, 2, "v ") == 0) {
    std::vector<double> coord{};
    std::string shifted_line = line.substr(2);
    std::istringstream iss(shifted_line);
    while (getline(iss, shifted_line, ' ')) {
      coord.push_back(std::stod(shifted_line));
    }

    if (coord.size() > 3) {
      throw std::runtime_error("Invalid vertex");
    }
    figure.AddVertex(Vertex(coord[0],coord[1],coord[2]));
    return true;
  }
  return false;
}