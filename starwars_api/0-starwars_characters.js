#!/usr/bin/node

const { exit } = require('process');
const request = require('request');

const movieNumb = process.argv[2];
if (!movieNumb)
{
    console.log("movie don't found, please write: ./0-starwars_characters.js <number of the movie>")
    process.exit(1);
}

const url = `https://swapi-api.hbtn.io/api/films/${movieNumb}/`;

request(url, function(err, res, body){
    if (err) {
        exit(1)
    }

    const movie = JSON.parse(body);
    const characterMovie = movie.characters;
    
    const printAllCharacters = (length) => {
        if (length >= characterMovie.length) {
            return;
        }

        request(characterMovie[length], (err, res, body) => {
            if(!err) {
                const people = JSON.parse(body);
                console.log(people.name);
            }
            printAllCharacters(length + 1);
        })
    }

    printAllCharacters(0);
})