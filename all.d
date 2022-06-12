main.o: main.cpp parser.h Command.h variables.h var.h Client.h dataBase.h \
 CMDopenDataServer.h Server.h CMDConnectClient.h CMDvar.h CMDequal.h \
 ShuntingYard.h CMDsleep.h CMDwhile.h conditions.h Lexer.h
 
Client.o: Client.cpp Client.h

CMDConnectClient.o: CMDConnectClient.cpp CMDConnectClient.h Command.h \
 variables.h var.h Client.h dataBase.h
 
CMDopenDataServer.o: CMDopenDataServer.cpp CMDopenDataServer.h Command.h \
 variables.h var.h Client.h dataBase.h Server.h
 
CMDvar.o: CMDvar.cpp CMDvar.h Command.h variables.h var.h Client.h \
 dataBase.h
 
Command.o: Command.cpp Command.h variables.h var.h Client.h dataBase.h

dataBase.o: dataBase.cpp dataBase.h

Lexer.o: Lexer.cpp Lexer.h

parser.o: parser.cpp parser.h Command.h variables.h var.h Client.h \
 dataBase.h CMDopenDataServer.h Server.h CMDConnectClient.h CMDvar.h \
 CMDequal.h ShuntingYard.h CMDsleep.h CMDwhile.h conditions.h Lexer.h
 
Server.o: Server.cpp Server.h dataBase.h

var.o: var.cpp var.h Client.h dataBase.h

variables.o: variables.cpp variables.h var.h Client.h dataBase.h

CMDequal.o: CMDequal.cpp CMDequal.h Command.h variables.h var.h Client.h \
 dataBase.h ShuntingYard.h
 
ShuntingYard.o: ShuntingYard.cpp ShuntingYard.h

CMDsleep.o: CMDsleep.cpp CMDsleep.h Command.h variables.h var.h Client.h \
 dataBase.h
 
CMDwhile.o: CMDwhile.cpp CMDwhile.h Command.h variables.h var.h Client.h \
 dataBase.h conditions.h Lexer.h parser.h CMDopenDataServer.h Server.h \
 CMDConnectClient.h CMDvar.h CMDequal.h ShuntingYard.h CMDsleep.h
 
conditions.o: conditions.cpp conditions.h variables.h var.h Client.h \
 dataBase.h
