# Pset 2: Substitution

For this problem, you’ll write a program that implements a substitution cipher, per the below.

```
$ ./substitution JTREKYAVOGDXPSNCUIZLFBMWHQ
plaintext:  HELLO
ciphertext: VKXXN
```

My code:
```
$ ./substitution JTREKYAVOGDXPSNCUIZLFBMWHQ
Enter text: HELLO
ciphertext: VKXXN
```

## Implementations Details

Design and implement a program, `substitution`, that encrypts messages using a substitution cipher.

* Implement your program in a file called `substitution.c` in a directory called `substitution`.
* Your program must accept a single command-line argument, the key to use for the substitution. The key itself should be case-insensitive, so whether any character in the key is uppercase or lowercase should not affext the behavior of your program.
* If your program is executed without any command-line arguments or with more than one command-line argument, your program should print an error message of your choice (with `printf`) and return from `main` a value of `1` (which tends to signify an error) immediately.
* If the key is invalid (as by not containing 26 characters, containing any character that is not an alphabetic character, or not containing each letter eactly once), your program should print an error message of your choice (with `printf`) and return from `main` a value of `1` immediately.
* Your program must output `plaintext:` (without a new line) and then prompt the user for a string of plaintext (using `get_string`).
* Your program must output `ciphertext:` (without a newline) followed by the plaintext’s corresponding ciphertext, with each alphabetical character in the plaintext substituted for the corresponding character in the ciphertext; non-alphabetical characters should be outputted unchanged.
* Your program must preserve case: capitalized letters must remain capitalized letters; lowercase letters must remain lowercase letters.
* After outputting ciphertext, you should print a newline. Your program should then exit by returning `0` from `main`.

## Useful resources
- [CS50x - Pset 2: Substitution](https://cs50.harvard.edu/x/2022/psets/2/substitution/)

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