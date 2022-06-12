CC = g++
CFLAGS = -Wall -g 
OBJ1 = main.o Client.o CMDConnectClient.o CMDopenDataServer.o CMDvar.o Command.o dataBase.o Lexer.o \
parser.o Server.o var.o variables.o CMDequal.o ShuntingYard.o CMDsleep.o CMDwhile.o conditions.o CMDprint.o expression.o
SRC1 = main.cpp Client.cpp commands/CMDConnectClient.cpp commands/CMDopenDataServer.cpp commands/CMDvar.cpp commands/Command.cpp dataBase.cpp Lexer.cpp \
parser.cpp Server.cpp var.cpp variables.cpp commands/CMDequal.cpp ShuntingYard.cpp commands/CMDsleep.cpp commands/CMDwhile.cpp conditions.cpp \
commands/CMDprint.cpp expression.cpp commands/CMDprint.cpp

all: main

main: $(OBJ1)
	$(CC) $(CFLAGS) $(OBJ1) -pthread  -o main

main.o: 
	$(CC) $(CFLAGS) -c main.cpp

Lexer.o:
	$(CC) $(CFLAGS) -c Lexer.cpp

parser.o:
	$(CC) $(CFLAGS) -c parser.cpp

Server.o:
	$(CC) $(CFLAGS) -pthread -c Server.cpp

Client.o:
	$(CC) $(CFLAGS) -pthread -c Client.cpp

dataBase.o:
	$(CC) $(CFLAGS) -c dataBase.cpp

var.o:
	$(CC) $(CFLAGS) -c var.cpp

variables.o:
	$(CC) $(CFLAGS) -c variables.cpp

ShuntingYard.o:
	$(CC) $(CFLAGS) -c ShuntingYard.cpp

Command.o:
	$(CC) $(CFLAGS) -c commands/Command.cpp

CMDConnectClient.o:
	$(CC) $(CFLAGS) -pthread -c commands/CMDConnectClient.cpp

CMDopenDataServer.o:
	$(CC) $(CFLAGS) -pthread -c commands/CMDopenDataServer.cpp

CMDvar.o:
	$(CC) $(CFLAGS) -c commands/CMDvar.cpp

CMDequal.o:
	$(CC) $(CFLAGS) -c commands/CMDequal.cpp

CMDsleep.o:
	$(CC) $(CFLAGS) -pthread -c commands/CMDsleep.cpp

CMDprint:
	$(CC) $(CFLAGS) -c commands/CMDprint.cpp

CMDwhile.o:
	$(CC) $(CFLAGS) -c commands/CMDwhile.cpp

CMDprint.o:
	$(CC) $(CFLAGS) -c commands/CMDprint.cpp

conditions.o:
	$(CC) $(CFLAGS) -c conditions.cpp

expression.o:
	$(CC) $(CFLAGS) -c expression.cpp

depend:
	$(CC) $(CFLAGS) -MM $(SRC1) >> Makefile 

clean:
	rm *.o




Client.o: Client.cpp Client.h
dataBase.o: dataBase.cpp dataBase.h
Lexer.o: Lexer.cpp Lexer.h
Server.o: Server.cpp Server.h dataBase.h
var.o: var.cpp var.h Client.h dataBase.h
variables.o: variables.cpp variables.h var.h Client.h dataBase.h
ShuntingYard.o: ShuntingYard.cpp ShuntingYard.h
conditions.o: conditions.cpp conditions.h variables.h var.h Client.h \
 dataBase.h
expression.o: expression.cpp expression.h ShuntingYard.h variables.h \
 var.h Client.h dataBase.h
main.o: main.cpp parser.h commands/Command.h commands/../variables.h \
 commands/../var.h commands/../Client.h commands/../dataBase.h \
 commands/CMDopenDataServer.h commands/Command.h commands/../Server.h \
 commands/CMDConnectClient.h commands/CMDvar.h commands/../expression.h \
 commands/../ShuntingYard.h commands/../variables.h commands/CMDequal.h \
 commands/../Client.h commands/CMDsleep.h commands/CMDwhile.h \
 commands/../conditions.h commands/../Lexer.h commands/../parser.h \
 commands/CMDprint.h commands/../ShuntingYard.h Lexer.h
