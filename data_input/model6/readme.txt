Model 6: Reading in a single survey variable from HFCS data from a single file
 
- index is in sequence (0,...,Nr agents -1)
- 2 agents initialize their memvar 
 
 var= HB1601
 
INITIALIZATION

Household:

var = list(map(lambda x: float(x), open("/populations/1600/HB1601.csv").read().split(",")))[deterministic(0,getAgentCountGlobal("Household")-1,lambda x:x)]

index = deterministic(0,getAgentCountGlobal("Household")-1,lambda x:x)