all: llist map requests 

clean:
	@make -C llist clean
	@make -C requests clean
	@make -C map clean

fclean: clean
	@make -C llist fclean
	@make -C requests fclean
	@make -C map fclean

llist:
	@make -C llist

requests:
	@make -C requests

map:
	@make -C map

.PHONY: all \
		clean \
		fclean \
		llist \
		requests \
		map
