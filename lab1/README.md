# Lab 1: Population Growth

Determine how long it takes for a populations to reach a particular size.

Behave example:
```
$ ./population
Start size: 100
End size: 200
Years: 9
```

My code:
```
$ ./population
How many lhamas do you have?
100
How many lhamas do you want to have?
200
Years: 9
You will need 9 years
```

## Implementations Details

Complete the implementation of "population.c", such that it calculates the number of years required for the population grow from the start size to the end size.
* Your program should first prompt the user for a starting population size.
	* If the user enters a number less than 9 (the minimum allowed population size), the user should be re-prompted to enter a starting population size until they enter a number that is greater than or equal to 9. (If we start with fewer than 9 llamas, the population of llamas will quickly become stagnant!)
* Your program should then prompt the user for an ending population size.
	* If the user enters a number less than the starting population size, the user should be re-prompted to enter an ending population size until they enter a number that is greater than or equal to the starting population size. (After all, we want the population of llamas to grow!)
* Your program should then calculate the (integer) number of years required for the population to reach at least the size of the end value.
* Finally, your program should print the number of years required for the llama population to reach that end size, as by printing to the terminal Years: n, where n is the number of years.

## Useful resources
- [CS50x - Lab 1: Population Growth](https://cs50.harvard.edu/x/2021/labs/1/population/)

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