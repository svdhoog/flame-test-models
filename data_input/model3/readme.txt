Model 3: 
- Short data input, from static or dynamic array
- Index is based on agent's own ID

 2 agents initialize their memvar var=data[getSelfVar("id")-1]
 
 1 agent with the data input array as a double array data[2] stored as memory variable
 
 Household:
var = getAgentGlobal("Eurostat").getAgentVar("data")[0]

or

var = getAgentGlobal("Eurostat").getAgentVar("data_readin")[0]

Eurostat:

data_readin = list(map(lambda x: float(x), open("/path/model3/data.csv").read().split(",")))