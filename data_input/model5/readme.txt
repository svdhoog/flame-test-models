Model 5: 

- Data input from a long file with 1600 items
- Indexing uses the deterministic sequence (0,..., Nr agents -1)
- 1600 agents initialize a memvar from file input
 
 
FULL INITIALIZATION EXPRESSIONS

Household:

var =

list(map(lambda x: float(x), open("path/data_long.csv").read().split(",")))[deterministic(0,getAgentCountGlobal("Household")-1,lambda x:x)]

index = deterministic(0,getAgentCountGlobal("Household")-1,lambda x:x)