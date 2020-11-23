#----------------------------------------------------------
# @file Makefile
# @author myasu
# @brief nif for e-RT3 API Makefile
# @version 0.1
# @date 2020-08-10
# 
# @copyright Copyright (c) 2020
#----------------------------------------------------------

CC				= gcc
CFLAGS			= -O4 -Wall -I/usr/local/include -shared -fPIC -I$(ERL_INCLUDE_PATH)
ERL_INCLUDE_PATH=$(shell elixir -e 'IO.puts [:code.root_dir, "/erts-", :erlang.system_info(:version), "/include"]')
DEST			= /usr/local/bin
LDFLAGS			= -L/usr/local/lib
LIBS			= -lm -lm3
OBJS			= nifm3.o relayio.o relayio.h
PROGRAM			= nifm3.so

all:			$(PROGRAM)

$(PROGRAM):		$(OBJS)
				$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) $(LIBS) -o $(PROGRAM)

clean:;			rm -f *.o *.c.* *~ $(PROGRAM)

install:		$(PROGRAM)
				install -s $(PROGRAM) $(DEST)

