# Queens & Knights

## N Queens

Place N queens on an N x N board such that they don't attack each other.

### Model

N rows, each with a single queen => N variables, N labels. Variable i assigned label Q[i].

### Constraints

- diff column: `i != j => Q[i] != Q[j]`
- no diagonal: `abs(i-j) != abs(Q[i] - Q[j])`

### Problem analysis

|Solver    |N  |First Solution| 5 solutions|
|:--------:|:-:|:------------:|:----------:|
|Q (simple)|8  |0.1 sec||
|Q (simple)|10 |15 sec||
|Q (path consistency)|10 | 0 sec|0.002 sec|
|Q (look ahead)|10 | 0 sec|0.0025 sec|
|Q (path consistency)|27 | 15 sec|18.2 sec|
|Q (look ahead)|27 | 15 sec|19.4 sec|

## Knights Problem

Generate tours for a knight starting at a given position on an N x N board. Each cell should be visited only once.

### Model

N rows, N columns => N * N variables, each label is the step at which the cell represented by the variable was reached. Alternatively, the labels could point to the variable representing the cell for the next move.

Generating labels for each variable in the compound would be too inefficient, so instead we simulate the knight's tour in a constraint graph.

### Constraints

- L-move: `T[i,j] = T[k,l] + 1 => (abs(i-j) == 1 && abs(k-l) == 2) || (abs(i-j) == 2 && abs(k-l) == 1)`
- Generate move (stay on board): `0 <= l + pl[move] < N && 0 <= c + pc[move] < N`
- Generate move (do not revisit): `!mark[l+pl[move]][c+pc[move]]`
- Create constraint graph using the mapping: `i = l * N + c`

*Note*: 0-indexed

### Problem analysis

|Solver    |N  |First Solution|
|:--------:|:-:|:-------------------------|
|K (simple)|8  |23 sec|
|K (arc consistency)|8 | 20 sec|
|K (look ahead)|100| 0.03 sec|

## Code Documentation

### Queens Problem

**Input**: `q.in`

`<N> <num_sol>`

**Output**: console (standard output)

`<sol_1 sol_2 ... sol_num_sol> <time> <total_found>`

**Compile & run**: 

Simple backtracking:
`g++ -o q q.cpp`
`./q`

Path consistency:
`g++ -o qv qv.cpp`
`./qv`

Look ahead search:
`g++ -o qla qla.cpp`
`./qla`

### Knights Problem

**Input**: `k.in`

`<N> <row> <col> <num_sol>`

*Note*: `row`, `col` are 0-indexed

**Output**: console (standard output)

`<sol_1 sol_2 ... sol_num_sol> <time> <total_found>`

**Compile & run**: 

Simple backtracking:
`g++ -o k k.cpp`
`./k`

Arc consistency:
`g++ -o kc kc.cpp`
`./kc`

Look ahead search:
`g++ -o kla kla.cpp`
`./kla`

### Simple Backtracking

Queens Problem: `q.cpp`

Knights Problem: `k.cpp`

### Problem Reduction

Queens Problem: `qv.cpp`

**Path Consistency**: When searching for a solution always validate that the labels generated so far are consistent with one another (check that queens do not attack each other).

Knights Problem: `kc.cpp`

**Arc Consistency**: When generating a new label (a knight move), use the constraint graph edges from the current node in order to avoid generating non-consistent arcs (such as moves outside of the board). Validate next variable can be assigned label.

### Basic Search Strategies

Queens Problem: `qla.cpp`

**Lookahead**: Prevent exploring current subtree if not enough available/free labels for the remaining queens.

Knights Problem: `kla.cpp`

**Lookahead**: Prioritize exploring moves landing in a position where the number of possible moves is the lowest.