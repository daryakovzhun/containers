UNAME := $(shell uname)

all: out

out:
	g++ -g -Wall -std=c++17 s21_set.cc -lgtest -lgmock -pthread -fprofile-arcs -ftest-coverage -g -fsanitize=address
	./a.out

test: out
	lcov -t report -o report.info -c -d .
	genhtml report.info -o finish

clean:
	rm -rf *.gcda *.gcno report.info a.out finish

html:
ifeq ($(UNAME), Linux)
	firefox finish/index.html
endif
ifeq ($(UNAME), Darwin)
	open finish/index.html
endif