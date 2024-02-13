#include <stdio.h>
#include "libs/data_structures/bitset/bitset.h"
#include "libs/data_structures/array_set/unordered_array_set.h"
#include "libs/data_structures/array_set/ordered_array_set.h"

void test_unordered_array_set_create() {
    unordered_array_set set1 =
            unordered_array_set_create(2);

    assert(set1.size == 0);
    assert(set1.capacity == 2);

    unordered_array_set_delete(set1);
}

void test_unordered_array_set_create_from_array() {
    int exp_data[] = {1, 2};
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {1, 2}, 2);

    assert(set1.size == 2);
    assert(set1.capacity == 2);

    for (int i = 0; i < set1.size; i++) {
        assert(set1.data[i] == exp_data[i]);
    }

    unordered_array_set_delete(set1);
}

void test_unordered_array_set_in() {
    int exp_data[] = {1, 2, 5, 7};
    unordered_array_set set1 =
            unordered_array_set_create_from_array(exp_data, 4);

    assert(set1.size == 4);
    assert(set1.capacity == 4);

    assert(unordered_array_set_in(set1, 5));

    unordered_array_set_delete(set1);
}

void test_unordered_array_set_isSubset() {
    unordered_array_set subset =
            unordered_array_set_create_from_array((int[]) {1, 2, 7}, 3);
    unordered_array_set set =
            unordered_array_set_create_from_array((int[]) {3, 1, 2, 7}, 4);

    assert (unordered_array_set_isSubset(subset, set) == 1);

    unordered_array_set_delete(subset);
    unordered_array_set_delete(set);
}

