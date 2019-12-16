CC=g++
CPPFLAGS=-ansi -pedantic -Wall -std=c++11
#DEFINEMAP= -DMAP
MAIN=MenuCatalogue
SRCS=TrajetComp.cpp TrajetSimple.cpp MenuCatalogue.cpp Catalogue.cpp File.cpp
HEADERS=TrajetComp.h TrajetSimple.h Catalogue.h File.h

$(MAIN): $(SRCS) $(HEADERS)
	$(CC) -g  $(CPPFLAGS) $(DEFINEMAP) $(SRCS) -o $(MAIN)

.PHONY: clean
clean:
	rm *.o $(MAIN)
