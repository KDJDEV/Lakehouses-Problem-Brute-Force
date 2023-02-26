# Lakehouses Problem Brute Force
My Brute Force solution to the Lakehouses Problem

Solution data represented as the relative distances between the lakehouses can be found in solutions.json.
A visualization of all 324 solutions can be found here:
https://kdjdev.github.io/Lakehouses-Problem-Brute-Force/

The soure code for my brute force is in the /src directory.

The code will default to generating the list of possible solutions to check using a recursive combinations algorithm. If you are not convinced that the recursive algorithm will check all possibilities, you can also check all permutations by instantiating a PermutationBruteForcer instead of a CombinationBruteForcer on [line 9 of main.cpp](https://github.com/KDJDEV/Lakehouses-Problem-Brute-Force/blob/f2f7e8b5b5b6f0266263a1a18402c3887ec94463/src/main.cpp#L9). Both algorithms should complete very quickly.
