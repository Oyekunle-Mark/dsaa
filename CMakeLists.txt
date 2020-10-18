cmake_minimum_required(VERSION 3.17)
project(dsaa)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall")

add_executable(dsaa main.cpp lists/Vector.cpp lists/Vector.h lists/List.cpp lists/List.h leetcode/array/MaxConsecutiveOnes.cpp leetcode/array/NumbersWithEvenDigits.cpp leetcode/array/SquaresOfSortedArray.cpp trees/BinarySearchTree.cpp trees/BinarySearchTree.h leetcode/array/DuplicateZeros.cpp leetcode/array/MergeSorted.cpp leetcode/array/RemoveElement.cpp leetcode/array/RemoveDuplicatesFromSortedArray.cpp leetcode/array/CheckIfNAndItsDoubleExist.cpp leetcode/array/ValidMountainArray.cpp leetcode/array/ReplaceElementsWithGreatestElementOnRightSide.cpp leetcode/array/MoveZeroes.cpp leetcode/array/SortArrayByParity.cpp leetcode/array/HeightChecker.cpp leetcode/array/ThirdMaximumNumber.cpp leetcode/array/FindAllNumbersDisappearedInAnArray.cpp hashTable/HashTable.cpp hashTable/HashTable.h hashTable/hash.h hashTable/Employee.h leetcode/linkedList/designLinkedList.cpp)
