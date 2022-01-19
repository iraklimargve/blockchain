CC = g++
CFLAGS = -Wall -g
OBJDIR = build/
mainexe: $(OBJDIR)main.o $(OBJDIR)home.o $(OBJDIR)config.o
	$(CC) $(CFLAGS) -DBOOST_LOG_DYN_LINK -o $(OBJDIR)mainexe $(OBJDIR)main.o $(OBJDIR)home.o $(OBJDIR)config.o -lboost_log_setup -lboost_log -lpthread -lboost_thread -lpqxx -lpq
$(OBJDIR)main.o: main.cpp
	$(CC) $(CFLAGS) -DBOOST_LOG_DYN_LINK -c main.cpp -o $(OBJDIR)main.o -lboost_log -lpthread -lboost_thread
$(OBJDIR)home.o: home.cpp
	$(CC) $(CFLAGS) -DBOOST_LOG_DYN_LINK -c home.cpp -o $(OBJDIR)home.o -lboost_log_setup -lboost_log -lpthread -lboost_thread
$(OBJDIR)config.o: config.cpp
	$(CC) $(CFLAGS) -DBOOST_LOG_DYN_LINK -c config.cpp -o $(OBJDIR)config.o -lboost_log_setup -lboost_log -lpthread -lboost_thread
