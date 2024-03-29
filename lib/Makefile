all: llist requests

clean:
	@make -C llist clean
	@make -C requests clean

fclean: clean
	@make -C llist fclean
	@make -C requests fclean

llist:
	@make -C llist

requests:
	@make -C requests

.PHONY: all \
		clean \
		fclean \
		llist \
		requests