all: testa_conta_palavras

testa_conta_palavras: testa_conta_palavras.cpp conta_palavras.o
	g++ -std=c++11 -Wall -ftest-coverage -fprofile-arcs conta_palavras.o testa_conta_palavras.cpp -o testa_conta_palavras
	./testa_conta_palavras

conta_palavras.o: conta_palavras.cpp conta_palavras.hpp
	g++ -std=c++11 -Wall -ftest-coverage -fprofile-arcs -c conta_palavras.cpp -o conta_palavras.o

compile: testa_conta_palavras.cpp conta_palavras.o
	g++ -std=c++11 -Wall conta_palavras.o testa_conta_palavras.cpp -o testa_conta_palavras

test: testa_conta_palavras
	./testa_conta_palavras

cpplint: testa_conta_palavras.cpp conta_palavras.cpp conta_palavras.hpp
	python3 cpplint.py --exclude=catch.hpp *.*

gcov: testa_conta_palavras.cpp conta_palavras.cpp conta_palavras.hpp 
	g++ -std=c++11 -Wall -ftest-coverage -fprofile-arcs -c conta_palavras.cpp 
	g++ -std=c++11 -Wall -ftest-coverage -fprofile-arcs conta_palavras.o testa_conta_palavras.cpp -o testa_conta_palavras
	./testa_conta_palavras
	gcov -o . conta_palavras.cpp | grep -A1 "File.*conta_palavras\.cpp"
	find . -name "*.gcov" ! -name "conta_palavras.cpp.gcov" -exec rm {} +

debug: testa_conta_palavras.cpp conta_palavras.cpp conta_palavras.hpp 
	g++ -std=c++11 -Wall -g -c conta_palavras.cpp -o conta_palavras.o
	g++ -std=c++11 -Wall -g conta_palavras.o testa_conta_palavras.cpp -o testa_conta_palavras
	gdb testa_conta_palavras

cppcheck: testa_conta_palavras.cpp conta_palavras.cpp conta_palavras.hpp
	cppcheck --enable=warning .

valgrind: testa_conta_palavras
	valgrind --leak-check=yes --log-file=valgrind.rpt testa_conta_palavras

clean:
	rm -rf *.o *.exe *.gc* testa_conta_palavras
