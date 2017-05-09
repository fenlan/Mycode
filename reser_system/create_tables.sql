/* ----------------------------------------------------------
    Author: fenlan
    Update: 2017.5.3
    function: Create tables for travel reservation system.
   ----------------------------------------------------------
    Flight----------AirlineID       numeric(10)    PRIMARY KEY
                ----AirNum          char(10)
                ----Source          char(20)
                ----Destination     char(20)
                ----Source_Time     datetime
                ----Arr_Time        datetime
                ----Price           numeric(10,2)

    Hotels----------HotelID         numeric(10)     PRIMARY KEY
                ----Hotel_name      char(20)
                ----Location        char(50)
                ----RoomID          char(5)
                ----CheckIn_Time    datetime
                ----CheckOut_Time   datetime
                ----Room_Status     bool
                ----Price           numeric(10,2)

    Bus-------------BusID           numeric(10)    PRIMARY KEY
                ----BusNum          char(10)
                ----Source          char(20)
                ----Destination     char(20)
                ----Source_Time     datetime
                ----Arr_Time        datetime
                ----Price           numeric(10,2)

    Customers-------Cust_Name       char(20)    primary key
                ----Age             numeric(3)
                ----Sex             bool(0->female 1->male)

    Reservation-----Cust_Name       char(20)
                ----AirlineID       numeric(10)
                ----HotelID         numeric(10)
                ----BusID           numeric(10)
   -----------------------------------------------------------
*/

USE reser_system;

CREATE TABLE flight (
    AirlineID       numeric(10)    PRIMARY KEY,
    AirNum          char(10),
    Source          char(20),
    Destination     char(20),
    Source_date     date,
    Source_Time     time,
    Arr_date        date,
    Arr_Time        time,
    Price           numeric(10,2)
);

CREATE TABLE hotels (
    HotelID         numeric(10)     PRIMARY KEY,
    Hotel_name      char(20),
    Location        char(50),
    RoomID          char(5),
    CheckIn_date    date,
    CheckIn_Time    time,
    CheckOut_date   date,
    CheckOut_Time   time,
    Room_Status     boolean,
    Price           numeric(10,2)
);

CREATE TABLE bus (
    BusID           numeric(10)    PRIMARY KEY,
    BusNum          char(10),
    Source          char(20),
    Destination     char(20),
    Source_date     date,
    Source_Time     time,
    Arr_date        date,
    Arr_Time        time,
    Price           numeric(10,2)
);

CREATE TABLE customers (
    Cust_Name       char(20)    PRIMARY KEY,
    Age             numeric(3),
    Sex             boolean
);

CREATE TABLE reservations (
    Cust_Name       char(20),
    AirlineID       numeric(10),
    HotelID         numeric(10),
    BusID           numeric(10),
    FOREIGN KEY (Cust_Name) REFERENCES customers(Cust_Name),
    FOREIGN KEY (AirlineID) REFERENCES flight(AirlineID),
    FOREIGN KEY (HotelID)   REFERENCES hotels(HotelID),
    FOREIGN KEY (BusID)     REFERENCES bus(BusID)
);
