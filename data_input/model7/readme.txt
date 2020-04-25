Model 7:  Data input from multiple files

- Reading in multiple survey variables from HFCS data from multiple input files
- index is in sequence (0,...,Nr agents -1)
- use static arrays to capture the data in agent memory
- 1600 agents initialize their memvar 
 
INITIALIZATION

Household:

HB160x[3] =

[list(map(lambda x: float(x), open("/populations/1600/HB1601.csv").read().split(",")))[deterministic(0,getAgentCountGlobal("Household")-1,lambda x:x)],list(map(lambda x: float(x), open("/populations/1600/HB1602.csv").read().split(",")))[deterministic(0,getAgentCountGlobal("Household")-1,lambda x:x)],list(map(lambda x: float(x), open("/populations/1600/HB1603.csv").read().split(",")))[deterministic(0,getAgentCountGlobal("Household")-1,lambda x:x)]]

HB170x[3] =
[list(map(lambda x: float(x), open("/populations/1600/HB1701.csv").read().split(",")))[deterministic(0,getAgentCountGlobal("Household")-1,lambda x:x)],list(map(lambda x: float(x), open("/populations/1600/HB1702.csv").read().split(",")))[deterministic(0,getAgentCountGlobal("Household")-1,lambda x:x)],list(map(lambda x: float(x), open("/populations/1600/HB1703.csv").read().split(",")))[deterministic(0,getAgentCountGlobal("Household")-1,lambda x:x)]]

HB360x[3] =
[list(map(lambda x: float(x), open("/populations/1600/HB3601.csv").read().split(",")))[deterministic(0,getAgentCountGlobal("Household")-1,lambda x:x)],list(map(lambda x: float(x), open("/populations/1600/HB3602.csv").read().split(",")))[deterministic(0,getAgentCountGlobal("Household")-1,lambda x:x)],list(map(lambda x: float(x), open("/populations/1600/HB3603.csv").read().split(",")))[deterministic(0,getAgentCountGlobal("Household")-1,lambda x:x)]]

HB370x[3] =
[list(map(lambda x: float(x), open("/populations/1600/HB3701.csv").read().split(",")))[deterministic(0,getAgentCountGlobal("Household")-1,lambda x:x)],list(map(lambda x: float(x), open("/populations/1600/HB3702.csv").read().split(",")))[deterministic(0,getAgentCountGlobal("Household")-1,lambda x:x)],list(map(lambda x: float(x), open("/populations/1600/HB3703.csv").read().split(",")))[deterministic(0,getAgentCountGlobal("Household")-1,lambda x:x)]]

index = deterministic(0,getAgentCountGlobal("Household")-1,lambda x:x)