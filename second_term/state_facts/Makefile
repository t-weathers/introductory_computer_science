CC = g++

main: state_facts.o run_facts.cpp
	$(CC) state_facts.o run_facts.cpp -o main
state_facts.o: state_facts.cpp state_facts.h
	$(CC) -c state_facts.cpp -o state_facts.o
clean:
	rm –f *.out state_facts.o
