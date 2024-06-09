# Definiciones de variables
CXX = g++
CXXFLAGS = -I./fabrica -I./controllers -I./interfaces -I./dataTypes -std=c++11
TARGET = myprogram

# Lista de archivos fuente
SOURCES = main.cpp fabrica/fabrica.cpp controllers/CIniciarSesion.cpp dataTypes/fecha.cpp

# Genera la lista de archivos objeto correspondiente
OBJECTS = $(SOURCES:.cpp=.o)

# Regla principal
all: $(TARGET)

# Cómo construir el objetivo principal
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@

# Reglas para compilar archivos en subdirectorios
fabrica/%.o: fabrica/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

controllers/%.o: controllers/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

dataTypes/%.o: dataTypes/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla genérica para compilar archivos .cpp a .o en el directorio principal
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar los archivos de construcción
clean:
	rm -f $(TARGET) $(OBJECTS)


