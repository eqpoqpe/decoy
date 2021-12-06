/**
 * decmap.c - Decoy
 * 
 * (c) Copyright 2021 Ryan Martin
 */

/**
 * String Key to index key to memory address
 * 
 *         +--------+
 * Joy  -> |        | -> 7 <---> 0xfffffffff
 * Kail -> |        | -> 0 <---> 0xffffffff0
 *         +--------+
 */