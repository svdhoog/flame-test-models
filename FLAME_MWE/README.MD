MAIN INSTRUCTIONS TO RUN FLAME TEST MODELS

Author: Sander van der Hoog (svdhoog@gmail.com)
Date: 6 Oct 2017

These general instructions give a short step-by-step list to get things working.

For more information, see these readme files:

libmboard-0.3.1/README

xparser-0.17.1/README.txt


INSTALLATION
=============

1. Libmboard library

a. Configuration step

# cd libmboard-0.3.1

To install in the system (requires root permissions):

# ./configure --disable-parallel --disable-tests

To install in a local folder (user permissions):

# ./configure --prefix=/home/user/build/libmboard --disable-parallel --disable-tests


b. Build step

[root@stfc]# make 
[root@stfc]# make install


2. Xparser (parsing XML, produces C code)

To compile the Xparser C code to build the xparser executable:

# cd xparser-0.17.1

# make

Result:

This should have created the xparser executable called 'xparser' (on POSIX systems, ie Linux or MacOS X) or 'xparser.exe' (on Windows).
It also produces other c code. See the folder called 'output'.

TESTING MODELS
==============
1. Parsing:

Run the xparser on a model using the pre-existing bash script provided inside the model_folder:

# cd model_folder

# bash parse.sh

Or, alternatively, you can execute xparser directly from inside its own folder, calling the model xml file as an argument (change 'model_folder' to the correct model name):

# cd xparser

# xparser ../model_folder/model.xml

2. Compiling the model code:

# cd model_folder

# make

Result:

This should have created the model's main executable in the model folder, called 'main' (on POSIX) or 'main.exe' (on Windows).
It also produces other c code. See the folder called 'output'.


3. Running the model:

[main executable] [no. of iterations] [initial file 0.xml]

# ./main 1 ./inputs/0.xml

Result: see the file output/stdout.txt

Model 1: Hello, World!
======================

Agent types:

Simple: 1 agent, ID=1

Messages: None.

Result: The complete output is in the file stdout.txt

"I am Agent 1: Hello, World!"


Model 2: Hello, Agent!
======================

Agent types:

Sender: 1 agent, ID=1

Receiver: 1 agent, ID=2

Messages:

One message type is defined: hello, which is used by Agent 1 as output and by Agent 2 as output. 

Agent 1 (Sender) has a function function_1 that outputs a message: hello.
Agent 2 (Receiver) has a function function_2 that inputs a message: hello, and prints the ID of the sender agent.

Result: The complete output is in the file stdout.txt

"I am Agent 1: Hello, World!"

"I am Agent 2; I received the message from Agent 1."

