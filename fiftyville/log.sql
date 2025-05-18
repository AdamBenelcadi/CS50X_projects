//crime_scene_reports
SELECT description FROM crime_scene_reports WHERE month = 7 AND day = 28 AND street = "Humphrey Street";
*the theft of the cs50 duck took place at 10:15 am
each of the three witnesses intreview transcripts mentions the bakery
//interviews
SELECT * FROM interviews WHERE month = 7 AND day = 28;
*after 10 minutes of the theft the thieve got into a car in the bakery parking lot and drove away(look for the security footage from bakery parking lot to see
the car that left the parking lot in that time frame)
*i don't know the thief's name, but it was someone i recognized. the ATM on Leggett Street and saw the thief there withdrawing money
*as the thieve was leaving the bakery, they called someone who talked to them for less than a minute in the call the thief say that they were planning to take
the earliest flight out of fiftyville tomorrow ; the thieve then asked the person on the other end of the phone to purchase the flight ticket.
//flights
SELECT * FROM flights WHERE month = 7 AND day = 29;
from here we observe that the the origin_airport_id=8 and the earliest flight destination_airport_id = 4 the hour=8 and minute = 20
//original airport
SELECT * FROM airports WHERE id = 8;
//direction airport
SELECT * FROM airports WHERE id = 4;

""""From here We conclude that the The city the thief ESCAPED TO is NEW York City""""

//atm_transactions
SELECT * FROM atm_transactions WHERE month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type != "deposit";
//bank_accounts
SELECT * FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type != "deposit");
//phone_calls
SELECT * FROM phone_calls WHERE month = 7 AND day = 28 AND duration <= 60;
//bakery_security_logs
SELECT license_plate, hour, minute, activity FROM bakery_security_logs WHERE month = 7 AND day = 28 AND hour = 10 and minute >= 15 AND minute <= 25;
//people
SELECT * FROM people WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type != "deposit")) AND phone_number IN (SELECT caller FROM phone_calls WHERE month = 7 AND day = 28 AND duration <= 60) AND license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28 AND hour = 10 and minute > 15 AND minute <= 25);
//passengers
SELECT * FROM passengers WHERE passport_number IN (SELECT passport_number FROM people WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type != "deposit")) AND phone_number IN (SELECT caller FROM phone_calls WHERE month = 7 AND day = 28 AND duration <= 60) AND license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND minute > 15 AND minute <= 25));
the one behind the passeport number 3592750733 is reserving more than a flight so it will be eliminated from the suspect's list
SELECT * FROM passengers WHERE passport_number IN (SELECT passport_number FROM people WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type != "deposit")) AND phone_number IN (SELECT caller FROM phone_calls WHERE month = 7 AND day = 28 AND duration <= 60) AND license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND minute > 15 AND minute <= 25)) AND passport_number != 3592750733;

""" Now we conclude that the one behind the theft is the owner of the passeport number = 5773159633 """

if i found the thief i will easily find the acomplice by refereing to phone_calls and also the city the thief escaped to by refering to passengers

SELECT name, phone_number FROM people WHERE passport_number = 5773159633;

""" From here we can see the passport number=5773159633 owner is called Bruce and his phone numer is (367) 555-5533 that is going to help us to find the accomplice name """

SELECT receiver FROM phone_calls WHERE caller = "(367) 555-5533" AND month = 7 AND day = 28 AND duration < 60;

""" the phone number of the receiver's phone number (accomplice) = (375) 555-8161 """

SELECT name FROM people WHERE phone_number = "(375) 555-8161";

""" The accomlice name is Robin """
