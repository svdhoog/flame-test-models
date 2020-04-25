Model 2: Input strings of fixed length from data files

HFCS data file: ID.csv
ID variables of length 12

char mystring[12]: does not work, results in a list of 12 strings
char_array id_hfcs: works, results in a single string of length 12 for each agent (but this cannot be loaded by FLAME)

Init form: 
char_array id_hfcs
array_length: 1
list(map(lambda x: str(x), open("/populations/1600/ID.csv").read().split(",")))[deterministic(0,getAgentCountGlobal("Household")-1,lambda x:x)]

