/**
 *
 * @filename:unoerder_set_realize.c
 * @function:
 * @return:
 * @author:Zhanyou Zhou (gmrakari@outlook.com)
 * @date:2022/5/29 03:12
 *
 */

#include "langCHeader.h"

struct unordered_set* find(struct unordered_set** hashtable, int ikey) {
    struct unordered_set* tmp;
    HASH_FIND_INT(*hashtable, &ikey, tmp);
    return tmp;
}
void insert(struct unordered_set** hashtable, int ikey) {
    struct unordered_set* tmp = find(hashtable, ikey);
    if (tmp != NULL) return;
    tmp = malloc(sizeof(struct unordered_set));
    tmp->key = ikey;
    HASH_ADD_INT(*hashtable, key, tmp);
}

int* getIntersection(struct unordered_set** set1, struct unordered_set** set2, int* returnSize) {
    if (HASH_COUNT(*set1) > HASH_COUNT(*set2)) {
        return getIntersection(set2, set1, returnSize);
    }
    int* intersection = malloc(sizeof(int) * (HASH_COUNT(*set1) + HASH_COUNT(*set2)));
    struct unordered_set *s, *tmp;
    HASH_ITER(hh, *set1, s, tmp) {
        if (find(set2, s->key)) {
            intersection[(*returnSize)++] = s->key;
        }
    }
    return intersection;
}

int* intersection(int* nuns1, int nums1Size, int* nums2, int* returnSize) {

}
