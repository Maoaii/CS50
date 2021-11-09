-- Check a crime report that matches the time and place of the crime:
SELECT description FROM crime_scene_reports WHERE street = "Chamberlin Street" AND day = "28" AND month = "7" AND year = "2020";
    -- Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse.
    -- Interviews were conducted today with three witnesses who were present at the time
    -- — each of their interview transcripts mentions the courthouse.


-- Check interviews from the witnesses to get clues.
SELECT name, transcript FROM interviews WHERE day = "28" AND month = "7" AND year = "2020";
    -- Ruth | Sometime within ten minutes of the theft,
    -- I saw the thief get into a car in the courthouse parking lot and drive away.
    -- If you have security footage from the courthouse parking lot,
    -- you might want to look for cars that left the parking lot in that time frame.

    -- Eugene | I don't know the thief's name, but it was someone I recognized.
    -- Earlier this morning, before I arrived at the courthouse,
    -- I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.

    -- Raymond | As the thief was leaving the courthouse, they called someone who talked to them for less than a minute.
    -- In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
    -- The thief then asked the person on the other end of the phone to purchase the flight ticket.


-- Go with Ruth's clue. Get the name, phone number, passport number, license plate and bank account number
-- from whomever left within 10 minutes of the crime.
SELECT name, phone_number, passport_number, people.license_plate, bank_accounts.account_number, courthouse_security_logs.activity FROM people
JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.license_plate
JOIN bank_accounts ON people.id = bank_accounts.person_id
WHERE minute >= "15" AND minute <= "25" AND hour = "10" AND day = "28";
    -- name | phone_number | passport_number | license_plate | account_number | activity
    -- Ernest | (367) 555-5533 | 5773159633 | 94KL13X | 49610011 | exit
    -- Russell | (770) 555-1861 | 3592750733 | 322W7JE | 26013199 | exit
    -- Elizabeth | (829) 555-5269 | 7049073643 | L93JTIZ | 25506511 | exit
    -- Danielle | (389) 555-5198 | 8496433585 | 4328GD8 | 28500762 | exit
    -- Amber | (301) 555-4174 | 7526138472 | 6P58WS2 | 56171033 | exit


-- Go with Raymond's clue. Check all our suspects and see whomever had a phone call the day of the crime
-- that lasted less than a minute.
SELECT caller, receiver, duration FROM phone_calls WHERE duration <= "60" AND day = "28" AND month = "7" AND caller IN
("(367) 555-5533", "(770) 555-1861", "(389) 555-5198", "(301) 555-4174");
    -- caller | receiver | duration
    -- (367) 555-5533 | (375) 555-8161 | 45
    -- (770) 555-1861 | (725) 555-3243 | 49

    -- Get the name of the callers and their receivers, respectively
    SELECT phone_number, name FROM people WHERE phone_number IN
    ("(367) 555-5533", "(770) 555-1861", "(375) 555-8161", "(725) 555-3243");
        -- phone_number | name
        -- (770) 555-1861 | Russell
        -- (367) 555-5533 | Ernest
        -- (725) 555-3243 | Philip
        -- (375) 555-8161 | Berthold

    -- Either Russel or Ernest can be the thief and either Philip or Berthold can be the accomplice


--Check the last clue, Eugene's one. Check which one of them was at the Fifer Street's ATM on the day of the crime
SELECT account_number, transaction_type, amount FROM atm_transactions 
WHERE day = "28" AND month = "7" AND atm_location = "Fifer Street" AND account_number IN 
(SELECT account_number FROM bank_accounts WHERE person_id IN 
(SELECT id FROM people WHERE name IN ("Russel", "Ernest")));
    -- account_number | transaction_type | amount
    -- 49610011 | withdraw | 50
    
    -- That account number corresponds to Ernest's, so he must be our thief. Consequently, Berthold is the accomplice


-- Now, to see where Ernest flew to after the crime. Check Fiftyville's airport name and id.
SELECT full_name, id FROM airports;
    -- full_name | id
    -- Fiftyville Regional Airport | 8

    -- Get the city and airport to which Ernest flew.
    SELECT city, full_name FROM airports WHERE id IN
    (SELECT destination_airport_id FROM flights WHERE origin_airport_id = "8" AND day = "29" AND month = "7" AND id IN
    (SELECT flight_id FROM passengers WHERE passport_number = "5773159633"));
        -- city | full_name
        -- London | Heathrow Airport


-- With all this, we can conclude that Ernest stole the duck and flew to London with the help of Berthold.