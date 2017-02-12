PROJECT	= Aurora
CPP	= clang++
CPPFLAGS= -std=c++11 -Wall
LDFLAGS	= 
OBJS	=

$(PROJECT):$(OBJS) $(PROJECT).cpp
	$(CPP) $(CPPFLAGS) -o $(PROJECT).out $(OBJ) $(PROJECT).cpp $(LDFLAGS)
