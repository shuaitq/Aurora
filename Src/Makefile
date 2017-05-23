PROJECT = Aurora
CPP = g++
CPPFLAGS = -std=c++11 -Wall
ifdef DEBUG
CPPFLAGS += -g
else
CPPFLAGS += -O2
endif
SRCS = Aurora.cpp \
       Core/Camera.cpp Core/Render.cpp \
       Utility/PPM.cpp Utility/ObjectFile.cpp Utility/SenceFile.cpp \
	   Light/DirectLight.cpp Light/PointLight.cpp Light/Light.cpp \
	   Model/Model.cpp Model/Texture.cpp Model/Face.cpp Model/Vertex.cpp
OBJS = $(SRCS:.cpp=.o)

$(PROJECT): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $@ $^

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -f $(OBJS)