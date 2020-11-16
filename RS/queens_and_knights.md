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