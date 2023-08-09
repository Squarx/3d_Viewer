.PHONY: install
CXX= g++
CXXFLAGS=  -Wall -Werror -Wextra  -std=c++17 -g
MAINSRC= $(wildcard main.cc model/calcmodel.cc )
EXECUTABLE= parcer
OBJECTS= $(patsubst %.cc, %.o, $(SRC))
TESTEXEC = s21_test_parcer
SRC= $(wildcard *.h)
TESTSRC= $(wildcard test/*.cc model/calcmodel.cc)
GTESTFLAGS = -lgtest -pthread
ALLFILE = $(wildcard *.cc **/*.cc *.h **/*.h *.cpp **/*.cpp)
VGRND= CK_FORK=no valgrind --vgdb=no\
				--leak-check=full --show-leak-kinds=all\
				--trace-children=yes --track-origins=yes\
				-v --verbose -q --quiet -s
ARCHIVE=Archive_CalcApp_v2_0
DIR=buil



main: clean
	$(CXX) $(CXXFLAGS1) $(MAINSRC) -o $(EXECUTABLE)
	./$(EXECUTABLE)


clean:
	rm -rf $(EXECUTABLE) $(OBJECTS) $(TESTEXEC) -rf *.gcda *.gcno report test.info $(LIBRARY) $(ARCHIVE)*
