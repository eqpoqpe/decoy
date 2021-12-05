# ***DECOY***
Alls, it's a macro define

```c
#define DECOY(opt, d, ...)
```
```
+--------------------+
|      +-------+     |
| prev | K | V | next|
|      +-------+     |
+--------------------+
```
```c
decoy decoier = DECOY_HEAD;

DECOY(add, decoier);
DECOY(add, decoier);
DECOY(delete, decoier, 10, FALSE);
DECOY(delete, decoier, .key=21, .sort=TRUE);
```

*`Functions list`*
--------------
 - <s>add</s>
 - detele
 - move
 - insert
 - patch

# *`Example`*
```
~$ git clone https://github.com/eqpoqpe/decoy.git
~$ cd decoy
~$ make
~$ # You can modify example/demo.c
```
