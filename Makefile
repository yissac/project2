SRC = src
BLD = build
PRG = prog.out
LIBS = -lGL -lglut -lGLU -lFreeSOLID -I$(SRC) -LLIBDIR
SRCS = main.cpp 

VPATH = $(SRC)

all : $(PRG)

$(PRG) : $(addprefix $(BLD)/,$(SRCS:.cpp=.o))
	gcc -o $(PRG) $(addprefix $(BLD)/,$(SRCS:.cpp=.o)) $(LIBS)

$(BLD)/%.o : %.cpp $(BLD)
	gcc -c $< -o $@ $(LIBS)

$(BLD) :
	mkdir $(BLD)

clean : 
	rm -rf $(BLD) $(PRG)
