/**
 * \file  header.h
 * \brief Header for xmachine data structures and transition functions.
 */
#ifndef _HEADER_H
#define _HEADER_H

#ifdef _DEBUG_MODE
    #define ERRCHECK
#else
    #define NDEBUG
#endif

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include "mboard.h"

#define FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS 0
#define FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS 0
#define FLAME_USE_FILTERS_IN_SYNC 1

/*#define PAUSE printf("PAUSE - type anything to continue");i=getc(stdin);*/
#define PAUSE

#ifdef START_END
int start_simulation(void);
int end_simulation(void);
int start_iteration(void);
int end_iteration(void);
#endif


/* Checking macros */
#ifdef CHECK_MEMORY
#define CHECK_POINTER(PT) if(PT==NULL){printf("**** ERROR in Memory check 1\n");exit(1);}
#else
#define CHECK_POINTER(PT)
#endif






#define START_LOOP_OVER_Sender_AGENTS  \
    current_xmachine_Sender_holder = Sender_start_Sender_state->agents;\
    while (current_xmachine_Sender_holder) {\
	temp_xmachine_Sender_holder = current_xmachine_Sender_holder->next;\
	current_xmachine_Sender = current_xmachine_Sender_holder->agent;\
	current_xmachine->xmachine_Sender = current_xmachine_Sender;
#define END_LOOP_OVER_Sender_AGENTS \
	current_xmachine_Sender = NULL;\
	current_xmachine->xmachine_Sender = NULL;\
	current_xmachine_Sender_holder = temp_xmachine_Sender_holder;\
    }







#define START_LOOP_OVER_Receiver_AGENTS  \
    current_xmachine_Receiver_holder = Receiver_start_Receiver_state->agents;\
    while (current_xmachine_Receiver_holder) {\
	temp_xmachine_Receiver_holder = current_xmachine_Receiver_holder->next;\
	current_xmachine_Receiver = current_xmachine_Receiver_holder->agent;\
	current_xmachine->xmachine_Receiver = current_xmachine_Receiver;
#define END_LOOP_OVER_Receiver_AGENTS \
	current_xmachine_Receiver = NULL;\
	current_xmachine->xmachine_Receiver = NULL;\
	current_xmachine_Receiver_holder = temp_xmachine_Receiver_holder;\
    }





/** \def ARRAY_BLOCK_SIZE
 * \brief The block size to allocate to dynamic arrays. */
#define ARRAY_BLOCK_SIZE 10
/** \def ARRAY_GROWTH_RATE
 * \brief Growth ratio to scale size of dynamic arrays. 
 * Use golden ratio. This makes for a Fibonacci sequence, so the next allocation size 
 * is the sum of the current size and the previous size thus improving the chance of 
 * memory block reuse. It also allows for moderate rate of growth.
 */
#define ARRAY_GROWTH_RATE 1.618034
/** \def START_HELLO_MESSAGE_LOOP
 * \brief Start of loop to process hello messages. */
#define START_HELLO_MESSAGE_LOOP  for(hello_message = get_first_hello_message(); hello_message != NULL; hello_message = get_next_hello_message(hello_message)) {
/** \def FINISH_HELLO_MESSAGE_LOOP
 * \brief Finish of loop to process hello messages. */
#define FINISH_HELLO_MESSAGE_LOOP }


struct FLAME_output
{
	int type; /* 0=snapshot 1=Sender 2=Receiver */
	int format; /* 0=XML */
	char * location;
	int period;
	int phase;
	int flag; /* Used when outputting to show it has been used */

	struct FLAME_output * next;
};
typedef struct FLAME_output FLAME_output;

/** \struct int_array
 * \brief Dynamic array to hold integers.
 *
 * Holds a pointer to an integer array and values for size and memory size.
 */
struct int_array
{
	int size;
	int total_size;

	int * array;
};

/** \struct float_array
 * \brief Dynamic array to hold floats.
 *
 * Holds a pointer to an float array and values for size and memory size.
 */
