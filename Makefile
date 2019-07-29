# Makefile for EECS 280 Machine Learning Project

CXX = g++
CXXFLAGS = -Wall -Werror -pedantic --std=c++11 -g -D_GLIBCXX_DEBUG


all: test

test: User_tests.exe Deal_tests.exe \
	main.exe

	./User_tests.exe
	./Deal_tests.exe

	./main.exe test_01.in > test_01.out
	diff -q test_01.out test_01.out.correct


User_tests.exe: Users.cpp User_tests.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

Deal_tests.exe: Deal_tests.cpp user.h
	$(CXX) $(CXXFLAGS) $< -o $@

main.exe: Users.cpp main.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@


# disable built-in rules
.SUFFIXES:

# these targets do not create any files
.PHONY: clean
clean :
		rm -vrf *.o *.exe *.gch *.dSYM *.stackdump *.out.txt

# Run style check tools
CPPCHECK ?= cppcheck
CPD ?= /usr/um/pmd-6.0.1/bin/run.sh cpd
OCLINT ?= /usr/um/oclint-0.13/bin/oclint
FILES := user.h Users_tests.cpp Deal_test.cpp main.cpp

sync :
		rsync \
	-rtv \
	--delete \
	--exclude '.git*' \
	--filter=':- .gitignore' \
	./ \
	dmmckinn@login.engin.umich.edu:p5-ml-copy/
