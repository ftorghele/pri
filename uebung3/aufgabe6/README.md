Aufgabe 6
=========

__Berechnen Sie unter Annahme von 64-bit Adressen die folgenden Werte fur einen 8-fach assoziativen 256 KB grossen Cache mit 64 Bytes cache lines:__

- Anzahl der Bits für offset, index und tag bits
> - __cache lines__ = (256 * 1024) / 64 Byte große cache lines = 4096
> - __offset =__ ld(64) = __6bit__
> - __index =__ 4096 (cache lines) / 8 (8-fach assoziativ) = ld(512) = __9bit__
> - __tag =__ 64bit - 6bit (offset) - 9bit (index) = __49bit__

- Anzahl der sets im Cache
> - __sets =__ 4096 (cache lines) / 8 (8-fach assoziativ) = __512__

- Anzahl der cache lines im Cache
> - siehe oben
