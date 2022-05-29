
#ifndef CODING_INTERVIEWS_LANGCHEADER_H
#define CODING_INTERVIEWS_LANGCHEADER_H

#include <stdio.h>
#include <string.h>
#include <stddef.h> // NULL
#include <stdlib.h> // malloc

#include "util/set/utarray.h"
#include "util/set/uthash.h"
#include "util/set/utlist.h"
#include "util/set/utringbuffer.h"
#include "util/set/utstack.h"
#include "util/set/utstring.h"

struct unordered_set {
    int key;
    UT_hash_handle hh;
};

struct unordered_set* find(struct unordered_set** hashtable, int ikey);
void insert(struct unordered_set** hashtable, int ikey);
int* getIntersection(struct unordered_set** set1, struct unordered_set** set2, int* returnSize);
int* intersection(int* nuns1, int nums1Size, int* nums2, int* returnSize);

#endif //CODING_INTERVIEWS_LANGCHEADER_H
