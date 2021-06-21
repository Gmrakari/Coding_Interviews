src = 122_best-time-to-buy-and-sell-stock-ii.cpp
obj = 122_best-time-to-buy-and-sell-stock-ii.o

CC = g++

targer = test 

CFLAG = -Wall

$(targer) : $(obj)
	$(CC) $^ -o $@
	rm -f $(obj) 
	@echo "end to compile!"

%.o : %.cpp
	@echo "start compiling!"
	$(CC) -c $(CFLAG) $< -o $@

.PHONY:clean
clean:
	rm -f test 
