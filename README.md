# Corewar

Corewar is a School 42 project. The purpose of this project is an implementation of the programming game **“Core War”**.

![Corewar](/ressources/corewar.svg)

- What is Corewar?
Corewar is a very peculiar game. It’s about bringing “players” together around a “virtual machine”, which will load some “champions” who will fight against one another with the support of “processes”, with the objective being for these champions to stay “alive”.

![Subject](/ressources/corewar.pdf)

## Ressources

- [Excel Summary!](https://docs.google.com/spreadsheets/d/13QWDmu6EnSz9ZHSQanRRWV44hpNNjZ5Gd0eIAo8Z2i0/edit#gid=0)

- [Cook Book!](https://github.com/VBrazhnik/Corewar/wiki)

## Project Structure

This project consists of five parts:

* Champion **slawi**
* Assembler
* Disassembler (Bonus)
* Virtual Machine
* Visualizer (Bonus)

## Compile

Clone repository and then go into the created directory and run the following command:

create the **asm** & **corewar** progerams

- Run `make`

## Usage

### `asm`

```
Usage: ./asm (champion.s|champion.cor)
    champion.s   — from assemble to bytecode
    champion.cor — from bytecode to assemble
```

### `desasm`

### `corewar`

```
Usage: ./corewar [-a (-dump|-d) <num> (-shed|-s) <num> -l <num>] [-v] [-n <num>] <champion.cor> <...>
    -a          : Print output from "aff" (Default is off)
    -dump <num> : Dump memory (32 octets per line) after <num> cycles and exit
    -d    <num> : Dump memory (64 octets per line) after <num> cycles and exit
    -show <num> : Run <num> cycles, dump memory (32 octets per line), pause and repeat
    -s    <num> : Run <num> cycles, dump memory (64 octets per line), pause and repeat
    -l    <num> : Log levels
                   1  : Show lives
                   2  : Show cycles
                   4  : Show operations
                   8  : Show deaths
                   16 : Show PC movements
    -v          : Run visualizer
    -n    <num> : Set <num> of the next player
```

## Visualizer

![Visualizer](/ressources/displayer.jpg)


## Owners
### team: Memory-Rapists
- Oussama Belouche 1337
- Ilyas Shaimoun 1337
- Ayoub Aguert 1337

#
[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/oooo-kill-em.svg)](https://forthebadge.com)

