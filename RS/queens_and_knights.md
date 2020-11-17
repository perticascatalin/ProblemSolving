# Queens & Knights

## N Queens

Place N queens on an N x N board such that they don't attack each other.

|Solver    |N  |First Solution|
|:--------:|:-:|:-------------------------|
|Q (simple)|8  |0.1 sec|
|Q (simple)|10 |15 sec|
|Q (path consistency)|10 | 0 sec|
|Q (path consistency)|27 | 15 sec|
|Q (look ahead)|27 | 15 sec|

## Knights Problem

Generate tours for a knight starting at a given position on an N x N board. Each cell should be visited only once.

|Solver    |N  |First Solution|
|:--------:|:-:|:-------------------------|
|K (simple)|8  |23 sec|
|K (arc consistency)|8 | 20 sec|
|K (look ahead)|100| 0.03 sec|

## Code Documentation

### Simple Backtracking

Queens Problem: q.cpp

Knights Problem: k.cpp

### Problem Reduction

Queens Problem: qv.cpp

**Path Consistency**: When searching for a solution always validate that the labels generated so far are consistent with one another (check that queens do not attack each other).

Knights Problem: kc.cpp

**Arc Consistency**: When generating a new label (a knight move), use the constraint graph edges from the current node in order to avoid generating non-consistent arcs (such as moves outside of the board).

### Basic Search Strategies

Queens Problem: qla.cpp

**Lookahead**: Prevent exploring current subtree if not enough available/free labels for the remaining queens.

Knights Problem: kla.cpp

**Lookahead**: Prioritize exploring moves landing in a position where the number of possible moves is the lowest.