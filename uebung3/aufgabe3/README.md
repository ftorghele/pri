Aufgabe 3
=========

__Lesen Sie das libabc README (URL: <http://0pointer.de/blog/projects/libabc.html>). Was halten Sie davon? Präsentieren Sie 5 wichtige, lehrreiche Hinweise. Ist der Artikel für die eigene Arbeit relevant? Welche Punkte sind ihnen unklar?__

In diesem Blog-Eintrag wird auf eine README verwiesen, die die eigentlichen Hinweise enthällt. Zu finden ist diese unter <https://git.kernel.org/?p=linux/kernel/git/kay/libabc.git;a=blob_plain;f=README>

- __use autotools:__ Every custom config/makefile/build system is worse for everybody than autotools is.

- __Zero global state:__ Always use a library context object. every thread should then operate on its own context. Don't use global variables. Ever.

- __Do not expose any complex structures in your API:__ Use get() and set() instead.

- __Use the de-facto standardized function names:__ It's abc_new(), abc_free(), abc_ref(), abc_unref(). Don't invent your own names.

- __Never call exit(), abort(), be very careful with assert():__ Always return error codes. Functions should return int and negative errors instead of NULL.

- __Make your code safe for unexpected termination and any point:__ Do not leave files dirty or temporary files around.

- __Always guard for multiple inclusions of headers:__ You must place '#ifndef libabc, #define libabc, #endif' in your header files. There is no way around that.

Auch dieser Artikel beinhaltet viele Hinweise, wie man seinen Code besser gestalten kann.