Client.o: Client.cpp Client.h
CMDConnectClient.o: commands/CMDConnectClient.cpp \
 commands/CMDConnectClient.h commands/Command.h commands/../variables.h \
 commands/../var.h commands/../Client.h commands/../dataBase.h
CMDopenDataServer.o: commands/CMDopenDataServer.cpp \
 commands/CMDopenDataServer.h commands/Command.h commands/../variables.h \
 commands/../var.h commands/../Client.h commands/../dataBase.h \
 commands/../Server.h
CMDvar.o: commands/CMDvar.cpp commands/CMDvar.h commands/Command.h \
 commands/../variables.h commands/../var.h commands/../Client.h \
 commands/../dataBase.h commands/../expression.h \
 commands/../ShuntingYard.h commands/../variables.h
Command.o: commands/Command.cpp commands/Command.h \
 commands/../variables.h commands/../var.h commands/../Client.h \
 commands/../dataBase.h
dataBase.o: dataBase.cpp dataBase.h
Lexer.o: Lexer.cpp Lexer.h
parser.o: parser.cpp parser.h commands/Command.h commands/../variables.h \
 commands/../var.h commands/../Client.h commands/../dataBase.h \
 commands/CMDopenDataServer.h commands/Command.h commands/../Server.h \
 commands/CMDConnectClient.h commands/CMDvar.h commands/../expression.h \
 commands/../ShuntingYard.h commands/../variables.h commands/CMDequal.h \
 commands/../Client.h commands/CMDsleep.h commands/CMDwhile.h \
 commands/../conditions.h commands/../Lexer.h commands/../parser.h \
 commands/CMDprint.h commands/../ShuntingYard.h
Server.o: Server.cpp Server.h dataBase.h
var.o: var.cpp var.h Client.h dataBase.h
variables.o: variables.cpp variables.h var.h Client.h dataBase.h
CMDequal.o: commands/CMDequal.cpp commands/CMDequal.h commands/Command.h \
 commands/../variables.h commands/../var.h commands/../Client.h \
 commands/../dataBase.h commands/../Client.h commands/../expression.h \
 commands/../ShuntingYard.h commands/../variables.h
ShuntingYard.o: ShuntingYard.cpp ShuntingYard.h
CMDsleep.o: commands/CMDsleep.cpp commands/CMDsleep.h commands/Command.h \
 commands/../variables.h commands/../var.h commands/../Client.h \
 commands/../dataBase.h
CMDwhile.o: commands/CMDwhile.cpp commands/CMDwhile.h commands/Command.h \
 commands/../variables.h commands/../var.h commands/../Client.h \
 commands/../dataBase.h commands/../conditions.h commands/../variables.h \
 commands/../Lexer.h commands/../parser.h commands/../commands/Command.h \
 commands/../commands/CMDopenDataServer.h commands/../commands/Command.h \
 commands/../commands/../Server.h commands/../commands/../dataBase.h \
 commands/../commands/CMDConnectClient.h commands/../commands/CMDvar.h \
 commands/../commands/../expression.h \
 commands/../commands/../ShuntingYard.h \
 commands/../commands/../variables.h commands/../commands/CMDequal.h \
 commands/../commands/../Client.h commands/../commands/CMDsleep.h \
 commands/../commands/CMDwhile.h commands/../commands/CMDprint.h \
 commands/../commands/../ShuntingYard.h
conditions.o: conditions.cpp conditions.h variables.h var.h Client.h \
 dataBase.h
CMDprint.o: commands/CMDprint.cpp commands/CMDprint.h commands/Command.h \
 commands/../variables.h commands/../var.h commands/../Client.h \
 commands/../dataBase.h commands/../ShuntingYard.h
expression.o: expression.cpp expression.h ShuntingYard.h variables.h \
 var.h Client.h dataBase.h
