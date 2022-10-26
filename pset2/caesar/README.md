# Pset 2: Caesar

For this problem, you’ll implement a program that encrypts messages using Caesar’s cipher, per the below.

```
$ ./caesar 13
plaintext:  HELLO
ciphertext: URYYB
```

My code:
```
$ ./caesar 13
plaintext: HELLO
ciphertext: URYYB
```

## Implementations Details

Design and implement a program, `caesar`, that encrypts messages using Caesar's cipher.

* Implement your program in a file called `caesar.c` in a directory called `caesar`.
* Your program must accept a single command-line argument, a non-negative integer. Let's call it ***k*** for the sake of disscussion.
* If your program is executed without any command-line arguments or with more than one command-line argument, your program should print an error message of your choice (with `printf`) and return from `main` a value of `1` (which tend to signify and error) immediately.
* If any of the characters of the command-line argument is not a decimanl digit, your program should print the message `Usage: ./caesar key` and return from `main` a value `1`.
* Do not assume that ***k*** less than ***2^31 - 26***. In other words, you don’t need to worry if your program eventually breaks if the user chooses a value for ***k*** that’s too big or almost too big to fit in an `int`. (Recall that an `int` can overflow.) But, even if ***k*** is greater than ***26***, alphabetical characters in your program’s input should remain alphabetical characters in your program’s output. For instance, if ***k*** is ***27***, `A` should not become `\` even though `\` is ***27*** positions away from A in ASCII, per asciichart.com; `A` should become `B`, since `B` is ***27*** positions away from `A`, provided you wrap around from `Z` to `A`.
* Your program must output `plaintext:` (with two spaces but without a newline) and then prompt the user for a `string` of plaintext (using `get_string`).
* Your program must output `ciphertext:` (with one space but without a newline) followed by the plaintext’s corresponding ciphertext, with each alphabetical character in the plaintext “rotated” by k positions; non-alphabetical characters should be outputted unchanged.
* Your program must preserve case: capitalized letters, though rotated, must remain capitalized letters; lowercase letters, though rotated, must remain lowercase letters.
* After outputting ciphertext, you should print a newline. Your program should then exit by returning `0` from `main`.

## Useful resources
- [CS50x - Pset 2: Caesar](https://cs50.harvard.edu/x/2022/psets/2/caesar/)

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