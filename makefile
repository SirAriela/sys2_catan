CXX=clang++
CXXFLAGS=-std=c++11 -Werror -Wsign-conversion -pedantic
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99
LDLIBS = -pthread


SOURCES= Building.hpp Dice.cpp Point.hpp Player.cpp myTest.cpp Recource.hpp DevelopmentCard.hpp Tile.cpp Road.hpp Map.cpp Demo.cpp Deck.cpp 
OBJECTS=$(subst .cpp,.o,$(SOURCES))

#run: demo
#	./$^

demo:Demo.o Dice.o Player.o Map.o Tile.o Deck.o
	$(CXX) $(CXXFLAGS) $^ -o demo

#test: TestCounter.o Test.o $(OBJECTS)
#	$(CXX) $(CXXFLAGS) $^ -o test

# my_demo: Graph.o Algorithms.o demo.o
# 	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o my_demo

my_test: Dice.o Player.o Map.o Tile.o Deck.o myTest.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o my_test
tidy:
	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

valgrind: demo 
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o my_test demo