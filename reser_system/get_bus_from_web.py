'''
    ------------------------------------------------------
    Author: fenlan
    Update: 2017.5.7
    function: Insert bus information into bus table
    run: python get_bus_from_web.py host username password table
    ------------------------------------------------------------
    Bus-------------BusID           numeric(10)    PRIMARY KEY
                ----BusNum          char(10)
                ----Source          char(20)
                ----Destination     char(20)
                ----Source_Time     datetime
                ----Arr_Time        datetime
                ----Price           numeric(10,2)
    ------------------------------------------------------------
'''
import os
import sys
import time
import MySQLdb
import urllib.request
from bs4 import BeautifulSoup
from datetime import *

def deal_time(time):
    time = time.replace(' ','')       #remove whitespace
    time = time.strip()               #remove '\n'
    time = datetime.strptime(time, "%H:%M")
    return time

def argv_check():
    if len(sys.argv) == 5:
        global host, username, password, table
        host = sys.argv[1]
        username = sys.argv[2]
        password = sys.argv[3]
        table = sys.argv[4]
    else :
        print('-------------------------------------------------------------')
        print('please run--> python get_bus_from_web.py host username password table')
        print('-------------------------------------------------------------')
        exit()

host = ''
username = ''
password = ''
table = ''

argv_check()

Source_date = date.today()
bus_ID = Source_date.strftime("%Y%m%d")
bus_ID = int(bus_ID)*100

url = "http://qiche.cncn.com/qiche_detail.php?city=%D7%F1%D2%E5&to_city=%D3%E0%C7%EC&Submit=%B2%E9%D1%AF"
html = urllib.request.urlopen(url).read()
soup = BeautifulSoup(html,"lxml")
div = soup.find("div",id="carPasses")
tbody = div.contents[1].contents[3]

db = MySQLdb.connect(host, username, password, table)
cursor = db.cursor()
cursor.execute("DELETE FROM bus")
db.commit()

for j in range(10):
    for i in tbody.find_all('tr'):
        bus_leaves_time = i.contents[1].contents[0].string
        bus_leaves_time = deal_time(bus_leaves_time)
        price = i.contents[9].contents[1].string
        bus_arr_time = bus_leaves_time + timedelta(hours=4)
        bus_leaves_time = bus_leaves_time.strftime("%H:%M:%S")
        bus_arr_time = bus_arr_time.strftime("%H:%M:%S")
        value = [bus_ID, bus_ID%100, Source_date, bus_leaves_time, Source_date, bus_arr_time, price]

        cursor.execute("INSERT INTO bus VALUES (%s,%s,'chongqing','zunyi',%s,%s,%s,%s,%s)", value)
        db.commit()
        bus_ID = bus_ID + 1

    Source_date = Source_date + timedelta(days=1)
    bus_ID = Source_date.strftime("%Y%m%d")
    bus_ID = int(bus_ID)*100


db.close()
