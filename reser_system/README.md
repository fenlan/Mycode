## reservation system
A simply program of reservation system, based on python and mysql.
Made just for fun. Play it here!
My teacher of Databses System Concepts gives the idea for me.

### how to use
- If you have not installed mysql in your computer, install it at first
- After you installed the mysql, you should create a database and name it as `reser_system`
- And then run the `create_tables.sql` to create needed tables
- Now run `get_flight_from_web.py` and `get_bus_from_web.py` to get data from web and insert into database
- run `insert_hotels_data.py` to insert hotels information
- At last run `reser.py` to book your travel route

## Tables
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

## Update
There are some faluts, and need to modify and add some other function
