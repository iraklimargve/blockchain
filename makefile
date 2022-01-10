CC = g++
CFLAGS = -Wall -g
OBJDIR = build/
maiin: $(OBJDIR)main.o $(OBJDIR)home.o
	$(CC) $(CFLAGS) -o $(OBJDIR)maiin $(OBJDIR)main.o $(OBJDIR)home.o
$(OBJDIR)main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o $(OBJDIR)main.o
$(OBJDIR)home.o: home.cpp
	$(CC) $(CFLAGS) -c home.cpp -o $(OBJDIR)home.o
