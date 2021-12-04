/**
 * decoy.h - Decoy
 * 
 * Naive Version linked list
 * 
 * (c) Copyright 2021 Ryan Martin
 */

#ifndef _DECOY_H
#define _DECOY_H

#include <stdio.h>

/**
 * +------+-----------+------+
 * |      | +-------+ |      |
 * | prev | | value | | next |
 * |      | +-------+ |      |
 * +------+-----------+------+
 * 
 * [p|k|v|n] -> [p|k|v|n]
 * 
 * The key value is only index
 */

#define HEAD 0
#define NEXT 1
#define SUB -1

enum DECOY_OPT {
    add,    /**
             * add a new to endline of list
             */

    delete, /* delete and resort key */
    move,   /* move and resort key */
    insert, /* same like move */
    patch, /**
            * insert to PATH where
            */
};

/* Don't used it to function return_type */
typedef void (*ANY);

struct __decoy {
    int key;
    ANY data; /* data just a pointer to void */
    struct __decoy *prev;
    struct __decoy *next;
};

typedef struct __decoy (decoy);

typedef enum __hook_mode {
    H_NEXT,
    H_PREV,
} HOOK_MODE;

/* HOOK for pointer of decoier */
typedef void (*HOOK);
typedef void (**HOOK_HEAD);
struct __decoier_hook {
    HOOK prev;
    HOOK_HEAD next;
};

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

static inline void __setup_next_decoier(struct __decoier_hook *h, int k)
{
    decoy *temp;

    temp = (decoy *) malloc(sizeof(decoy));
    temp->key = k;
    temp->prev = (decoy *) h->prev;
    temp->next = NULL;
    *((decoy **) h->next) = temp;
}

// __d's key must be HEAD
static inline void __add_decoy(decoy *__d)
{
    /**
     * template hook for get pointer of
     * __d's next (the __d's next is a pointer)
     */

    // temp for next decoier
    // checked in __foreach_null
    decoy *temp;
    struct __decoier_hook hook;

    // for next decoier
    int key;

    // found the pointer of endline for next
    temp = (decoy *) malloc(sizeof(decoy));

    __foreach_null(__d, &hook, &key);
    __setup_next_decoier(&hook, key);
}

static inline void __delete_decoy()
{
    // printf("DONE\n");
}

enum __DECOY_SORT {
    FALSE,
    TRUE,
};

struct __DECOY_ARG {
    int key;
    enum __DECOY_SORT sort;
};

/**
 * DECOY
 * 
 * add, delete, move, insert, patch
 */
#define DECOY(opt, d, ...) do { \
    struct __DECOY_ARG __new = {__VA_ARGS__}; \
    switch (opt) { \
    case add: \
        __add_decoy(&d); \
        break; \
    case delete: \
        if (__new.key ^ 0) __delete_decoy(); \
        break; \
    case move: \
        break; \
    case insert: \
        break; \
    case patch: \
        break; \
    } \
} while(0);

#define DECOY_HEAD {.key = 0, .next = NULL, .prev = NULL}

#endif /* _DECOY_H */
