# Pset 1: Cash

Determine the smallest amout of coins to give change

Behave examples:
```
$ ./cash
Change owed: 41
4
```
```
$ ./cash
Change owed: -41
Change owed: foo
Change owed: 41
4
```

My code:
```
How much change do you need?
41
Total coins: 4
```

## Implementations Details

In `cash.c`, we’ve implemented most (but not all!) of a program that prompts the user for the number of cents that a customer is owed and then prints the smallest number of coins with which that change can be made. Indeed, `main` is already implemented for you. But notice how `main` calls several functions that aren’t yet implemented! One of those functions, `get_cents`, takes no arguments (as indicated by `void`) and returns an `int`. The rest of the functions all take one argument, an `int`, and also return an `int`. All of them currently return `0` so that the code will compile. But you’ll want to replace every `TODO` and `return 0;` with your own code. Specifically, complete the implementation of those functions as follows:

* Implement `get_cents` in such a way that the function prompts the user for a number of cents using `get_int` and then returns that number as an `int`. If the user inputs a negative `int`, your code should prompt the user again. (But you don’t need to worry about the user inputting, e.g., a `string`, as `get_int` will take care of that for you.) Odds are you’ll find a `do while` loop of help, as in `mario.c`!
* Implement `calculate_quarters` in such a way that the function calculates (and returns as an `int`) how many quarters a customer should be given if they’re owed some number of cents. For instance, if `cents` is `25`, then `calculate_quarters` should return `1`. If `cents` is `26` or `49` (or anything in between, then `calculate_quarters` should also return `1`. If `cents` is `50` or `74` (or anything in between), then `calculate_quarters` should return `2`. And so forth.
* Implement `calculate_dimes` in such a way that the function calculates the same for dimes.
* Implement `calculate_nickels` in such a way that the function calculates the same for nickels.
* Implement `calculate_pennies` in such a way that the function calculates the same for pennies.

Note that, unlike functions that only have side effects, functions that return a value should do so explicitly with `return`! Take care not to modify the distribution code itself, only replace the given `TODO`s and the subsequent `return` value!
Note too that, recalling the idea of abstraction, each of your calculate functions should accept any value of `cents` , not just those values that the greedy algorithm might suggest. If `cents` is 85, for example, `calculate_dimes` should return 8.

## Useful resources
- [CS50x - Pset 1: Cash](https://cs50.harvard.edu/x/2022/psets/1/cash/)

<br /><br />

## Author
<div sytle="display: inline-block;">
    <figure>
        <a href="https://github.com/bemibrando" target="_blank">
            <img style="border-radius: 50%;" src="https://avatars.githubusercontent.com/u/102377919?v=4" width="100px" alt="Bianca Emi profile's photo"> <br />
            <sub style="text-align: center; font-size: 1.4em;"><b>Bianca Emi</b></sub>
        </a>
    </figure>
    <p>Made with ♥ by <a href="https://github.com/bemibrando" target="_blank">Bianca Emi</a> 👋 Get in touch!</p>
    <div align="start">
        <a href="https://www.linkedin.com/in/bianca-emi/" target="_blank">
            <img src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white">
        </a>   
        <a href="https://twitter.com/bemibrando" target="_blank">
            <img src="https://img.shields.io/badge/Twitter-1DA1F2?style=for-the-badge&logo=twitter&logoColor=white">
        </a>   
        <a href="mailto: bemi.brando@outlook.com">
            <img src="https://img.shields.io/badge/bemi.brando@outlook.com-0078D4?style=for-the-badge&logo=microsoft-outlook&logoColor=white">
        </a><br/>
    </div>
</div>