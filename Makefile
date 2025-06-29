# Makefile for Sorting Algorithms Project

# Compiler settings
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2
TARGET = sorts
SOURCES = main.cpp Menu.cpp BubbleSort.cpp UpBubbleSort.cpp InsertionSort.cpp SelectionSort.cpp MergeSort.cpp QuickSort.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = Menu.h BubbleSort.h UpBubbleSort.h InsertionSort.h SelectionSort.h MergeSort.h QuickSort.h

# Default target
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)
	@echo "Build complete! Run with: ./$(TARGET)"

# Compile source files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJECTS) $(TARGET)
	@echo "Clean complete!"

# Install target (optional)
install: $(TARGET)
	cp $(TARGET) /usr/local/bin/

# Uninstall target (optional)
uninstall:
	rm -f /usr/local/bin/$(TARGET)

# Debug build
debug: CXXFLAGS += -g -DDEBUG
debug: $(TARGET)

# Release build (default optimization)
release: CXXFLAGS += -DNDEBUG
release: $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Run tests
test: $(TARGET)
	@echo "Running basic compilation and executable tests..."
	@if [ -f $(TARGET) ]; then echo "✓ Executable exists"; else echo "✗ Executable missing"; exit 1; fi
	@echo "✓ All tests passed!"

# Check for memory leaks (requires valgrind)
memcheck: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

# Show help
help:
	@echo "Available targets:"
	@echo "  all      - Build the project (default)"
	@echo "  clean    - Remove build files"
	@echo "  debug    - Build with debug information"
	@echo "  release  - Build optimized release version"
	@echo "  run      - Build and run the program"
	@echo "  test     - Run basic tests"
	@echo "  memcheck - Run with valgrind memory checker"
	@echo "  install  - Install to /usr/local/bin"
	@echo "  uninstall- Remove from /usr/local/bin"
	@echo "  help     - Show this help message"

# Declare phony targets
.PHONY: all clean debug release run test memcheck install uninstall help
