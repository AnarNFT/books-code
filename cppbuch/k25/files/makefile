# Compiliert alle .cpp-Dateien im aktuellen Verzeichnis, und zwar
# jede f�r sich, d.h. jede Datei mu� eine main-Funktion enthalten

include ../../make/mf_alle
ifeq "$(findstring Windows,$(OS))" "Windows"
CXXFLAGS+= -DWIN32
endif

