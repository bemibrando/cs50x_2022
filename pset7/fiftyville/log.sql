-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Analyze the description of the crime
SELECT description FROM crime_scene_reports
WHERE year = 2021 AND month = 7 AND day = 28 AND street = "Humphrey Street";
-- at 10:15 at the Humphrey Street bakery. 
-- Interviews with three witnesses
-- each of their interview transcripts mentions the bakery.

SELECT transcript FROM interviews
WHERE year = 2021 AND month = 7 AND day = 28 AND transcript LIKE "%bakery%";

-- First Transcipt
-- Sometime within ten minutes of the theft
-- I saw the thief get into a car in the bakery parking lot and drive away
SELECT name FROM people
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
WHERE year = 2021 AND month = 7 AND day = 28 
AND hour = 10 AND minute >= 15 AND minute <= 25 
AND activity = "exit";
-- Suspects list:
-- Vanessa || Bruce || Barry || Luca || Sofia || Iman || Diana || Kelsey

-- Second Transcript
-- I was walking by the ATM on Leggett Street
-- saw the thief there withdrawing some money
SELECT name AS "BANK" FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE year = 2021 AND month = 7 AND day = 28
AND atm_location = "Leggett Street"
AND transaction_type = "withdraw"
ORDER BY name;
-- Suspects list:
-- Benista || Brooke || Bruce || Diana || Iman || Kenny || Luca || Taylor


-- Common suspects
SELECT DISTINCT(name) FROM people
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
JOIN bank_accounts ON bank_accounts.person_id = people.id
WHERE bakery_security_logs.license_plate IN (
SELECT bakery_security_logs.license_plate FROM bakery_security_logs
WHERE year = 2021 AND month = 7 AND day = 28 
AND hour = 10 AND minute >= 15 AND minute <= 25 
AND activity = "exit")
AND bank_accounts.person_id in (
SELECT bank_accounts.person_id FROM bank_accounts
JOIN people ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE year = 2021 AND month = 7 AND day = 28
AND atm_location = "Leggett Street"
AND transaction_type = "withdraw")
ORDER BY name;
-- Suspects list:
-- Bruce || Diana || Iman || Luca

-- Third Transcript
-- They called someone who talked to them for less than a minute
SELECT DISTINCT(people.name) FROM people
JOIN phone_calls ON phone_calls.caller = people.phone_number
AND phone_calls.year = 2021 AND phone_calls.month = 7 AND phone_calls.day = 28
AND phone_calls.duration <= 60
ORDER BY name;
-- Common Suspects list:
-- Bruce || Diana

-- Third Transcript
-- they were planning to take the earliest flight out of Fiftyville tomorrow.
SELECT DISTINCT(people.name) FROM people
JOIN passengers ON passengers.passport_number = people.passport_number
WHERE passengers.flight_id = (
SELECT id FROM flights
    WHERE year = 2021 AND month = 7 AND day = 29
    AND origin_airport_id = (
        SELECT id FROM airports WHERE city = "Fiftyville")
ORDER BY hour, minute
LIMIT 1);
-- Common Suspects list:
-- Bruce
-- Thief name: Bruce

-- Where
SELECT city FROM airports
WHERE id = (
SELECT destination_airport_id FROM flights
    WHERE year = 2021 AND month = 7 AND day = 29
    AND origin_airport_id = (
        SELECT id FROM airports WHERE city = "Fiftyville")
ORDER BY hour, minute
LIMIT 1);
--Destination: New York City

SELECT name FROM people 
WHERE phone_number = (
SELECT receiver FROM phone_calls
WHERE year = 2021 AND month = 7 AND day = 28
AND duration < 60
AND caller = (
SELECT phone_number FROM people
WHERE name = "Bruce"));
-- Accomplice: Robin