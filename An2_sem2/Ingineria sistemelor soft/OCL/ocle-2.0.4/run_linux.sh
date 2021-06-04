#!/bin/sh
# The Java interpreter must be in PATH
# Set OCLE_HOME to the directory where the distribution was unpacked

# OCLE_HOME=/usr/ocle

if [ "$OCLE_HOME" == "" ]; then 
    echo "Please set the OCLE_HOME environment variable to the directory where the distribution was unpacked. "
    exit 1
fi

OCLE_LIB=${OCLE_HOME}/lib

java -Xms192m -Xmx192m -Djava.library.path=${OCLE_LIB} -classpath ${OCLE_LIB}/jgraph.jar:${OCLE_LIB}/kLF.jar:${OCLE_LIB}/template.jar:${OCLE_LIB}/velocity-dep-1.3.jar:${OCLE_LIB}/Whiteboard.jar:${OCLE_HOME}/bin ro.ubbcluj.lci.gui.mainframe.GApplication