struct float_array
{
	int size;
	int total_size;

	float * array;
};

/** \struct double_array
 * \brief Dynamic array to hold doubles.
 *
 * Holds a pointer to a double array and values for size and memory size.
 */
struct double_array
{
	int size;
	int total_size;

	double * array;
};

/** \struct char_array
 * \brief Dynamic array to hold chars.
 *
 * Holds a pointer to a char array and values for size and memory size.
 */
struct char_array
{
	int size;
	int total_size;

	char * array;
};

/** \typedef struct int_array int_array
 * \brief Typedef for int_array struct.
 */
typedef struct int_array int_array;
/** \typedef struct float_array float_array
 * \brief Typedef for float_array struct.
 */
typedef struct float_array float_array;
/** \typedef struct double_array double_array
 * \brief Typedef for double_array struct.
 */
typedef struct double_array double_array;
/** \typedef struct char_array char_array
 * \brief Typedef for char_array struct.
 */
typedef struct char_array char_array;


/** \struct xmachine_memory_Sender
 * \brief Holds memory of xmachine Sender.
 */
struct xmachine_memory_Sender
{
	int id;	/**< X-machine memory variable id of type int. */
};

/** \struct xmachine_memory_Sender_holder
 * \brief Holds struct of memory of xmachine Sender.
 */
struct xmachine_memory_Sender_holder
{
	/*@dependent@*/ struct xmachine_memory_Sender * agent;	/**< Pointer to X-machine memory Sender. */

	/*@dependent@*/ struct xmachine_memory_Sender_holder * prev;	/**< Pointer to previous Sender agent in the list.  */
	/*@dependent@*/ struct xmachine_memory_Sender_holder * next;	/**< Pointer to next Sender agent in the list.  */
};

/** \struct xmachine_memory_Sender_holder
 * \brief Holds struct of memory of xmachine Sender.
 */
struct xmachine_memory_Sender_state
{
	/*@dependent@*/ struct xmachine_memory_Sender_holder * agents;	/**< Pointer to X-machine memory Sender. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine_memory_Receiver
 * \brief Holds memory of xmachine Receiver.
 */
struct xmachine_memory_Receiver
{
	int id;	/**< X-machine memory variable id of type int. */
};

/** \struct xmachine_memory_Receiver_holder
 * \brief Holds struct of memory of xmachine Receiver.
 */
struct xmachine_memory_Receiver_holder
{
	/*@dependent@*/ struct xmachine_memory_Receiver * agent;	/**< Pointer to X-machine memory Receiver. */

