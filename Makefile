PROJECT = Aurora
CPP = clang++
CPPFLAGS = -std=c++11 -Wall
ifdef DEBUG
CPPFLAGS += -g
else
CPPFLAGS += -O2
endif
SRCS = Aurora.cpp \
Utility/PPM.cpp Utility/ObjectFile.cpp
OBJS = $(SRCS:.cpp=.o)

$(PROJECT): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $@ $^

%.o: %.cpp %.hpp
	$(CPP) $(CPPFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -f $(OBJS)
