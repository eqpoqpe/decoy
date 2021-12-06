/**
 * decoy
 *
 * (c) Copyright 2021 Ryan Martin
 */

#include <stdio.h>
#include <stdlib.h>

#include "decoy.h"

int main()
{
    decoy decoier = DECOY_HEAD;
    // decoy user;
    // decoy slave;

    // decoier.next = &user;
    // user.key = 1;
    // user.prev = &decoier;
    // user.next = &slave;;
    // slave.key = 2;
    // slave.prev = &user;
    // slave.next = NULL;

    printf("%p\n", &(decoier));
    printf("%d\n", decoier.key);

    // DECOY(add, decoier);
    // DECOY(add, decoier);
    // DECOY(delete, decoier, 10, FALSE);
    // DECOY(delete, decoier, 21, .sort=TRUE);

    // printf("%d\n", decoier.next->key);
    // DECOY(add, decoier);
    // DECOY(add, decoier);
    // DECOY(add, decoier);
    // DECOY(add, decoier);
    // DECOY(add, decoier);
    // DECOY(add, decoier);
    // DECOY(add, decoier);
    // DECOY(add, decoier);
    // DECOY(add, decoier);
    // DECOY(add, decoier);

    // printf("%d\n", decoier.next->prev->next->prev->next->next->prev->key);

    // printf("%d\n", slave.next->prev->key);

    return 0;
}