	/*@dependent@*/ struct xmachine_memory_Receiver_holder * prev;	/**< Pointer to previous Receiver agent in the list.  */
	/*@dependent@*/ struct xmachine_memory_Receiver_holder * next;	/**< Pointer to next Receiver agent in the list.  */
};

/** \struct xmachine_memory_Receiver_holder
 * \brief Holds struct of memory of xmachine Receiver.
 */
struct xmachine_memory_Receiver_state
{
	/*@dependent@*/ struct xmachine_memory_Receiver_holder * agents;	/**< Pointer to X-machine memory Receiver. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine
 * \brief Holds xmachines.
 */
struct xmachine
{
	/*@dependent@*/ /*@null@*/ /*@out@*/ struct xmachine_memory_Sender * xmachine_Sender;	/**< Pointer to X-machine memory of type Sender.  */
	/*@dependent@*/ /*@null@*/ /*@out@*/ struct xmachine_memory_Receiver * xmachine_Receiver;	/**< Pointer to X-machine memory of type Receiver.  */
};

/** \var void* FLAME_m_hello_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_hello_composite_params;

/** \struct m_hello
 * \brief Holds message of type hello_message.
 */
struct m_hello
{
	int id;	/**< Message memory variable id of type int. */
};

/** \typedef struct xmachine xmachine
 * \brief Typedef for xmachine struct.
 */
typedef struct xmachine xmachine;
/** \var typedef xmachine_memory_Sender xmachine_memory_Sender
 * \brief Typedef for xmachine_memory_Sender struct.
 */
typedef struct xmachine_memory_Sender xmachine_memory_Sender;
/** \var typedef xmachine_memory_Sender xmachine_memory_Sender
 * \brief Typedef for xmachine_memory_Sender struct.
 */
typedef struct xmachine_memory_Sender_holder xmachine_memory_Sender_holder;
/** \var typedef xmachine_memory_Sender xmachine_memory_Sender
 * \brief Typedef for xmachine_memory_Sender struct.
 */
typedef struct xmachine_memory_Sender_state xmachine_memory_Sender_state;
/** \var typedef xmachine_memory_Receiver xmachine_memory_Receiver
 * \brief Typedef for xmachine_memory_Receiver struct.
 */
typedef struct xmachine_memory_Receiver xmachine_memory_Receiver;
/** \var typedef xmachine_memory_Receiver xmachine_memory_Receiver
 * \brief Typedef for xmachine_memory_Receiver struct.
 */
typedef struct xmachine_memory_Receiver_holder xmachine_memory_Receiver_holder;
/** \var typedef xmachine_memory_Receiver xmachine_memory_Receiver
 * \brief Typedef for xmachine_memory_Receiver struct.
 */
typedef struct xmachine_memory_Receiver_state xmachine_memory_Receiver_state;
/** \typedef m_hello m_hello
 * \brief Typedef for m_hello struct.
 */
typedef struct m_hello m_hello;


/** \struct location
 * \brief Holds location for calculating space partitioning .
 */
struct location
{
	double point;		/**< Point on an axis. */

	struct location * next;	/**< Pointer to next location on the list. */
};

/** \struct node_information
 * \brief Holds node information .
 */
struct node_information
{
	int node_id;	/**< Node ID. */
	double partition_data[6];	/**< Defines bounding box. */
	int neighbours[10]; /**< Defines the neighbours to this node - -99 if no neighbour */
	int agents_in_halo;	/**< Number of agents in the halo region. */
	int agent_total;	/**< Total number of agents on the node. */
	struct xmachine * agents;	/**< Pointer to list of X-machines. */
	struct m_hello * hello_messages;	/**< Pointer to hello message list. */

