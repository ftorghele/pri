Aufgabe 1
=========

__Lesen Sie unmaintainable code (URL: <http://mindprod.com/jgloss/unmain.html>). Was halten Sie davon? Präsentieren Sie 5 wichtige, lehrreiche Hinweise/Fehler/Fallstricke: entweder aus dem Artikel (die Ihnen besonders wichtig erscheinen) oder Beispiele aus eigener Erfahrung.__

Der Autor schreibt in einem kurzen Einleitungs-Satz, das es erstaunlich ist, wie viele Leute nicht kapieren, dass diese Auflistung irronisch gemeint ist. Nachfolgend führe ich Hinweise auf, wie man Code unwartbar gestalten kann:

- __Lie in the comments:__ You don’t have to actively lie, just fail to keep comments as up to date with the code.

- __Never Test:__ Never test any code that handles the error cases, machine crashes, or OS glitches. Never check return codes from the OS. That code never gets executed anyway and slows down your test times. Modern hardware never fails, and who wants to write code just for testing purposes? It isn’t any fun. If users complain, just blame the OS or hardware. They’ll never know.

- __Inline Assembler:__ Sprinkle your code with bits of inline assembler just for fun. Almost no one understands assembler anymore. Even a few lines of it can stop a maintenance programmer cold.

- __Never Validate:__ Never check input data for any kind of correctness or discrepancies. It will demonstrate that you absolutely trust the company’s equipment as well as that you are a perfect team player who trusts all project partners and system operators. Always return reasonable values even when data inputs are questionable or erroneous.

- __Clone & Modify:__ In the name of efficiency, use cut/paste/clone/modify. This works much faster than using many small reusable modules. This is especially useful in shops that measure your progress by the number of lines of code you’ve written.

- __Single Letter Variable Names:__ If you call your variables a, b, c, then it will be impossible to search for instances of them using a simple text editor. Further, nobody will be able to guess what they are for. If anyone even hints at breaking the tradition honoured since FØRTRAN of using i, j, and k for indexing variables, namely replacing them with ii, jj and kk, warn them about what the Spanish Inquisition did to heretics.
