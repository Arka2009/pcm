#!/bin/bash

suffix=$(git log -1 '--pretty=format:%h')

# make
for fl in ${PWD}/*.x; do
    fl2="$(basename ${fl})"
    fl3="$fl2.build_$(hostname).$suffix"
    mv $fl2 $fl3
    scp ${fl3} amaity@taurus:/home/amaity/Desktop/hostphypkg_ebe2e65/HostStatusTools
done