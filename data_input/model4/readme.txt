Model 4: Long data input from file, index is based on agent's ID-1

 Households:
 10 agents initialize their memvar var based on the same long input data file (10 items)
 
 This uses the 'determinstic' function from poplib.py.
 Set the index of the list determistically such that agents get allocated the items of the list one by one:
 
 index = deterministic(0,getAgentCount("Household")-1,lambda x:x)
 
 agent[1]=item[0]
 agent[2]=item[1]
  ...
 agent[10]=item[9]
 
 Eurostat:
 1 agent with the data input array as a dynamic array of doubles, stored as memory variable
 
FULL INITIALIZATION EXPRESSIONS

Household:

var = list(map(lambda x: float(x), open("/path/model4/data.csv").read().split(",")))[deterministic(0,getAgentCount("Household")-1,lambda x:x)]


Eurostat:

data_readin = list(map(lambda x: float(x), open("/path/model4/data.csv").read().split(",")))