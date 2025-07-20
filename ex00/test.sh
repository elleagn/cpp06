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

printf "Int:\n"

res=$(./convert 2147483647)
expected='char: impossible
int: 2147483647
float: 2.14748e+09f
double: 2.14748e+09'

if [[ "$res" != "$expected" ]]; then
    printf "\e[0;31mKO \e[0m"
    echo "$res"
else
    printf "\e[0;32mOK \e[0m"
fi

res=$(./convert -2147483648)
expected='char: impossible
int: -2147483648
float: -2.14748e+09f
double: -2.14748e+09'

if [[ "$res" != "$expected" ]]; then
    printf "\e[0;31mKO \e[0m"
    echo "$res"
else
    printf "\e[0;32mOK \e[0m"
fi

res=$(./convert 4)
expected='char: non displayable
int: 4
float: 4.0f
double: 4.0'

if [[ "$res" != "$expected" ]]; then
    printf "\e[0;31mKO \e[0m"
    echo "$res"
else
    printf "\e[0;32mOK \e[0m"
fi

printf "\n"
