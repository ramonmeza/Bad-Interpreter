# Simple Interpreter

A simple math interpreter.

## About

This interpreter takes a string containing math operations, uses the `Lexer` to
`Tokenize` the string into `Tokens`, which are then used by the `Interpreter`
to perform the operations.

## Building

### `g++`

Build: `g++ *.cpp *.hpp -o interpreter.o`
Run: `./interpreter.o`

### Docker

Build: `docker build . --tag interpreter`
Run: `docker run --rm -i interpreter:latest`
