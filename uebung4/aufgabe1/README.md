Aufgabe 1
=========

__Welche Bedeutungen hat das Schlusselwort static in C/C++ bei Klassen und Funktionen? Erklaren Sie anhand von Beispielen!__

Das Schlüsselwort static kommt in mehreren Bedeutungen vor: 

###__bei Funktionen und globalen Variablen__ 

```
// file.cpp
// die Funktion foo() ist überall sichtbar 
int foo() {
    return 42;
}

// die Funktion bar() ist nur innerhalb von file.cpp sichtbar 
static int bar() {
    return 123;
}

// die globale Variable var1 ist überall sichtbar 
int var1;

// die Variable var2 ist nur innerhalb von file.cpp sichtbar 
static int var2;
```

* static sollte für Funktionen verwendet werden, die nur innerhalb einer Datei (eines Moduls) Bedeutung haben 
* static Funktionen sind ausserhalb nicht sichtbar; es kann somit nicht zu Namenskonflikten kommen 
* Der Compiler kann evt. besseren Code erzeugen.

###__bei lokalen Variablen__ 

* static bei lokalen Variablen ändert die 'Lebenszeit'; die lokale Variable wird einmal bei Programmstart initialisiert und besteht bis Programmende 
* statische lokale Variablen sind aber wie bisher nur innerhalb der Funktion sichtbar

```
int foo() {
    static int aufrufzaehler = 0;
    aufrufzaehler++;
    return aufrufzaehler;
}
```
###__bei Methoden und Attributen einer Klasse__

* static bei Attributen einer Klasse bewirkt, dass sich alle Instanzen der Klasse den Wert dieses Attributs teilen 
* static bei Methoden bewirkt, dass diese ohne Instanzierung der Klasse aufgerufen werden können, aber nur auf statische Attribute der Klasse zugreifen können

```
class MyClass {
    public:     
        MyClass() { 
            instance_count++; 
        }
        static unsigned int getInstanceCount() {
            return instance_count;     
        }   
    private:       
        static unsigned int instance_count; 
};

// Initialisierung muss ausserhalb der Klasse stehen 
unsigned int MyClass::instance_count = 0; 

int main() {
    // erzeuge 3 Instanzen von MyClass 
    MyClass a, b;
    MyClass *p = new MyClass; 
     
    cout << p­->getInstanceCount() << endl;

    // Zugriff über Klassenmethode (ohne Instanzvariable)   
    cout << MyClass::getInstanceCount() << endl;
}
```
