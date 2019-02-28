# arrays_mutations
Given:
 - integer array A is long size (arbitrary size, memory overflow is not considered),
 - the element size is 1 byte,
 - random filling,
 - the range of values ​​is 0-255;
 
 - the integer array F is long 256,
 - the element size is 1 byte,
 - the values ​​of the elements are unique (no repetition of elements), the range of values ​​is 0-255.
 
 Note: array F defines a permutation of the elements of any array M long 256,
 by which the element of the original array M standing on position i moves to position
 determined by the value of the element of the array F located on the i position. (M [i] => N [j], where j = F [i])
 
 Task:
 Make an array B of mixed (according to the array of permutations F) blocks of array A with a length of 256 bytes.
 If the length of array A is not a multiple of 256, then the last block of array A (incomplete) is considered to be padded to the size of 256 bytes with zero values.
 At the beginning of array B, you must place its length (field size 4 bytes).
 
 Conditions:
  - do not use library containers for data storage, place the final array on the heap;
  - do not use ready-made library algorithms, all standard arithmetic operations are allowed;
  - try to optimize the algorithm (not at the expense of the readability of the code) for the economical use of computational and memory resources.

# not tested
