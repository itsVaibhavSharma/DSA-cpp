# DATA STRUCTURE
A data structure is a data organization, management and storage format that enables efficient access and modification.
(Data Structure is a way in which data is stored on a computer.)

## Why do we need Data Structures?
Data structure is a particular way of storing and organizing information in a computer so that it can be retrieved and used most productively.

- Each Data Structure allows data to be stored in specific manner.
- Data Structure allows efficient data search and retrieval.
- Specific Data structures are decided to work for specific problems.
- It allows to manage large amount of data such as large databases and indexing services such as hash table.
## ABSTRACT DATA TYPE
Abstract data type are **like user defined data type** on which we can perform functions without knowing what is there inside the datatype and how the operations are performed on them.

2 Ways of looking at Data Structures –

- Mathematical/Logical/Abstract Models/Views (algo/pseudocode or what it does)
- Implementation (code)

ADT: These are entities that are definitions of data and operations but do not have implementation details.

- An abstract data type (**ADT**) is basically a logical description or a specification of components of the data and the operations that are allowed, that is independent of the implementation.
- ADTs are a **theoretical** concept in computer science, used in the **design** and **analysis** of algorithms, data structures, and software systems, and do not correspond to specific features of computer languages.
- There may be thousands of ways in which a given ADT can be implemented, even when the coding language remains constant. Any such implementation must comply with the content-wise and behavioral description of the ADT.

# ALGORITHM
###### **Dictionary Definition –**
A **process** or **set of rules** to be followed in **calculations** or other **problem-solving operations**, especially by a computer.

###### **Formal Definition –**
An **algorithm** is a **finite set of instructions** that are carried in a **specific order** to perform **specific task**.

###### **Algorithms typically have the following characteristics –**
- **Inputs** : 0 or more input values.
- **Outputs** : 1 or more than 1 output.
- **Unambiguity** : clear and simple instructions.
- **Finiteness** : Limited number of instructions.
- **Effectiveness** : Each instruction has an impact on the overall process.

###### **Real world example of an Algorithm –** 
Algorithm(aka process) to make a lemonade –
1. Cut your lemon in half.
2. Squeeze all the juice out of it that you can.
3. Pour your juice into a container with 1/4 cup sugar.
4. Add a very small amount of water to your container.
5. Stir your solution until sugar dissolves.
6. Fill up container with water and add ice.
7. Put your lemonade in the fridge for five minutes.
8. Serve and enjoy!
###### **Example of an Algorithm in Programming –**
Write an algorithm to add two numbers entered by user. –
- Step 1: Start
- Step 2: Declare variables num1, num2 and sum.
- Step 3: Read values num1 and num2.
- Step 4: Add num1 and num2 and assign the result to sum.(sum←num1+num2 )
- Step 5: Display sum
- Step 6: Stop
## SORTING ALGORITHMS IN DATA STRUCTURES
**What is a Sorting Algorithm?***
A Sorting Algorithm is used to rearrange a given array or list DS elements according to a particular pattern(For e.g. Ascending or Descending order). The comparison operator is used to decide the new order of element in the respective data structure.

***Why do we need sorting algorithms ?***
- Efficient sorting is important for optimizing the efficiency of other algorithms (such as search and merge algorithms) which require input data to be in sorted lists. 
- Producing more human readable output. 
- It is easier and faster to locate items in a sorted list than unsorted. 

***Types of Sorting Algorithms ?***
Selection Sort 
Bubble Sort 
Insertion Sort 
Merge Sort 
Quick Sort 
Heap Sort 
Radix Sort etc etc...

## Algorithm Analysis
Algorithm analysis is a study to provide theoretical estimation for the required resources of an algorithm to solve a specific computational problem i.e. calculating efficiency.
Generally, the efficiency of an algorithm is related to the input length (no. of steps), known as **time complexity**, or volume of memory, known as **space complexity**.

### Why do we need Algorithm Analysis?
- Knowing efficiency of an algorithm is very vital on mission critical tasks.
- Generally there are multiple approaches/method/algorithms to solve one problem statement. Algorithm analysis is performed to figure out which is the better/optimum approaches/method/algorithms out of the options.
### What does a BETTER Algorithm mean?
- Faster (Less execution time) - **Time Complexity**
- Less Memory - **Space Complexity**
- Easy to read
- Less line of code
- Less hardware/software requirements
Note: Algorithm analysis does not give you accurate/exact values (time/space, etc), however it gives **estimates** which can be used to study the behavior of the algorithm.

## ASYMPTOTIC ALGORITHM ANALYSIS
In mathematical analysis, asymptotic analysis of algorithm is a method of defining the mathematical boundaries (upper limit and lower limit) of its runtime performance.
- Using the Asymptotic analysis, we can easily estimate about the average case, best case and worst case scenario of an algorithm.
In easy words, It is used to mathematically calculate the running time of any operation inside an algorithm.
- Asymptotic algorithm analysis is to estimate the time complexity function for arbitrarily large number.
**TIME COMPLEXITY: It is a computational way to show how (behavior) runtime of a program increases as the size of its input increases.**

# Big O Notation
The notation O(n) is the formal/mathematical way to express the upper bound (worst case) of an algorithm's running time.
- It measures the worst case time complexity or the longest amount of time an algorithm can possibly take to complete.
Following is a list of some common asymptotic notations:
1. Constant time - O(1)
2. Linear - O(n)
3. Logarithmic - O(log n)
4. Quadratic - O (n^2)
5. Cubic - O(n^3)
How to find out the Big O Notation?
1. Find the fastest growing variable term.
2. Eliminate the coefficients/constant terms.
e.g. T = n^2 + 2n
Time complexity : O(n^2)

- Big O Notation specifically describes worst case scenario.
- It represents the upper bound running time complexity of an algorithm.
Mathematically,
Let `f` and `g` be functions of `n`, where n is natural no denoting size or steps of the algorithm then:
	f(n) = O(g(n))
		iff  f(n) <= c.g(n)  , where `n >= n_0`, `c > 0`, n`_0 >= 1`