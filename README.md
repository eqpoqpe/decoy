# DECOY
 - <s>add</s>
 - detele
 - move
 - insert
 - patch

```
+--------------------+
|      +-------+     |
| prev | K | V | next|
|      +-------+     |
+--------------------+
```

Alls, it's a macro define

```c
#define DECOY(opt, d, ...)
```
```c
DECOY(add, decoier);
DECOY(add, decoier);
DECOY(delete, decoier, 10, FALSE);
DECOY(delete, decoier, .key=21, .sort=TRUE);
```

# Example
```
~$ git clone https://github.com/eqpoqpe/decoy.git
~$ cd decoy
~$ make
~$ # You can modify example/demo.c
```
