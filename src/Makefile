all: test_queue

test_queue:
	g++ queue/s21_queue.cpp tests/s21_queue_tests.cpp -lgtest -fprofile-arcs -ftest-coverage
	./a.out
	lcov -t report -o report.info -c -d .
	genhtml report.info -o finish

clean:
	rm -rf *.gcda *.gcno report.info a.out finish