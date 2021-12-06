#include <stdio.h>
#include <stdlib.h>

#include "decoy.h"

/**
 * Found the endline of decoier
 * 
 * It's value is NULL
 * 
 * Return a decoy to ponter of next or prev
 * 
 * Pointer to pointer to decoy
 * the parameter h, pointer to pointer to pointer of decoy hook
 */
extern void __foreach_null(decoy *__d, struct __decoier_hook *h, int *k)
{
    struct __decoy *temp;
    struct __decoy *prev;

    if (__d->next != NULL) {
        temp = __d->next;
        prev = (struct __decoy *) __d;

        // started from [1] [2]
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

extern void __setup_next_decoier(struct __decoier_hook *h, int k)
{
    struct __decoy *temp;

    temp = (struct __decoy *) malloc(sizeof(struct __decoy));
    temp->key = k;
    temp->prev = (struct __decoy *) h->prev;
    temp->next = NULL;
    *((struct __decoy **) h->next) = temp;
}

// #pragma GCC diagnostic ignored "-Wunused-but-set-variable"

// __d's key must be HEAD
extern void __add_decoy(decoy *__d)
{
    /**
     * template hook for get pointer of
     * __d's next (the __d's next is a pointer)
     */

    // temp for next decoier
    // checked in __foreach_null
    struct __decoier_hook hook;

    // for next decoier
    int key;

    // found the pointer of endline for next
    // temp = (decoy *) malloc(sizeof(decoy));

    __foreach_null(__d, &hook, &key);
    __setup_next_decoier(&hook, key);
}

extern void __delete_decoy(void *__d)
{
    free(__d);
}