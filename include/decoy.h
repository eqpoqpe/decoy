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
#include <stdlib.h>

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

enum __DECOY_SORT {
    FALSE,
    TRUE,
};

struct __DECOY_ARG {
    int key;
    enum __DECOY_SORT sort;
};

/* Don't used it to function return_type */
typedef void (*ANY);

struct __decoy {
    int key;
    ANY data; /* data just a pointer to void */
    struct __decoy *prev;
    struct __decoy *next;
};

struct __head_prototype {
    int length;
    int key;
    ANY data;
    struct __decoy *prev;
    struct __decoy *next;
};

typedef struct __head_prototype (decoy);

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

extern void __foreach_null(decoy *, struct __decoier_hook *, int *);
extern void __setup_next_decoier(struct __decoier_hook *, int);
extern void __add_decoy(decoy *);

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
        break; \
    case move: \
        break; \
    case insert: \
        break; \
    case patch: \
        break; \
    } \
} while(0);

#define DECOY_HEAD  { \
    .length = 0, \
    .key = HEAD, \
    .prev = NULL, \
    .next = NULL, \
}

#endif /* _DECOY_H */
