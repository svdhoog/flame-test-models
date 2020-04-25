#!/bin/bash

# set parser mode
export PARSE_DEBUG=1
export PARSE_PRODUCTION=0
export PARSE_SERIAL=1
export PARSE_PARALLEL=0

# Set base dir
export BASE='/media/sander/DataStorage1/GIT/GitLab/ETACE-GIT/svn-import'
#export BASE='/home/svanderh/files-server-CHEOPS'
#export BASE='/home/svdhoog/files-server/SVN/unibi-svn/'

echo "BASE=$BASE"

echo 'Starting XParsing'

#export FLAME_XPARSER_DIR='$BASE/tags/xparser-0.16.2'
#export FLAME_XPARSER_DIR='$BASE/tags/xparser-gsl'
#export FLAME_XPARSER_DIR="$BASE/tags/xparser-0.17.1"
export FLAME_XPARSER_DIR="/media/sander/DataStorage1/GIT/GitLab/ABM@ECB/ABM_at_ECB/code/utils/xparser-0.17.1"
echo "FLAME_XPARSER_DIR=$FLAME_XPARSER_DIR"

# Financial Fragility model
#export MODEL_DIR="$BASE/branches/Sander/Financial_Fragility_Network_Model"

# Default model
export MODEL_DIR=$PWD

echo "MODEL_DIR=$MODEL_DIR"

cd $FLAME_XPARSER_DIR
echo "Now in: $PWD"

#($FLAME_XPARSER_DIR)/xparser eurace_model.xml

#Parse in normal mode: DEBUG and SERIAL
if (($PARSE_DEBUG && $PARSE_SERIAL)); then
 ./xparser -s $MODEL_DIR/model.xml
 echo 'XParsing done.'
 cd $MODEL_DIR
 make clean all
 echo 'Compilation done.'
 mv main main_sd
 echo 'Moved main ->main_sd'
fi

#Parse in parallel mode: DEBUG and PARALLEL
# NOTE: You need mpicc
if (($PARSE_DEBUG && $PARSE_PARALLEL)); then
 ./xparser -p $MODEL_DIR/model.xml
 echo 'XParsing done.'
 cd $MODEL_DIR
 make clean all
 echo 'Compilation done.'
 mv main main_pd
 echo 'Moved main ->main_pd'
fi

#Parse in production mode: PRODUCTION and SERIAL
# NOTE: Compiler output does not produce as many warnings as debug mode
if (($PARSE_PRODUCTION && $PARSE_SERIAL)); then
	./xparser -s -f $MODEL_DIR/model.xml
	echo 'XParsing done.'
	cd $MODEL_DIR
	make clean all
	echo 'Compilation done.'
	mv main main_sf
	echo 'Moved main ->main_sf'
fi

#Parse in production mode: PRODUCTION and PARALLEL
# NOTE: You need mpicc
# NOTE: Compiler output does not produce as many warnings as debug mode
if (($PARSE_PRODUCTION && $PARSE_PARALLEL)); then
	./xparser -p -f $MODEL_DIR/model.xml
	echo 'XParsing done.'
	cd $MODEL_DIR
	make clean all
	echo 'Compilation done.'
	mv main main_pf
	echo 'Moved main ->main_pf'
fi

echo 'Script done.'
