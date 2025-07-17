#!/bin/bash

printf "Char: \n"

res=$(./convert a);
expected='char: a
int: 97
float: 97.0f
double: 97.0'

if [[ "$res" != "$expected" ]]; then
    printf "\e[0;31mKO \e[0m"
    echo "$res"
else
    printf "\e[0;32mOK \e[0m"
fi

res=$(./convert .);
expected='char: .
int: 46
float: 46.0f
double: 46.0'

if [[ "$res" != "$expected" ]]; then
    printf "\e[0;31mKO \e[0m"
    echo "$res"
else
    printf "\e[0;32mOK \e[0m"
fi

printf "\n"
