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

enum __DECOY_OPT {
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

enum __DEL_SORT {
    FALSE,
    TRUE,
};

/* Don't used it to function return_type */
typedef void (*ANY);

// public decoy arg
struct __PUBLIC_DECOY_ARG {
    int key;
    enum __DEL_SORT sort;

    // set data
    void (*set)(ANY, ANY);
    ANY data_ptr;
};

// private struct type
struct __DECOY_ADD_ARG {
    void (*set)(ANY, ANY);
    ANY data_ptr;
};

// private struct type
struct __DECOY_DEL_ARG {
    int key;
    enum __DEL_SORT sort;
};

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

#pragma GCC diagnostic ignored "-Wunused-function"
static struct __decoy * __foreach_key(decoy *, int);
static void __foreach_null(decoy *, struct __decoier_hook *, int *);
static inline void __inline_sort(struct __decoy *);

extern void __setup_next_decoier(struct __decoier_hook *, int);
extern void __add_decoy(decoy *, struct __DECOY_ADD_ARG *);
extern void __del_decoy(decoy *, struct __DECOY_DEL_ARG *);

/**
 * DECOY
 * 
 * add, delete, move, insert, patch
 * 
 * __VA_ARGS__
 */
#define DECOY(opt, d, ...) do { \
    struct __PUBLIC_DECOY_ARG __add = {__VA_ARGS__}; \
    switch (opt) { \
    case add: \
        __add_decoy(&d, (struct __DECOY_ADD_ARG *) &__add); \
        break; \
    case delete: \
        __del_decoy(&d, (struct __DECOY_DEL_ARG *) &__add); \
        break; \
    case insert: \
        break; \
    } \
} while(0);

#define DECOY_HEAD  { \
    .length = 0, \
    .key = HEAD, \
    .data = NULL, \
    .prev = NULL, \
    .next = NULL, \
}

#endif /* _DECOY_H */
