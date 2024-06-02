# Define the compiler and the compiler flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Define the target executable
TARGET = mergeable_heap

# Define the source files
SRCS = main.cpp MergeableHeap.cpp

# Define the object files
OBJS = $(SRCS:.cpp=.o)

# Default target to build the executable
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to build the object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to clean the build
clean:
	rm -f $(TARGET) $(OBJS)

# Phony targets
.PHONY: all clean
