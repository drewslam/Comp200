# 8.13 LAB: Library book sorting

Two sorted lists have been created, one implemented using a linked list (LinkedListLibrary class) and the other implemented using the built-in Vector class (VectorLibrary class). Each list contains 100 books (title, ISBN number, author), sorted in ascending order by ISBN number.

Complete main() by inserting a new book into each list using the respective LinkedListLibrary and VectorLibrary InsertSorted() functions and outputting the number of book copy operations the computer must perform to insert the new book. Each InsertSorted() returns the number of book copy operations the computer performs.

Ex: If the input is:

Their Eyes Were Watching God
9780060838676
Zora Neale Hurston

the output is:

Number of linked list book copy operations: 1
Number of vector book copy operations: 95
