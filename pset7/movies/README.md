# Pset7 - Movies

Write SQL queries to answer questions about a database of movies.

## Specification

For each of the following problems, you should write a single SQL query that outputs the results specified by each problem. Your response must take the form of a single SQL query, though you may nest other queries inside of your query. You <b>should not</b> assume anything about the `id`s of any particular movies or people: your queries should be accurate even if the `id` of any particular movie or person were different. Finally, each query should return only the data necessary to answer the question: if the problem only asks you to output the names of movies, for example, then your query should not also output each movie’s release year.

You’re welcome to check your queries’ results against <a href="https://www.imdb.com/">IMDb</a> itself, but realize that ratings on the website might differ from those in `movies.db`, as more votes might have been cast since we downloaded the data!

    1. In `1.sql`, write a SQL query to list the titles of all movies released in 2008.
        - Your query should output a table with a single column for the title of each movie.
    2. In `2.sql`, write a SQL query to determine the birth year of Emma Stone.
        - Your query should output a table with a single column and a single row (not counting the header) containing Emma Stone’s birth year.
        - You may assume that there is only one person in the database with the name Emma Stone.
    3. In `3.sql`, write a SQL query to list the titles of all movies with a release date on or after 2018, in alphabetical order.
        - Your query should output a table with a single column for the title of each movie.
        - Movies released in 2018 should be included, as should movies with release dates in the future.
    4. In `4.sql`, write a SQL query to determine the number of movies with an IMDb rating of 10.0.
        - Your query should output a table with a single column and a single row (not counting the header) containing the number of movies with a 10.0 rating.
    5. In `5.sql`, write a SQL query to list the titles and release years of all Harry Potter movies, in chronological order.
        - Your query should output a table with two columns, one for the title of each movie and one for the release year of each movie.
        - You may assume that the title of all Harry Potter movies will begin with the words “Harry Potter”, and that if a movie title begins with the words “Harry Potter”, it is a Harry Potter movie.
    6. In `6.sql`, write a SQL query to determine the average rating of all movies released in 2012.
        - Your query should output a table with a single column and a single row (not counting the header) containing the average rating.
    7. In `7.sql`, write a SQL query to list all movies released in 2010 and their ratings, in descending order by rating. For movies with the same rating, order them alphabetically by title.
        - Your query should output a table with two columns, one for the title of each movie and one for the rating of each movie.
        - Movies that do not have ratings should not be included in the result.
    8. In `8.sql`, write a SQL query to list the names of all people who starred in Toy Story.
        - Your query should output a table with a single column for the name of each person.
        - You may assume that there is only one movie in the database with the title Toy Story.
    9. In `9.sql`, write a SQL query to list the names of all people who starred in a movie released in 2004, ordered by birth year.
        - Your query should output a table with a single column for the name of each person.
        - People with the same birth year may be listed in any order.
        - No need to worry about people who have no birth year listed, so long as those who do have a birth year are listed in order.
        - If a person appeared in more than one movie in 2004, they should only appear in your results once.
    10. In `10.sql`, write a SQL query to list the names of all people who have directed a movie that received a rating of at least 9.0.
        - Your query should output a table with a single column for the name of each person.
        - If a person directed more than one movie that received a rating of at least 9.0, they should only appear in your results once.
    11. In `11.sql`, write a SQL query to list the titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated.
        - Your query should output a table with a single column for the title of each movie.
        - You may assume that there is only one person in the database with the name Chadwick Boseman.
    12. In `12.sql`, write a SQL query to list the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred.
        - Your query should output a table with a single column for the title of each movie.
        - You may assume that there is only one person in the database with the name Johnny Depp.
        - You may assume that there is only one person in the database with the name Helena Bonham Carter.
    13. In `13.sql`, write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.
        - Your query should output a table with a single column for the name of each person.
        - There may be multiple people named Kevin Bacon in the database. Be sure to only select the Kevin Bacon born in 1958.
        - Kevin Bacon himself should not be included in the resulting list.

## Useful resources

- [CS50x - Pset7: Movies](https://cs50.harvard.edu/x/2022/psets/7/movies/)
- [IMDb](https://www.imdb.com/)

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