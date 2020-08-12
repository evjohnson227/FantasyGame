# Name:		Eric Johnson
# Date:		5/21/19
# Description:	Make file for Fantasy combat tournament

# Adapted from Lecture: Makefiles
CXX = g++
CXXFLAGS = -std=c++0x
CFLAGS = -g

OBJS = Vampire.o Barbarian.o Blue_Men.o Medusa.o Harry_Potter.o inputValidation.o menu.o CharacterQueue.o Tournament.o

SRCS = main.cpp  Vampire.cpp Barbarian.cpp Blue_Men.cpp Medusa.cpp Harry_Potter.cpp inputValidation.cpp menu.cpp Game.cpp CharacterQueue.cpp Tournament.cpp

HEADERS = Character.hpp Vampire.hpp Barbarian.hpp Blue_Men.hpp Medusa.hpp Harry_Potter.hpp inputValidation.hpp menu.hpp Game.hpp CharacterNode.hpp CharacterQueue.hpp Tournament.hpp

default: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o project4

debug: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} ${CFLAGS} -o debug

Vampire.o: Vampire.cpp Vampire.hpp Character.hpp
	${CXX} ${CXXFLAGS} -c Vampire.cpp

Barbarian.o: Barbarian.cpp Barbarian.hpp Character.hpp
	${CXX} ${CXXFLAGS} -c Barbarian.cpp

Blue_Men.o: Blue_Men.cpp Blue_Men.hpp Character.hpp
	${CXX} ${CXXFLAGS} -c Blue_Men.cpp

Medusa.o: Medusa.cpp Medusa.hpp Character.hpp
	${CXX} ${CXXFLAGS} -c Medusa.cpp

Harry_Potter.o: Harry_Potter.cpp Harry_Potter.hpp Character.hpp
	${CXX} ${CXXFLAGS} -c Harry_Potter.cpp 

inputValidation.o: inputValidation.cpp inputValidation.hpp
	${CXX} ${CXXFLAGS} -c inputValidation.cpp

menu.o: menu.cpp menu.hpp inputValidation.hpp
	${CXX} ${CXXFLAGS} -c menu.cpp

Game.o: Game.cpp Game.hpp inputValidation.hpp menu.hpp Character.hpp Vampire.hpp Barbarian.hpp Blue_Men.hpp Medusa.hpp Harry_Potter.hpp
	${CXX} ${CXXFLAGS} -c Game.cpp

CharacterQueue.o: Character.hpp CharacterQueue.cpp CharacterQueue.hpp CharacterNode.hpp
	${CXX} ${CXXFLAGS} -c CharacterQueue.cpp

Tournament.o: Tournament.hpp Tournament.cpp Character.hpp CharacterQueue.hpp CharacterNode.hpp 
	${CXX} ${CXXFLAGS} -c Tournament.cpp
clean:
	${RM} project4
	${RM} debug
	${RM} ${OBJS}

