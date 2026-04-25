#1. Variabel Compiler
CXX = g++
CXXFLAGS = -I include -std=c++17 -Wall

# 2. Nama Hasil Akhir
TARGET = hidupjokowi

# 3. File Sumber
SRCS = main.cpp

# 4. Aturan Kompilasi
all:	$(TARGET)

$(TARGET):	$(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# 5. Perintah Pembersih (Windows)
clean:
	del /f /q hidupjokowi.exe
