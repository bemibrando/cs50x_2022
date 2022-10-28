# Pset 4: Filter (less)

Implement a program that applies filter to BMPs.

- Grayscale: Convert an image to black-and-white.
- Sepia: Give image an old-timey feel by making the whole image look a bit reddish-brown.
- Reflect: should take an image and reflect horizontally.
- Blur: Take an image and turn it into a box-blurred version of the same image.

## Implementations Details

Implement the functions in `helpers.c` such that a user can apply grayscale, reflection, blur, or edge detection filters to their images.

- The function `grayscale` should take an image and turn it into a black-and-white version of the same image.
    - Make the red, green, and blue values are all the same value.
    - Take the average of the red, green and blue values to determine what shade of grey to make the new pixel. 
- The function `sepia` should take an image and turn it into a sepia version of the same image.
    - There are a number of algorithms for converting an image to sepia, but for this problem, we'll ask you to use the following algorithm. For each pixel, the sepia color values should be calculated based on the original color values per the below.
        ```
        sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
        sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
        sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue
        ```
- The `reflect` function should take an image and reflect it horizontally.
    - Move pixels around, pixels on the left side of the image should end up on the right, and vice versa.
- The `blur` function should take an image and turn it into a box-blurred version of the same image.
    - use the "box blur" 3x3 which works by taking each pixel and, for each value, giving it a new value by averaging the color values of neighboring pixels.
    - Its important to take a copy of the original image before start to edit it.

You should not modify any of the function signatures, nor should you modify any other files other than `helpers.c`.

## Useful resources

- [CS50x - Pset 4: Filter (less)](https://cs50.harvard.edu/x/2022/psets/4/filter/less/)

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