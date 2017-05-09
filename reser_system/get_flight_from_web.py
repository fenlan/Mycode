'''
    ------------------------------------------------------
    Author: fenlan
    Update: 2017.5.6
    function: Insert flight information into flight table
    ------------------------------------------------------
    Flight----------AirlineID       numeric(10)    PRIMARY KEY
                ----AirNum          char(10)
                ----Source          char(20)
                ----Destination     char(20)
                ----Source_Time     datetime
                ----Arr_Time        datetime
                ----Price           numeric(10,2)
    -------------------------------------------------------
'''
import os
import sys
import time
import MySQLdb
import urllib.request
from bs4 import BeautifulSoup
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
        print('please run--> python get_fligth_from_web.py host username password table')
        print('-------------------------------------------------------------')
        exit()

host = ''
username = ''
password = ''
table = ''

argv_check()

Source_date = date.today()
ID = Source_date.strftime("%Y%m%d")
ID = int(ID)*100

url = "http://flights.ctrip.com/schedule/sia.ckg.html?P+"
html = urllib.request.urlopen(url).read()
soup = BeautifulSoup(html,"lxml")
td = soup.find("tbody",id="flt1")

db = MySQLdb.connect(host, username, password, table)
cursor = db.cursor()
cursor.execute("DELETE FROM flight")
db.commit()

for j in range(10):
    for i in td.find_all('tr'):
        flight_name = i.contents[1].contents[1].contents[1].contents[0]
        flight_source_time = i.contents[3].contents[1].contents[0]
        flight_arr_time = i.contents[7].contents[1].contents[0]
        if len(i.contents[13].contents) > 1:                #the price of some flights is not given, so jump there flights
            price = i.contents[13].contents[1].contents[1]
            value = [ID, flight_name, Source_date, flight_source_time, Source_date, flight_arr_time, price]

            cursor.execute("INSERT INTO flight VALUES (%s,%s,'xian','chongqing',%s,%s,%s,%s,%s)", value)
            db.commit()
            ID = ID + 1

    Source_date = Source_date + timedelta(days=1)
    ID = Source_date.strftime("%Y%m%d")
    ID = int(ID)*100

db.close()
