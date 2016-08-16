LFLAGS = -lm -lfftw3  

main: main.cpp 
	g++ $(LFLAGS) -o $@ $(MOBLIB) $(SUBFILES) main.cpp $(LIBS) -Wall -W -pedantic -std=c++11 -O3 -g

# Clean-up rules
clean:
	rm -rf */*.o */*~
	rm -f *~ *.o

.PHONY: clean

