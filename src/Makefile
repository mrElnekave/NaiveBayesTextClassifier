# Makefile for the text classification project (Yamm/Nathan 2023)
#

CFLAGS=-std=c++11

make_ngram_stats: make_ngram_stats.cpp
	g++ $(CFLAGS) -o make_ngram_stats make_ngram_stats.cpp

install: make_ngram_stats
	install -s make_ngram_stats ../bin
