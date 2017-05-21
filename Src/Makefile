PROJECT = Aurora
CPP = g++
CPPFLAGS = -std=c++11 -Wall
ifdef DEBUG
CPPFLAGS += -g
else
CPPFLAGS += -O2
endif
SRCS = Aurora.cpp \
       Core/Camera.cpp Core/Object.cpp Core/Sence.cpp Core/Texture.cpp Core/Triangle.cpp Core/Vertex.cpp Core/Light.cpp Core/Render.cpp \
       Utility/PPM.cpp Utility/ObjectFile.cpp Utility/SenceFile.cpp \
	   Light/DirectLight.cpp Light/PointLight.cpp
OBJS = $(SRCS:.cpp=.o)

$(PROJECT): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $@ $^

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -f $(OBJS)