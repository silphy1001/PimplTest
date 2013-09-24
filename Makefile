CC = gcc
CFLAGS = -Wall -g -Werror
TARGET = pimpl_test

INCLUDEDIR = inc
HEADERS = $(wildcard inc/*.h)
SOURCES = $(wildcard src/*.c)
OBJFILES = $(SOURCES:%.c=%.o)
PRIV_HEADERS = $(wildcard src/*.h)

all: $(TARGET) $(OBJFILES) 

$(TARGET): $(OBJFILES)
	$(CC) -o $@ $(OBJFILES)
	@echo Complete linking

$(OBJFILES):    %.o: %.c $(HEADERS)
	@echo Compiling $@ from $<..
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -c -o $@ $<
	@echo Complete compiling

$(OBJFILES): $(HEADERS) $(PRIV_HEADERS)

install : $(TARGET)
	@mv $(TARGET) bin/
	@echo Complete installing

clean : 
	@rm -rf $(OBJFILES) bin/$(TARGET) $(TARGET) *~ *.d .dep
	@echo Complete cleaning

