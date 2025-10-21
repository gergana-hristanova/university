# ==============================================================================
# MAKEFILE: DIAGNOSTIC MODE (NO @ SYMBOLS)
# Run this and COPY THE ENTIRE TERMINAL OUTPUT to find the specific linker error.
# ==============================================================================

# --- Project Configuration ---
TARGET = pusheen_app
SRCS = main.cpp sdlwrapper.cpp
OBJS = $(SRCS:.cpp=.o)

# --- Directory Paths ---
INC_DIR = src/include
LIB_DIR = src/lib 


# --- Compiler and Linker Flags ---
CXXFLAGS = -std=c++17 -Wall -I$(INC_DIR)

# LDFLAGS: Comprehensive list for MinGW/G++ (correct order and dependencies)
LDFLAGS = -L$(LIB_DIR) \
          -lSDL2_ttf -lSDL2_image -lSDL2main -lSDL2 \
          -lmingw32 -lopengl32 -luser32 -lgdi32 -lwinmm -ldxguid -lsetupapi -lshell32


# ==============================================================================
# --- Build Rules ---
# ==============================================================================

# The default target: Link object files to create the executable
$(TARGET): $(OBJS)
	echo "--> Linking $(TARGET)"
	# 🛑 The detailed error will appear after this g++ command 🛑
	g++ $(OBJS) $(LDFLAGS) -o $(TARGET)
	echo "--------------------------------------------------------"
	echo "Build attempt finished. COPY the terminal output above."
	echo "--------------------------------------------------------"


# Rule for compiling .cpp files into .o object files
%.o: %.cpp
	echo "--> Compiling $<"
	g++ $(CXXFLAGS) -c $< -o $@


# Clean rule: Removes all generated files
.PHONY: clean
clean:
	echo "--> Cleaning up build files"
	rm -f $(OBJS) $(TARGET) main.obj