	struct node_information * next;	/**< Pointer to next node on the list. */
};


/** \typedef struct location location
 * \brief Typedef for location struct.
 */
typedef struct location location;
/** \typedef struct node_information node_information
 * \brief Typedef for node_information struct.
 */
typedef struct node_information node_information;

/** \var xmachine * temp_xmachine
* \brief Pointer to xmachine to initialise linked list. */
xmachine * temp_xmachine;

/** \var m_hello * temp_hello_message
* \brief Pointer to m_hello to initialise linked list. */
m_hello * temp_hello_message;
/** \var node_information * temp_node_info
* \brief Pointer to node_information to initialise linked list. */
node_information * temp_node_info;
/** \var char outputpath[1000]
* \brief Output path for files. */
char outputpath[1000];
/** \var long total_time
* \brief Total time for the simulation run (in seconds) */
double total_time;
/** \var int total_messages
* \brief Total messages sent between nodes for the simulation run */
int total_messages;
/** \var int totalnodes
* \brief Number of nodes */
int totalnodes;
/** \var xmachine ** p_xmachine
* \brief Pointer to first pointer of x-machine memory list */
//xmachine ** p_xmachine;
/** \var xmachine * current_xmachine
* \brief Pointer to current x-machine memory that is being processed */
xmachine * current_xmachine;
/* Pointer to current $agent_name agent */
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_Sender * current_xmachine_Sender;
/*@dependent@*/ xmachine_memory_Sender_holder * temp_xmachine_Sender_holder;
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_Sender_holder * current_xmachine_Sender_holder;
xmachine_memory_Sender_state * current_xmachine_Sender_next_state; /* New agents added to this state */
/* Pointer to list of Sender agents in state end_Sender state */
//xmachine_memory_Sender * temp_xmachine_Sender_end_Sender;
xmachine_memory_Sender_state * Sender_end_Sender_state;
/* Pointer to list of Sender agents in state start_Sender state */
//xmachine_memory_Sender * temp_xmachine_Sender_start_Sender;
xmachine_memory_Sender_state * Sender_start_Sender_state;
/* Pointer to current $agent_name agent */
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_Receiver * current_xmachine_Receiver;
/*@dependent@*/ xmachine_memory_Receiver_holder * temp_xmachine_Receiver_holder;
/*@dependent@*/ /*@null@*/ /*@out@*/ xmachine_memory_Receiver_holder * current_xmachine_Receiver_holder;
xmachine_memory_Receiver_state * current_xmachine_Receiver_next_state; /* New agents added to this state */
/* Pointer to list of Receiver agents in state end_Receiver state */
//xmachine_memory_Receiver * temp_xmachine_Receiver_end_Receiver;
xmachine_memory_Receiver_state * Receiver_end_Receiver_state;
/* Pointer to list of Receiver agents in state start_Receiver state */
//xmachine_memory_Receiver * temp_xmachine_Receiver_start_Receiver;
xmachine_memory_Receiver_state * Receiver_start_Receiver_state;



MBt_Board b_hello;
MBt_Iterator i_hello;


/** \var m_hello * hello_message
* \brief Pointer to message struct for looping through hello message list */
m_hello * hello_message;
/** \var FLAME_output ** FLAME_outputs
* \brief Pointer to list of outputs */
FLAME_output * FLAME_outputs;
/** \var node_information * p_node_info
* \brief Pointer to first pointer of node list */
node_information ** p_node_info;
/** \var node_information * current_node
* \brief Pointer to current node */
node_information * current_node;


/** \var int node_number\n
 *  \brief Node number (not needed for serial codes) */
int node_number;



/** \var int iteration_loop
* \brief The current iteration number */
int iteration_loop;
/** \var int output_frequency
* \brief Frequency to output results */
int output_frequency;
/** \var int output_offset
* \brief Offset to output results */
int output_offset;

/** \def SPINF
* \brief Dummy inf value for space partition data. */
#define SPINF 999999.123456
/** \def RELEASE
* \brief Used to kill an agent via 'return RELEASE;'. */
#define RELEASE 1
/** \def kill_me_now
* \brief Used to kill an agent via 'kill_me_now'. */
#define kill_me_now return 1

void initialise_pointers(void);
void initialise_unit_testing(void);
FLAME_output * add_FLAME_output(FLAME_output ** outputs);
void free_FLAME_outputs(FLAME_output ** outputs);
void add_location(double point, location ** p_location);
void freelocations(location ** p_location);
void add_node(int node_id, double minx, double maxx, double miny, double maxy, double minz, double maxz);
void clean_up(int code);
void propagate_agents(void);
void propagate_messages_init(void);
void propagate_messages_complete(void);
void create_partitions(char * filename, int * itno);
void free_node_info(void);
void free_agent(void);
void freexmachines(void);
/* model datatypes */

void init_int_static_array(/*@out@*/ int * array, int size);
void init_int_array(int_array * array);
void reset_int_array(int_array * array);
void free_int_array(int_array * array);
void copy_int_array(int_array * from, int_array * to);
//void sort_int_array(int_array array);
//int quicksort_int(int array, int elements);
void add_int(int_array * array, int new_int);
void remove_int(int_array * array, int index);
void print_int_array(int_array * array);
void init_float_static_array(float * array, int size);
void init_float_array(float_array * array);
void reset_float_array(float_array * array);
void free_float_array(float_array * array);
void copy_float_array(float_array * from, float_array * to);
//void sort_float_array(float_array array);
//int quicksort_float(float array, int elements);
void add_float(float_array * array, float new_float);
void remove_float(float_array * array, int index);
void print_float_array(float_array * array);
void init_double_static_array(/*@out@*/ double* array, int size);
void init_double_array(double_array * array);
void reset_double_array(double_array * array);
void free_double_array(double_array * array);
void copy_double_array(double_array * from, double_array * to);
//void sort_double_array(double_array array);
//int quicksort_double(double array, int elements);
void add_double(double_array * array, double new_double);
void remove_double(double_array * array, int index);
void print_double_array(double_array * array);
void init_char_static_array(/*@out@*/ char * array, int size);
void init_char_array(char_array * array);
void reset_char_array(char_array * array);
void free_char_array(char_array * array);
void copy_char_array(char_array * from, char_array * to);
void add_char(char_array * array, char new_char);
void remove_char(char_array * array, int index);
char * copy_array_to_str(char_array * array);
void print_char_array(char_array * array);
int idle(void);
/* xml.c */
int read_int_static_array(char * buffer, int buffer_size, int * j, int * int_static_array, int size);
int read_float_static_array(char * buffer, int buffer_size, int * j, float * float_static_array, int size);
int read_double_static_array(char * buffer, int buffer_size, int * j, double * double_static_array, int size);
int read_char_static_array(char * buffer, int buffer_size, int * j, char * char_static_array, int size);
int read_int_dynamic_array(char * buffer, int buffer_size, int * j, int_array * int_dynamic_array);
int read_float_dynamic_array(char * buffer, int buffer_size, int * j, float_array * float_dynamic_array);
int read_double_dynamic_array(char * buffer, int buffer_size, int * j, double_array * double_dynamic_array);
int read_char_dynamic_array(char * buffer, int buffer_size, int * j, char_array * char_dynamic_array);


void readinitialstates(char * filename, char * filelocation, int * itno, double cloud_data[],
					   int partition_method, int flag);
void saveiterationdata(int iteration_number);


xmachine_memory_Sender_state * init_Sender_state();
xmachine_memory_Sender * init_Sender_agent();
void free_Sender_agent(xmachine_memory_Sender_holder * tmp, xmachine_memory_Sender_state * state);
void transition_Sender_agent(xmachine_memory_Sender_holder * tmp, xmachine_memory_Sender_state * from_state, xmachine_memory_Sender_state * to_state);
void add_Sender_agent_internal(xmachine_memory_Sender * agent, xmachine_memory_Sender_state * state);
void add_Sender_agent(int id);
void unittest_init_Sender_agent();
void unittest_free_Sender_agent();
xmachine_memory_Receiver_state * init_Receiver_state();
xmachine_memory_Receiver * init_Receiver_agent();
void free_Receiver_agent(xmachine_memory_Receiver_holder * tmp, xmachine_memory_Receiver_state * state);
void transition_Receiver_agent(xmachine_memory_Receiver_holder * tmp, xmachine_memory_Receiver_state * from_state, xmachine_memory_Receiver_state * to_state);
void add_Receiver_agent_internal(xmachine_memory_Receiver * agent, xmachine_memory_Receiver_state * state);
void add_Receiver_agent(int id);
void unittest_init_Receiver_agent();
void unittest_free_Receiver_agent();

void add_hello_message(int id);
m_hello * add_hello_message_internal(void);
m_hello * get_first_hello_message(void);
m_hello * get_next_hello_message(m_hello * current);
void freehellomessages(void);


void set_id(int id);
int get_id();
int agent_get_id(void);
double agent_get_x(void);
double agent_get_y(void);
double agent_get_z(void);
/* partitioning.c */
void partition_data(int totalnodes, xmachine ** agent_list, double cloud_data[], int partition_method);


void save_partition_data(void);
void generate_partitions(double cloud_data[], int partitions, int partition_method);

/* messageboard.c */
m_hello * get_next_message_hello_in_range(m_hello * current);




/* memory.c */
xmachine * add_xmachine(void);


/* rules.c */
int FLAME_integer_in_array(int a, int * b, int size);

/* timing.c */
double get_time(void);

int sender_sends_mesg(void);
int receiver_reads_mesg(void);
#endif
