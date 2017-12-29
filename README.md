# Fire Emblem Summon Calculator

The purpose of this program was to determine the optimal summoning strategy for given percents for the best 5star/orb ratio.

## How Summoning works in Fire Emblem

Summoning happens in sessions. You may summon up to 5 characters per a session. The orb cost is as followed.
1: 5, 2: 4, 3: 4, 4: 4, 5: 3.
Every summon has a chance at a 5star character. The chance is set per a summon session.
Every 5 characters summoned without a 5star, the chance of 5star increases by .5. Every 5star summon resets the chance to it's base value.

## The problem to be solved

At sufficiently low percents, the best chance is to always summon all 5 characters, as the orb cost is decreased.
At sufficiently high percents, it would be better to not continue summoning if you do not get a 5star.
The querstion is what consitutes a high enough percent that summoning 5 characters is no longer the optimal strategy.

## How this program solves it

It runs a very large amount of times, and calculates the average number of 5star characters received with the given strategy and given number of orbs.
Within a few test trials, you can quickly narrow down roughly where the percent is at, and what the optimal strategy becomes.

## Results

Starting at 19% chance, summoning 2 heroes until receiving a 5star gives a better 5star/orb ratio than the standard 'summon all 5'. 
http://i.imgur.com/Ivd9lDX.png

## How to run

Simple change the constants listed at the top to desired, compile and run. 

## Programming Environment

C++, Notepad++, Windows 7

## Author

Peter Bengtson

## Date Created

Febuary, 2017