#pragma once
/*
	upon creation
		introduces Player to a Monster
	method .roundStart
		gets base stats of both units
			round consists of two phases:
				-choice (each unit makes a choice)
				-action (each unit's chosen action is calculated, Player's coise is prioritised)
	method .action
		gets both unit's chosen actions
		evokes chosen action
	method .attack
		calculates unit's attact and damage to counterUnit
	method .defend
		calculates defence buff of a unit
	method .wasEvaded
		calculates evasion according to dexterity
*/
class Encounter
{
};

