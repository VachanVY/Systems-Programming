/* linked list element */
typedef struct ELE {
    long val;
    struct ELE *next; // list_ptr next;
} *list_ptr; // list_ptr is a pointer to `struct ELE`

/* sum_list - Sum the elements of a linked list */
long sum_list(list_ptr ls)
{
    long val = 0;
    while (ls) {        // while ls != NULL
        val += ls->val;     // val += (*ls).val
        ls = ls->next;      // ls = (*ls).next
    }
    return val; // return val
}

/* rsum_list - Recursive version of sum_list */
long rsum_list(list_ptr ls)
{
    if (!ls) // if ls == NULL
        return 0;
    else {
        long val = ls->val;
        long rest = rsum_list(ls->next);
        return val + rest;
    }
}

/* copy_block - Copy src to dest and return xor checksum of src */
long copy_block(long *src, long *dest, long len)
{
    long result = 0;
    while (len > 0) {
        long val = *(src++);
        *(dest++) = val;
        result ^= val;
        len--;
    }
    return result;
}

/*
1) Write a Y86-64 program sum.ys that iteratively sums the elements of a linked list. Your program should
consist of some code that sets up the stack structure, invokes a function, and then halts. In this case,
the function should be Y86-64 code for a function (sum list) that is functionally equivalent to the C
sum list function in Figure 1. Test your program using the following three-element list:
# Sample linked list
.align 8
ele1:
.quad 0x00a
.quad ele2
ele2:
.quad 0x0b0
.quad ele3
ele3:
.quad 0xc00
.quad 0

2) rsum.ys: Recursively sum linked list elements
Write a Y86-64 program rsum.ys that recursively sums the elements of a linked list. This code should
be similar to the code in sum.ys, except that it should use a function rsum list that recursively sums a
list of numbers, as shown with the C function rsum list in Figure 1. Test your program using the same
three-element list you used for testing list.ys.

3) copy.ys: Copy a source block to a destination block
Write a program (copy.ys) that copies a block of words from one part of memory to another (non-
overlapping area) area of memory, computing the checksum (Xor) of all the words copied.
Your program should consist of code that sets up a stack frame, invokes a function copy block, and
then halts. The function should be functionally equivalent to the C function copy block shown in Figure
Figure 1. Test your program using the following three-element source and destination blocks:
.align 8
# Source block
src:
.quad 0x00a
.quad 0x0b0
.quad 0xc00
# Destination block
dest:
.quad 0x111
.quad 0x222
.quad 0x333
*/