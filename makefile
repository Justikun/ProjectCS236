NUM?=1
numbers70=1 3 4 5 6 7
numbers90=1 2 3
number100=1 2

test70=1-70
test90=1-90
test100=1-100

run70:
	for number in $(numbers70); \
	do \
		./project$(NUM) $(test70)/input$$number.txt > $(test70)/out.txt ; \
		diff $(test70)/answer$$number.txt $(test70)/out.txt || (echo "diff failed on test $$number \n") ; \
	done
	rm $(test70)/out.txt

run90:
	for number in $(numbers90); \
	do \
		./project$(NUM) $(test90)/input$$number.txt > $(test90)/out.txt ; \
		diff $(test90)/answer$$number.txt $(test90)/out.txt || (echo "diff failed on test $$number \n") ; \
	done
	rm $(test90)/out.txt

run100:
	for number in $(number100); \
	do \
		./project$(NUM) $(test100)/input$$number.txt > $(test100)/out.txt ; \
		diff $(test100)/answer$$number.txt $(test100)/out.txt || (echo "diff failed on test $$number \n") ; \
	done
	rm $(test100)/out.txt

compile:
	g++ -Wall -Werror -std=c++17 -g *.cpp -g Automata/*.cpp -o project$(NUM)