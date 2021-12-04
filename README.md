# decoy
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

# __foreach_null
```c
/* HOOK for pointer of decoier */
typedef void (*HOOK);
typedef void (**HOOK_HEAD);
struct __decoier_hook {
    HOOK prev;
    HOOK_HEAD next;
};

...

static inline void __foreach_null(decoy *__d, struct __decoier_hook *h, int *k)
{
    decoy *temp;
    decoy *prev;

    if (__d->next != NULL) {
        temp = __d;

        // [0]->[1]->[2]
        // temp must pointer to [2]'s next
        while (temp->next != NULL) {

            // prev to last second
            prev = temp;

            // temp to last one
            temp = temp->next;
        }

        h->prev = (HOOK) prev->next;
        h->next = (HOOK_HEAD) &(temp->next);
        *k = prev->next->key + NEXT;
    } else {
        h->prev = (HOOK) __d;
        h->next = (HOOK_HEAD) &(__d->next);
        *k =__d->key + NEXT;
    }
}

...
```
