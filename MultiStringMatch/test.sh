#!/bin/bash


./test -1 "Her colleagues are generally biased against her. " are biase
./test -1 "Her colleagues are generally biased against her. " are biaseeeeee
./test -1 "Her colleagues are generally biased against her. " are
./test -1 "Her colleagues are generally biased against her. " ArE

echo 
echo '*********************************************'
echo 

./test -2 "Her colleagues are generally biased against her. " are biase
./test -2 "Her colleagues are generally biased against her. " are biaseeeeee
./test -2 "Her colleagues are generally biased against her. " are
./test -2 "Her colleagues are generally biased against her. " ArE

