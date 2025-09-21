CXX = g++
CXXFLAGS = -Iincludes -std=c++11 -Wall -Wextra -pedantic

SRC = src
INC = includes

SRCS = divisao.cpp multiplicacao.cpp noh.cpp soma.cpp subtracao main.cpp

OBJS = main.o divisao.o multiplicacao.o noh.o soma.o subtracao.o
PROG = calc

$(PROG): $(OBJS)

	$(CXX) -o $(PROG) $(OBJS)

main.o: main.cpp

	$(CXX) $(CXXFLAGS) -c main.cpp

divisao.o: $(INC)/divisao.hpp $(SRC)/divisao.cpp

	$(CXX) $(CXXFLAGS) -c $(SRC)/divisao.cpp

multiplicacao.o: $(INC)/multiplicacao.hpp $(SRC)/multiplicacao.cpp

	$(CXX) $(CXXFLAGS) -c $(SRC)/multiplicacao.cpp

noh.o: $(INC)/noh.hpp $(SRC)/noh.cpp

	$(CXX) $(CXXFLAGS) -c $(SRC)/noh.cpp

subtracao.o: $(INC)/subtracao.hpp $(SRC)/subtracao.cpp

	$(CXX) $(CXXFLAGS) -c $(SRC)/subtracao.cpp

soma.o: $(INC)/soma.hpp $(SRC)/soma.cpp
	$(CXX) $(CXXFLAGS) -c $(SRC)/soma.cpp

clean:
	rm -f $(OBJS) $(PROG)

visualizar:
	dot -Tpng arvore.dot -o arvore.png
