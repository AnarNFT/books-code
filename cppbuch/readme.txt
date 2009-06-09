

Konventionen:

Der Verzeichnisname gibt das Kapitel an. Zum Beispiel enth�lt das
Verzeichnis "cppbuch/k5 die Beispiele aus Kapitel 5.

In jedem Verzeichnis, das makefile enth�lt, kann die �bersetzung
durch den Aufruf
 make
angesto�en werden.
 make clean
l�scht alle erzeugten Dateien.

makemakefile erzeugt ein makefile f�r die Compilation *s�mtlicher*
Beispiele. 

ACHTUNG: In den Dateien cppbuch/make/mf_alle,
cppbuch/make/makeProject und cppbuch/make/include.mak m�ssen die
Verzeichnisnamen Ihrem System entsprechend angepasst werden!

Anschlie�end m�gliche Aufrufe:

      make
        �bersetzt s�mtliche Beispiele. Wenn Sie einen Multikern-
        prozessor haben, k�nnen Sie zum Beispiel
        make -j2 oder make -j4 f�r einen Dual- bzw. Quadcore-
        Rechner aufrufen, um den Vorgang zu bescchleunigen.

      make clean
        l�scht s�mtliche bei der �bersetzung erzeugte Dateien,
        soweit (noch) vorhanden

      make  2> error.log
        �bersetzt s�mtliche Beispiele und sammelt die Fehlermeldungen
        in der Datei error.log

      make > compile.log 2>&1
        �bersetzt s�mtliche Beispiele und sammelt alle Ausgaben
        einschlie�lich der Fehlermeldungen in der Datei compile.log

Erl�uterungen zu makemakefile finden Sie im Abschnitt
"Makefile f�r rekursive Aufrufe erzeugen" des Buchs.

######## EINSCHR�NKUNGEN BEI DER �BERSETZUNG! ############

Damit Sie sich nicht wundern, falls nicht alles �bersetzt wird:
Die Beispiele sind alle mit dem GNU C++-Compiler 4.3 �bersetzbar,
mit folgenden Ausnahmen/Einschr�nkungen:

1. Die Beispiele in den Verzeichnissen 
   k27/tuple
   k9/sharedptr
   k24/vermischtes
   k24/array2dmath/performancetest/array2d
   k24/array2dmath
   k33/uniqueptr
   setzen mindestens den GNU C++Compiler Version 4.4 voraus.
   (zur Zeit des Erscheinens des Buch nur f�r Linux erh�ltlich)
   Den richtigen Pfad zu dem Compiler bitte in der Datei
   make/mf_alle44
   korrigieren.

2. Das Beispiel mit static_assert DARF nicht �bersetzbar sein 
   (siehe Text dazu).

3. Der Performance-Vergleich im Verzeichnis
   k24/array2dmath/performancetest
   setzt sowohl GNU C++ Version 4.4 als auch die Blitz-Bibliothek voraus. 
   Bitte beachten Sie dazu die Installationshinweise.
   
   Bei der Standardinstallation mit install.exe von der Buch-DVD
   wird die Blitz-Bibliothek automatisch mit installiert. Damit 
   sind die Beispiele in k24/array2dmath/performancetest
   uebersetzbar, einschliesslich
   k24/array2dmath/performancetest/array2d, falls G++ 4.4 installiert ist.





