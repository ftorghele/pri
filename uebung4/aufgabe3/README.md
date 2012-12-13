Aufgabe 3
=========

Implementieren Sie eine Template-Klasse RingBuffer (auch circular buffer genannt für beliebige Datentypen, Details siehe <http://en.wikipedia.org/wiki/Circular_buffer>).

* Überprüfen Sie ihre Klasse mit sinnvollen self-checking Tests. Überlegen und Implementieren Sie die Tests bevor Sie die Klasse ausimplementieren!

* Das Verhalten bei Einfügen wenn der Buffer voll ist soll als Policy ausgefüphrt werden: entweder ignorieren, einen Fehler/Exception liefern, oder das alteste Element überschreiben. 

* Das Verhalten bei Lesen wenn der Buffer leer ist soll als Policy ausgefuhrt werden: entweder einen Fehler/Exception liefern oder einen Default-Wert zuruckliefern.
