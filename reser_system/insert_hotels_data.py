'''
    ------------------------------------------------------
    Author: fenlan
    Update: 2017.5.7
    function: Insert hotel information into hotel table
    ------------------------------------------------------------
    Hotels----------HotelID         numeric(10)     PRIMARY KEY
                ----Hotel_name      char(20)
                ----Location        char(50)
                ----RoomID          char(5)
                ----CheckIn_Time    datetime
                ----CheckOut_Time   datetime
                ----Room_Status     bool
                ----Price           numeric(10,2)
    ------------------------------------------------------------
'''
import os
import sys
import time
import MySQLdb
from datetime import *

def argv_check():
    if len(sys.argv) == 5:
        global host, username, password, table
        host = sys.argv[1]
        username = sys.argv[2]
        password = sys.argv[3]
        table = sys.argv[4]
    else :
        print('-------------------------------------------------------------')
        print('please run--> python insert_hotel_data.py host username password table')
        print('-------------------------------------------------------------')
        exit()

host = ''
username = ''
password = ''
table = ''

argv_check()

CheckIn_date = date.today()
CheckOut_date = CheckIn_date + timedelta(days=1)
hotel_ID = CheckIn_date.strftime("%Y%m%d")
hotel_ID = int(hotel_ID)*100
Location = '57 Beijing Rd, Huichuan Qu, Zunyi, Guizhou'
Hotel_name = 'Shenzhenair'
Room_Status = False

db = MySQLdb.connect(host, username, password, table)
cursor = db.cursor()
cursor.execute("DELETE FROM hotels")
db.commit()

for k in range(10):
    for i in range(1,6):
        for j in range(20):
            RoomID = i * 100 + j
            value = [hotel_ID, Hotel_name, Location, RoomID, CheckIn_date, CheckOut_date, Room_Status]
            cursor.execute("INSERT INTO hotels VALUES (%s,%s,%s,%s,%s,'12:00:00',%s,'13:00:00',%s,'200')", value)
            db.commit()
            hotel_ID = hotel_ID + 1

    CheckIn_date = CheckIn_date + timedelta(days=1)
    CheckOut_date = CheckOut_date + timedelta(days=1)

db.close()
