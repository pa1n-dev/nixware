CXX = emcc
OUTPUT = imgui.js
SRC_DIR := src
IMGUI_DIR := imgui
FILES_TO_DELETE := imgui.js imgui.wasm imgui.data

SOURCES = $(SRC_DIR)/main.cpp
SOURCES += $(SRC_DIR)/menu/menu.cpp
SOURCES += $(IMGUI_DIR)/backends/imgui_impl_glfw.cpp $(IMGUI_DIR)/backends/imgui_impl_opengl3.cpp
SOURCES += $(IMGUI_DIR)/freetype/imgui_freetype.cpp
SOURCES += $(IMGUI_DIR)/imgui.cpp $(IMGUI_DIR)/imgui_draw.cpp $(IMGUI_DIR)/imgui_widgets.cpp $(IMGUI_DIR)/imgui_tables.cpp

LIBS = -lGL -lfreetype
WEBGL_VER = -s USE_WEBGL2=1 -s USE_GLFW=3 -s FULL_ES3=1 -s USE_FREETYPE=1
USE_WASM = -s WASM=1

all: $(SOURCES) $(OUTPUT)

$(OUTPUT): $(SOURCES) 
	$(CXX) $(SOURCES) -std=c++17 -o $(OUTPUT) $(LIBS) $(WEBGL_VER) -O2 $(USE_WASM) -I $(IMGUI_DIR) -I $(IMGUI_DIR)/backends -I $(IMGUI_DIR)/freetype

clean:
	del $(FILES_TO_DELETE)

