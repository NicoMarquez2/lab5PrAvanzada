# Definiciones de variables
CXX = g++
CXXFLAGS = -I./fabrica -I./controllers -I./interfaces -I./dataTypes -I./headers -I./implementaciones -std=c++11
LDFLAGS =
TARGET = myprogram
DATATYPES_DIR := dataTypes
CONTROLLERS_DIR := controllers
INTERFACES_DIR := interfaces
FABRICA_DIR := fabrica
HEADERS_DIR := headers
IMPLEMENTACIONES_DIR := implementaciones
MAIN_SOURCES := main.cpp

# Lista de archivos fuente
DATATYPES_SOURCES := $(wildcard $(DATATYPES_DIR)/*.cpp)
CONTROLLERS_SOURCES := $(wildcard $(CONTROLLERS_DIR)/*.cpp)
INTERFACES_SOURCES := $(wildcard $(INTERFACES_DIR)/*.cpp)
FABRICA_SOURCES := $(wildcard $(FABRICA_DIR)/*.cpp)
HEADERS_SOURCES := $(wildcard $(HEADERS_DIR)/*.cpp)
IMPLEMENTACIONES_SOURCES := $(wildcard $(IMPLEMENTACIONES_DIR)/*.cpp)
SOURCES := $(DATATYPES_SOURCES) $(CONTROLLERS_SOURCES) $(INTERFACES_SOURCES) $(FABRICA_SOURCES) $(IMPLEMENTACIONES_SOURCES) $(HEADERS_SOURCES) $(MAIN_SOURCES)

# Genera la lista de archivos objeto correspondiente
OBJECTS = $(SOURCES:.cpp=.o)

# Incluye automáticamente las dependencias
-include $(OBJECTS:.o=.d)

# Regla principal
all: $(TARGET)

# Cómo construir el objetivo principal
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $@

# Reglas para compilar archivos en subdirectorios
fabrica/%.o: fabrica/%.cpp
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

controllers/%.o: controllers/%.cpp
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

dataTypes/%.o: dataTypes/%.cpp
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

interfaces/%.o: interfaces/%.cpp
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

implementaciones/%.o: implementaciones/%.cpp
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

# Regla genérica para compilar archivos .cpp a .o en el directorio principal
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

# Regla para limpiar los archivos de construcción
clean:
	if exist $(TARGET) del /F /Q $(TARGET)
	for %%f in ($(OBJECTS)) do if exist %%f del /F /Q %%f
	for %%d in ($(OBJECTS:.o=.d)) do if exist %%d del /F /Q %%d