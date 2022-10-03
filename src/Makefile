all: test

test:
	g++ queue/s21_queue.cc  tests/main_tests.cc -lgtest -fprofile-arcs -ftest-coverage
	./a.out
	lcov -t report -o report.info -c -d .
	genhtml report.info -o finish

clean:
	rm -rf *.gcda *.gcno report.info a.out finish