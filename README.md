<!--HEADER-->
<h1 align="center"> So_long
</h1>
<!--FINISH HEADER-->

<!--MINI DESCRIPTION-->
> A project involving the creation of a ***small 2D game*** with a graphical library. Using MiniLibX, the 42 graphical library.

 
### What is the project about

This project is focused on developing a 2D game that can be interacted with using your keyboard. The task is divided into two parts: the mandatory and the bonus. Each of these parts is compiled and executed separately. The bonus section includes the same features as the mandatory part, along with some additional enhancements.

## General Instrucctions
* Makefile will compile your source files. It must include 'all' and 'bonus' rules for the Mandatory and Bonus parts, respectively. It should not relink.
* You are required to use MiniLibX for this project.
* The program should be compiled using the following commands:
 
```shell
> ./so_long map.ber
> ./so_long_bonus map.ber
```


> [!WARNING]
> Maps must have the ***.ber*** extension

## Mandatory Instrucctions
* The number of movements must be displayed in the shell.
* Pressing <kbd>ESC</kbd> or closing the window should result in quitting the program.

* The map must be constructed using five components: **walls**, **collectibles** (at least one), **empty spaces**, **exits** (at least one), and **the player** (only one). These five characters compose the map: 
  * **0** for an empty space
  * **1** for a wall
  * **C** for a collectible
  * **E** for a map exit
  * **P** for the player’s starting position

* To move the main character, use the <kbd>W</kbd> <kbd>A</kbd> <kbd>S</kbd> <kbd>D</kbd> keys:
  * <kbd>W</kbd> to move up ↑
  * <kbd>S</kbd> to move down ↓
  * <kbd>D</kbd> to move right ➞
  * <kbd>A</kbd> to move left ←

## Bonus Instrucctions

* Add **X** to the map for spawn patrols 
* Make the player lose when they touch an enemy patrol
* Add some sprite animation. 
* Display the movement count directly on screen instead of writing it in the shell.
 
### How to compile it
> Compilation is managed through the Makefile rules.


* If you use <kbd>make</kbd> command, the ***./so_long*** executable file, will be generated.
* You can use <kbd>make bonus</kbd> command to generate the ***./so_long_bonus*** executable file

```shell
> make
> make bonus
```
