PROGNAME = my_mastermind
SOURCES = $(PROGNAME).c utils.c

default:
	gcc -Wall -Wextra -Werror $(SOURCES) -o $(PROGNAME)

clean:
	@rm $(PROGNAME)