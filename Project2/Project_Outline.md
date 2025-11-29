# Project Outline
Luke Aubrey, William Gallagher

## Dataset
https://baseballsavant.mlb.com/leaderboard/statcast

## Motivation
An interest in sport statistic specifically baseball. Decided to use batting statistics specifically the EV50 from the top 250 hitters in the 2025 season. The players are ranked by their Batted Ball Contact % divided by Plate Appearance % (Bris/PA %). I was curious how these players did with their EV50 which is the average of the hardest 50% of his batted balls per batter.

## Problem 1
### Application 1:
Hash table for fast lookup of player metrics.  A hash table would be highly effective for storing statistical player data by a unique identifier, such as player ID or name.  Statcast datasets often have thousands of entries; the constant-time lookup given by a hash table would be handy in quickly finding any player’s data.  This would enable quick comparisons between players or integration into dashboards and scouting tools.  An example use would be for analysts evaluating trade targets; they could quickly retrieve any player’s metrics without having to scan the entire dataset.  Collisions could be handled with chaining, but overall, most operations would still have O(1) time complexity, while remaining scalable as the data grows throughout the season.

### Application 2:
A stack could model a player's recent decisions/performance. The last several pitches he faced could be stored, with data like location, speed, and outcome, at the top of the stack, and then popped by coaches who want to quickly review swings by how recent they are. This would help them evaluate if a player is adjusting correctly between pitches. Because a stack is last-in, first-out, it is useful when the most recent swings are most important for the coach's decision-making. The approach parallels video review workflows where analysts examine the last few pitches first, making the stack a natural fit for the short-term memory of swing decision patterns.

## Problem 2
### Priority Queue - Max Heap

### Modifications Made:
* Implemented a comparison operator (operator>) in the Player struct to compare based on EV50. Used in both Reheaps.
* Added a print() function tailored for formatted display of player data (rank, name, team, EV50).
* Removed many generic functions, Peek(), IsFull(), IsEmpty(), & MakeEmpty()
* Implemented PutItem() and GetItem() to insert players into the heap and extract the top EV50 players, respectively.

### Implementation & I/O
**Input:**

* Before running program user needs to put their EV50.csv file in same folder as main.cpp.

* A value k for the number of top players to display.

**Output:**

* Prints all players currently in the heap using a formatted print() function.

* Checks the heap property with checkMaxHeap() to ensure the structure remains a valid Max Heap.

* Prints the top k players by EV50 by repeatedly calling GetItem() to remove the max element, displaying rank, name, team, and EV50.