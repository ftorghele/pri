Aufgabe 2
=========

__Lesen Sie Writing a C library (URL: <http://davidz25.blogspot.com/2011/07/writing-c-library-intro-conclusion-and.html>). Was halten Sie davon? Präsentieren Sie 5 wichtige, lehrreiche Hinweise. Ist der Artikel für die eigene Arbeit relevant? Welche Punkte sind ihnen unklar?__

- Es ist oft besser eine gut getestete Library zu verwenden als alles selbst zu implementieren. Man sollte dann aber immer noch aufpassen, das man diese auch richtig benutzt. Wenn man verschiedene Librarys verwendet muss man sicherstellen, das sich diese nicht gegenseitig behindern.

- Wenn man selbst eine Library schreibt muss jeder Daten-Typ der eingeführt wird über eine free() Methode verfügen. Das Speicher-Management sollte in der gesammten Library konsistent und gut dokumentiert sein, damit auch andere Entwickler die Library richtig verwenden.

- Dokumentiere valide und nicht valide Parameter und stelle Methoden zur Validierung bereit. Erstelle eine Policy wie bei falscher Verwendung der Library durch den Programmierer oder bei Laufzeit-Fehlern verfahren wird.

- Verstecke so viele Implementierungs-Details wie nur möglich vor den Benutzern deiner Library, damit sie nicht falsch verwendet werden kann. Stele sicher, das die Library erweiterbar bleibt ohne die bisherige API zu beeinflussen.

- Beginne so früh wie möglich eine Test-Suite zu schreiben. Starte die Test-Suite so oft wie möglich, idealerweise wird sie in das Build System integriert.

- Verwende gute Typen und Methoden Namen (besser selbsterklährend und lang als kurz und nichts-sagend). Versuche die Anzahl von Argumenten, die einer Methode übergeben werden niedrig zu halten (gegebenenfalls Hilfs-Typen einführen).

Der Artikel ist für unsere Arbeit auf jeden Fall relevant. Auch wenn ich nicht vor habe eine C/C++ Library zu schreiben enthällt dieser Artikel viele Hinweise, wie man sauberen Code schreiben kann und auf welche Dinge man aufpassen sollte.
