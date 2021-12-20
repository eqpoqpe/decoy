/**
 * decoy.c - Decoy
 * 
 * (c) Copyright 2021 Ryan Martin
 */

#include <stdio.h>
#include <stdlib.h>

#include "decoy.h"

static inline void __inline_sort(struct __decoy *__d)
{
}

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
static void __foreach_null(decoy *__d, struct __decoier_hook *h, int *k)
{
    struct __decoy *temp;
    struct __decoy *prev;

    if (__d->next != NULL) {
        temp = __d->next;
        prev = (struct __decoy *) __d;

        // started from [1] [2]
        while (temp->next != NULL) {
            prev = temp;
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

/**
 * if matched it, return pointer
 * if not return NULL
 */
static struct __decoy * __foreach_key(decoy *__d, int key)
{
    struct __decoy *temp;

    temp = (struct __decoy *) __d;

    for (; temp != NULL; temp = temp->next)
        if (temp->key == key)   return temp;

    return NULL;
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

// __d's key must be HEAD
extern void __add_decoy(decoy *__d, struct __DECOY_ADD_ARG *args)
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

    // printf("%p\n", args->set);
    if (args->set != NULL) {

         ;;;;;;;;
        ;;      ;;
        ;;
        ;;;;;;;;;
        ;;      ;;
        ;;      ;;
         ;;;;;;;;
        (args->set)((ANY) __d, args->data_ptr);
    }
}

/**
 * [ || ] [X] [ || ] [ || ]
 *     ^       ^
 *     |_______|
 */

/**
 * if delete head decoier, only delete data
 * 
 * absolute head deocier, it's only one at alls
 */
extern void __del_decoy(decoy *__d, struct __DECOY_DEL_ARG *args)
{
    struct __decoy *res;

    if (__d->prev == NULL && __d->key == HEAD) {
        if (args->key != HEAD) {
            res = __foreach_key(__d, args->key);

            if (res != NULL) {
                if (res->data != NULL)  free(res->data);
                res->prev->next = res->next;
                res->next->prev = res->prev;
                free(res);
            }
            if (args->sort) __inline_sort(NULL);
        } else {
            if (__d->data != NULL) free(__d->data);
        }
    }
}