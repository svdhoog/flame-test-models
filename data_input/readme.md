This folder contains test models for testing the reading in of data from files.

It build up in complexity, starting from agents initialiying a memory variable from data contained in another agent's memory as an array.

Then we read-in daat from file, first reading only a single variable from one external data file.

Finally, we read in multiple variables from multiple files, and allocate the items one by one with agents having a determinstic index (this uses the 'determinstic()' function provided in poplib.py and the lambda function "lambda x:x")