SRC = src
BLD = build
PRG = prog.out
LIBS = -lGL -lglut -lGLU
SRCS = main.cpp 

VPATH = $(SRC)

all : $(PRG)

$(PRG) : $(BLD)/$(SRCS:.cpp=.o)
	gcc -o $(PRG) $< $(LIBS)

$(BLD)/%.o : %.cpp $(BLD)
	gcc -c $< -o $@

$(BLD) :
	mkdir $(BLD)

clean : 
	rm -rf $(BLD) $(PRG)
