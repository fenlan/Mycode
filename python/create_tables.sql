/*
    flights(string flightNum, int price, int numSeats, int numAvail, string FromCity, string ArivCity);
    hotels(string location, int price, int numRooms, int numAvail);
    bus(strig location, int price, int numBus, int numAvail);
    customers(string custName, custID);
    reservations(string custName, int resvType, string resvKey);
*/

USE bank067;

CREATE TABLE flights (
	flightNum			CHAR(10)			PRIMARY KEY,
	numSeats			INT(3),
	numAvail			INT(3),
	FromCity			CHAR(30),
	ArivCity			CHAR(30),
	price				INT(5)
);

CREATE TABLE hotels (
	location			VARCHAR(50)			PRIMARY KEY,
	numRooms			INT(4),
	numAvail			INT(4),
	price				INT(4)
);

CREATE TABLE bus (
	location			VARCHAR(50)			PRIMARY KEY,
	numBus				INT(2),
	numAvail			INT(2),
	price				INT(3)
);

CREATE TABLE customers (
	custID				INT(4)				PRIMARY KEY,
	custName			VARCHAR(30)
);

CREATE TABLE reservations (
	custName			VARCHAR(30),
	resvType			INT(1),
	resvKey				VARCHAR(50),
	PRIMARY KEY (custName, resvKey),
	CHECK(resvType IN('1','2','3'))
);
