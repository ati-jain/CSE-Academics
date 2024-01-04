#!/bin/bash
while read -r line;do
if [[ $line =~ (^| )"$2"( |$) ]];then
echo "$line"|sed 's/[A-Z]/\L&/g'|sed 's/[a-zA-Z][^a-z^A-Z]*.\?/\u\0/g';else echo "$line";fi;done<$1
