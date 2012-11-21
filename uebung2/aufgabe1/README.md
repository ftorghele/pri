Aufgabe 1
=========

Lesen Sie (die angegebenen Teile von) What Every Programmer Should Know About Memory (URL: <http://www.akkadia.org/drepper/cpumemory.pdf>) und beantworten Sie die Fragen.

__(a) Lesen Sie Kapitel 2, 2.1, 2.2.4 und 2.2.5. Erklären sie die Abkürzungen SMP und NUMA.__

__SMP:__

Ein symmetrisches Multiprozessorsystem (SMP) ist eine Architektur, bei der mehrere Prozessoren auf denselben Adressraum zugreifen. Jeder Prozessor besitzt einen integrierten Memory-Controller und verwaltet damit einen Teil des Speichers. Prozessor A kann aber auch mittels SMP auf den Speicher von Prozessor B zugreifen. Um Konflikte zu vermeiden können Prozessoren den Speicherinhalt eines anderen Prozessors invlidieren.

Eine SMP-Architektur erlaubt es, die laufenden Prozesse dynamisch auf alle verfügbaren Prozessoren zu verteilen.

* integrierter Memory Controller
* so viele Memory-Banks wie Prozessoren
* Memory-Bandwidth steigt mit der Anzahl von Prozessoren


__NUMA:__
Non-Uniform Memory Access (NUMA) ist eine Computer-Speicher-Architektur für Multiprozessorsysteme, bei denen jeder Prozessor einen eigenen, lokalen Speicher hat, aber anderen Prozessoren über einen gemeinsamen Adressraum direkten Zugriff darauf gewährt (Distributed Shared Memory). Die Speicherzugriffszeiten in einem solchen Verbund hängen daher davon ab, ob sich eine Speicheradresse im lokalen oder im fremden Speicher befindet.

Bei SMP läuft der Speicherzugriff über einen einzelnen Shared Memory Bus. NUMA reduziert diesen Engpass indem wenige CPUs ihren eigenen Shared-Memory-Bus und Arbeitsspeicher erhalten. Diese "nodes" können bei Bedarf aber auch auf den Arbeitsspeicher anderer Nodes zugreifen, was allerdings aufwendiger ist als auf den eigenen Arbeitsspeicher zuzugreifen.

__(b) Lesen Sie Kapitel 3, 3.1, 3.2. Was ist die von Neumann Architektur? Was kostet ein Zugriff auf ein Register bzw. auf den Hauptspeicher? Was versteht man unter eviction?__

__von Neumann Architektur:__
Die Von-Neumann-Architektur (VNA) ist ein Referenzmodell für Computer, wonach ein gemeinsamer Speicher sowohl Computerprogrammbefehle als auch Daten hält. Die Von-Neumann-Architektur ist ein Schaltungskonzept zur Realisierung universeller Rechner (Von-Neumann-Rechner, VNR). Sie realisiert alle Komponenten einer Turingmaschine. Dabei ermöglicht ihre systematische Aufteilung in die entsprechenden Funktionsgruppen jedoch die Nutzung spezialisierter binärer Schaltwerke und damit eine effizientere Strukturierung der Operationen.

Im Prinzip bleibt es aber dabei, dass alles, was mit einer Turingmaschine berechenbar ist, auch auf einer Maschine mit Von-Neumann-Architektur berechenbar ist und umgekehrt. Gleiches gilt für alle höheren Programmiersprachen, die durch einen Compiler oder Interpreter auf die binäre Repräsentation abgebildet werden. Sie vereinfachen zwar das Handling der Operationen, bieten jedoch keine Erweiterung der von der Turingmaschine vorgegebenen Semantik.

__Zugriff auf Register:__
~1 CPU-Cycles (Intel Pentium M)

__Zugriff auf L1:__
~3 CPU-Cycles (Intel Pentium M)

__Zugriff auf L2:__
~14 CPU-Cycles (Intel Pentium M)

__Zugriff auf Hauptspeicher:__
~240 CPU-Cycles (Intel Pentium M)

__Eviction:__
Um neue Daten in den L1 Cache zu laden ist es fast immer zuerst notwendig, Platz im L1 frei zu machen. Eine nicht mehr benötigte Cache-Line wird in den L2 Cache verschoben. Auch dort muss Platz gemacht werden.. -> L3 Cache -> Hauptspeicher. 

__(c) Lesen Sie Kapitel 4, 4.1, 4.2. Wofür braucht man virtuellen Speicher? Warum wird mehrstufige address translation verwendet?__

__wofür braucht man virtuellen Speicher?__
Damit sich verschiedene Prozesse, die gleichzeitig ausgeführt werden, nicht behindern. Jeder Prozess denkt er würde alleine auf dem System laufen. Der virtuelle Speicher bezeichnet den vom tatsächlich vorhandenen Arbeitsspeicher unabhängigen Adressraum, der einem Prozess vom Betriebssystem zur Verfügung gestellt wird.

__address translation:__

Wenn jeder Prozess seine eigene 1-Stufige Page-Tabelle hätte, würde ein großer Teil des physischen Speichers bereits für diese verbraucht werden.
Um dieses Problem zu umgehen werden mehrstufige Page-Tabellen verwendet. Adressbereiche, die nicht tatsächlich verwendet werden benötigen dadurch keinen allozierten Speicher. Dadurch sind viel kompaktere Page-Tabellen für jeden Prozess möglich. 


__(d) Lesen Sie Kapitel 6.2, 6.2.1 (bis Seite 51) und probieren Sie den angegeben Code zur Matrix-Multiplikation aus. Messen Sie mit gettimeofday() und vergleichen Sie das Ergebnis mit dem Artikel. Was versteht man unter locality. Was versteht man unter alignment?__

__Code/Time Vergleich:__
* time used (original):	 	12183 ms
* time used (transposed):	 3367 ms
* time used (sub-matrix):	 1051 ms

__Locality:__
Unter Locality versteht man, ob alle Daten, die für die Berechnung benötigt werden zum Beispiel in den L1-Cache des Prozessors passen oder nicht. Umso besser die Locality ist, umso schneller wird das Programm.

* Spatial Locality: weitere Zugriffe in der Nähe wahrscheinlich
* Temporal Locality: weitere Zugriffe in naher Zukunft wahrscheinlich

__Alignment:__
Unter Alignment versteht man, ob zum Beispiel eine Variable in eine einzige Cache-Line passt oder über mehrere verteilt ist.