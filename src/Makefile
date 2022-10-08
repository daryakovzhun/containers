all: test

test:
	g++ tests/main_tests.cc -lgtest -lgmock -pthread -fprofile-arcs -ftest-coverage -fsanitize=address -g
	./a.out
	lcov -t report -o report.info -c -d .
	genhtml report.info -o finish

clean:
	rm -rf *.gcda *.gcno report.info a.out finish