void test_unordered_array_set_insert() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {1, 2}, 2);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);

    unordered_array_set_insert(&set1, 3);
    assert (unordered_array_set_isEqual(set1, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_deleteElement1() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {1, 2}, 2);

    unordered_array_set_deleteElement(&set1, 3);
    assert (unordered_array_set_isEqual(set1, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_deleteElement2() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {2, 3}, 2);

    unordered_array_set_deleteElement(&set1, 1);
    assert (unordered_array_set_isEqual(set1, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_intersection() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {1, 2}, 2);
    unordered_array_set set2 =
            unordered_array_set_create_from_array((int[]) {2, 3}, 2);
    unordered_array_set resSet =
            unordered_array_set_intersection(set1, set2);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {2}, 1);
    assert (unordered_array_set_isEqual(resSet, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_difference() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {1, 2}, 2);
    unordered_array_set set2 =
            unordered_array_set_create_from_array((int[]) {2, 3}, 2);
    unordered_array_set resSet =
            unordered_array_set_difference(set1, set2);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {1}, 1);
    assert (unordered_array_set_isEqual(resSet, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_symmetricDifference() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {1, 2}, 2);
    unordered_array_set set2 =
            unordered_array_set_create_from_array((int[]) {2, 3}, 2);
    unordered_array_set resSet =
            unordered_array_set_symmetricDifference(set1, set2);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {1, 3}, 2);
    assert (unordered_array_set_isEqual(resSet, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_complement() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {2}, 1);
    unordered_array_set set2 =
            unordered_array_set_create_from_array((int[]) {1, 2, 3, 6}, 4);
    unordered_array_set resSet =
            unordered_array_set_complement(set1, set2);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {1, 3, 6}, 3);
    assert (unordered_array_set_isEqual(resSet, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_union1() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {1, 2}, 2);
    unordered_array_set set2 =
            unordered_array_set_create_from_array((int[]) {2, 3}, 2);
    unordered_array_set resSet =
            unordered_array_set_union(set1, set2);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    assert (unordered_array_set_isEqual(resSet, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_union2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    unordered_array_set set2 =
            unordered_array_set_create_from_array((int[]) {}, 0);
    unordered_array_set resSet =
            unordered_array_set_union(set1, set2);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    assert (unordered_array_set_isEqual(resSet, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_union() {
    test_unordered_array_set_union1();
    test_unordered_array_set_union2();
}

void test_unordered_array_set_deleteElement() {
    test_unordered_array_set_deleteElement1();
    test_unordered_array_set_deleteElement2();
}

//---------------------------------------------------------------------------

void test_ordered_array_set_create() {
    ordered_array_set set1 =
            ordered_array_set_create(2);

    assert(set1.size == 0);
    assert(set1.capacity == 2);

    ordered_array_set_delete(set1);
}

void test_ordered_array_set_create_from_array() {
    int exp_data[] = {1, 2};
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {2, 1}, 2);

    assert(set1.size == 2);
    assert(set1.capacity == 2);

    for (int i = 0; i < set1.size; i++) {
        assert(set1.data[i] == exp_data[i]);
    }

    ordered_array_set_delete(set1);
}

void test_ordered_array_set_in() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]){7, 5, 9, 1}, 4);

    assert(set1.size == 4);
    assert(set1.capacity == 4);

    assert(ordered_array_set_in(&set1, 5));

    ordered_array_set_delete(set1);
}

void test_ordered_array_set_isSubset() {
    ordered_array_set subset =
            ordered_array_set_create_from_array((int[]) {7, 1, 2}, 3);
    ordered_array_set set =
            ordered_array_set_create_from_array((int[]) {6, 1, 2, 7}, 4);

    assert (ordered_array_set_isSubset(subset, set) == 0);

    ordered_array_set_delete(subset);
    ordered_array_set_delete(set);
}

void test_ordered_array_set_insert() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {1, 3}, 2);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {1, 3, 3}, 3);

    ordered_array_set_insert(&set1, 3);
    assert (ordered_array_set_isEqual(set1, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_deleteElement1() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {1, 2}, 2);

    ordered_array_set_deleteElement(&set1, 3);
    assert (ordered_array_set_isEqual(set1, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_deleteElement2() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {2, 3}, 2);

    ordered_array_set_deleteElement(&set1, 1);
    assert (ordered_array_set_isEqual(set1, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_intersection() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {1, 2}, 2);
    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {2, 3}, 2);
    ordered_array_set resSet =
            ordered_array_set_intersection(set1, set2);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {2}, 1);
    assert (ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_difference() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {1, 2}, 2);
    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {2, 3}, 2);
    ordered_array_set resSet =
            ordered_array_set_difference(set1, set2);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {1}, 1);
    assert (ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_symmetricDifference() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {1, 2}, 2);
    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {2, 3}, 2);
    ordered_array_set resSet =
            ordered_array_set_symmetricDifference(set1, set2);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {1, 3}, 2);
    assert (ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_complement() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {2}, 1);
    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {1, 2, 3, 6}, 4);
    ordered_array_set resSet =
            ordered_array_set_complement(set1, set2);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {1, 3, 6}, 3);
    assert (ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_union1() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {1, 2}, 2);
    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {2, 3}, 2);
    ordered_array_set resSet =
            ordered_array_set_union(set1, set2);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    assert (ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_union2() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {}, 0);
    ordered_array_set resSet =
            ordered_array_set_union(set1, set2);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    assert (ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_union() {
    test_ordered_array_set_union1();
    test_ordered_array_set_union2();
}

void test_ordered_array_set_deleteElement() {
    test_ordered_array_set_deleteElement1();
    test_ordered_array_set_deleteElement2();
}

void test() {
    test_unordered_array_set_create();
    test_unordered_array_set_create_from_array();
    test_unordered_array_set_in();
    test_unordered_array_set_isSubset();
    test_unordered_array_set_insert();
    test_unordered_array_set_deleteElement();
    test_unordered_array_set_union();
    test_unordered_array_set_intersection();
    test_unordered_array_set_difference();
    test_unordered_array_set_symmetricDifference();
    test_unordered_array_set_complement();

    //--------------------------------------------------------

    test_ordered_array_set_create();
    test_ordered_array_set_create_from_array();
    test_ordered_array_set_in();
    test_ordered_array_set_isSubset();
    test_ordered_array_set_insert();
    test_ordered_array_set_deleteElement();
    test_ordered_array_set_union();
    test_ordered_array_set_intersection();
    test_ordered_array_set_difference();
    test_ordered_array_set_symmetricDifference();
    test_ordered_array_set_complement();
}

int main() {
    test();

    return 0;
}