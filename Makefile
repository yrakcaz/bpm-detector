BIN=bpm-detector
CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -std=c++11 -pedantic -Iinclude/
LDFLAGS=-lsndfile
SRC=src/detector.cc src/soundsystem.cc src/main.cc
OBJ=$(SRC:.cc=.o)
TAR=yrakcaz-$(BIN)
PREFIX=/usr/local

-include makefile.rules

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(BIN) $^ $(LDFLAGS)

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $^

clean:
	$(RM) $(OBJ) $(BIN) $(TAR).tar.bz2

distclean: clean
	$(RM) makefile.rules

install:
	cp $(BIN) $(PREFIX)/bin

uninstall:
	$(RM) $(PREFIX)/bin/$(BIN)

export:
	git archive HEAD --prefix=$(TAR)/ | bzip2 > $(TAR).tar.bz2

.PHONY: all clean distclean export install uninstall
