# Insertion Sort

## Straight Insertion Sort

- Description:
    + The list is divided into 2 parts: **sorted** and **unsorted**.
    + In each pass, the fisrt element of the unsorted sublist is **inserted** into the sorted sublist.<br><br>
    <img src="../../img-md/insertion.gif" width="500px">
    <br><br>
- Efficiency: O(n<sup>2</sup>)

## Shell Sort

- Description:
    + Named after its creator Donald L. **Shell** (1959).
    + Given a list of N elements, the list is divided into K **segments** (K is called the **increment**).
    + Each segment contains N/K or more elements.
    + Segments are dispersed throughout the list.
    + Also is called **diminishing-increment sort**.

    *Note*: Choosing incremental values:<br>
        + From more of the comparisons, it is better when we can receive more new information.<br>
        + Incremental values should not be multiples of each other, other wise, the same keys compared on one pass would be compared again at the next.<br>
        + The final incremental value must be 1.
- Efficiency: O(n<sup>1.25</sup>)

# Selection Sort

## Straight Selection Sort

- Description:
    + The list is divided into 2 parts: **sorted** and **unsorted**.
    + In each pass, in the unsorted sublist, the smallest element is **selected** and **exchanged** with the first element.<br><br>
    <img src="../../img-md/selection.gif" width="120px">
    <br><br>
- Efficiency: O(n<sup>2</sup>)

## Heap Sort

- Description:
    + The unsorted sublist is organized into a **heap**.
    + In each pass, in the unsorted sublist, the largest element is **selected** and **exchanged** with the last element.
    + The heap is **reheaped**.
- Efficiency: O(nlog<sub>2</sub>n)

# Exchange Sort

## Bubble Sort

- Description:
    + The list is divided into 2 parts: **sorted** and **unsorted**.
    + In each pass, the smallest element is **bubbled** from the unsorted sublist and moved to the sorted list.<br><br>
    <img src="../../img-md/bubble.gif" width="100px">
    <br><br>
- Efficiency: O(n<sup>2</sup>)

# Divide-and-Conquer

## Quick Sort

## Merge Sort
