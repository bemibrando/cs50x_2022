# Pset 2: Readability

For this problem, you’ll implement a program that calculates the approximate grade level needed to comprehend some text, per the below.

```
$ ./readability
Text: Congratulations! Today is your day. You're off to Great Places! You're off and away!
Grade 3
```

My code:
```
$ ./readability
Paste a text to calculate the readability 
Congratulations! Today is your day. You're off to Great Places! You're off and away!
Grade 3
```

## Implementations Details

Design and implement a program, `readability`, that computes the Coleman-Liau index of text.

* Implement your program in a file called `readability.c` in a directory called `readability`.
* Your program must prompt the user for a `string` of text using `get_string`.
* Your program should count the number of letter, words, and sentences in the text. You may assume that a letter is any lowercase character from `a` to `z` or any uppercase character from `A` to `Z`, any sequence of character separated by spaces should count as a word, and that any occurrence of a period, exclamation point, or question mark indicates the end of a sentence.
* Your program should print as output `"Grade X"` where `X` is the grade level computed by the Coleman-Liau formula, rounded to the nearest integer.
* If the resulting index number is 16  or higher (equivalent to greater than a senior undergraduate reading level), your program should output `""Grade 16+" instead of giving the exact index number. If the index number is less than 1, your program should output `"Before Grade 1"`.

## Useful resources
- [CS50x - Pset 2: Readability](https://cs50.harvard.edu/x/2022/psets/2/readability/)

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