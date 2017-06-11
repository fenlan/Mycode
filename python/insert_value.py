'''
    ------------------------------------------------------
    Author: fenlan
    Update: 2017.5.30
    function: Insert information into tables
    ------------------------------------------------------
    Flight----------AirNum          char(10)       PRIMARY KEY
                ----numSeats        int(3)
                ----numAvail        int(3)
                ----FromCity        char(30)
                ----ArivCity        char(30)
                ----Price           int(5)
    -------------------------------------------------------
    Bus-------------location        varchar(50)    PRIMARY KEY
                ----numBus          int(2)
                ----numAvail        int(2)
                ----Price           int(3)
    -------------------------------------------------------
    Hotels----------location        varchar(50)     PRIMARY KEY
                ----numRooms        int(4)
                ----numAvail        int(4)
                ----Price           int(4)
    -------------------------------------------------------
'''

import os
import sys
import MySQLdb
import urllib.request
from bs4 import BeautifulSoup

def argv_check():
    if len(sys.argv) == 5:
        global host, username, password, database
        host = sys.argv[1]
        username = sys.argv[2]
        password = sys.argv[3]
        database = sys.argv[4]
    else :
        print('-------------------------------------------------------------')
        print('please run--> python insert_value.py host username password database')
        print('-------------------------------------------------------------')
        exit()

def insert_flights_value():
    url = "http://flights.ctrip.com/schedule/sia.ckg.html?P+"
    html = urllib.request.urlopen(url).read()
    soup = BeautifulSoup(html,"lxml")
    td = soup.find("tbody",id="flt1")

    db = MySQLdb.connect(host, username, password, database)
    cursor = db.cursor()
    cursor.execute("DELETE FROM flights")
    db.commit()

    for i in td.find_all('tr'):
        flight_name = i.contents[1].contents[1].contents[1].contents[0]
        cursor.execute("SELECT flightNum FROM flights WHERE flightNum = %s",[flight_name])
        flight = cursor.fetchone()

        if len(i.contents[13].contents) > 1 and flight == None:                #the price of some flights is not given, so jump there flights
            price = i.contents[13].contents[1].contents[1]
            value = [flight_name,'100','100','xian','chongqing',price]

            cursor.execute("INSERT INTO flights VALUES (%s,%s,%s,%s,%s,%s)", value)
            db.commit()

    db.close()

def insert_bus_value():
    url = "http://bus.ctrip.com/schedule/chongqing-zunyi/"
    html = urllib.request.urlopen(url).read()
    soup = BeautifulSoup(html,"lxml")
    table = soup.find("table",id="tb_railway_list")

    db = MySQLdb.connect(host, username, password, database, charset='utf8')
    cursor = db.cursor()
    cursor.execute("DELETE FROM bus")
    db.commit()

    for i in table.find_all('tr'):
        if len(i.contents[3]) > 1:
            location = i.contents[3].contents[1]
            price = i.contents[11].contents[1].contents[1].contents[0]
            cursor.execute("SELECT location FROM bus WHERE location = %s",[location])
            bus = cursor.fetchone()

            if bus == None:
                value = [location,'50','50',price]
                cursor.execute("INSERT INTO bus VALUES (%s,%s,%s,%s)",value)
                db.commit()

    db.close()

def insert_hotel_value():
    db = MySQLdb.connect(host, username, password, database, charset='utf8')
    cursor = db.cursor()
    cursor.execute("DELETE FROM hotels")
    db.commit()

    sql1 = "INSERT INTO hotels VALUES ('江北区金沙门路66号', '300', '300', '921')"
    sql2 = "INSERT INTO hotels VALUES ('渝中区上清寺中山四路上曾家岩24号', '300', '300', '432')"
    sql3 = "INSERT INTO hotels VALUES ('渝北区红锦大道609号', '300', '300', '494')"
    sql4 = "INSERT INTO hotels VALUES ('渝北区泰山大道东段116号', '300', '300', '664')"
    sql5 = "INSERT INTO hotels VALUES ('渝中区渝州路168号', '300', '300', '580')"
    sql6 = "INSERT INTO hotels VALUES ('渝中区石油路虎头岩18号', '300', '300', '355')"
    sql7 = "INSERT INTO hotels VALUES ('渝北区龙山街道旗龙路2号', '300', '300', '560')"
    cursor.execute(sql1)
    cursor.execute(sql2)
    cursor.execute(sql3)
    cursor.execute(sql4)
    cursor.execute(sql5)
    cursor.execute(sql6)
    cursor.execute(sql7)
    db.commit()

    db.close()

def insert_customer_value():
    db = MySQLdb.connect(host, username, password, database, charset='utf8')
    cursor = db.cursor()
    cursor.execute("DELETE FROM customers")
    db.commit()

    sql = "INSERT INTO customers VALUES ('1', 'fenlan')"
    cursor.execute(sql)
    db.commit()

    db.close()

host = ''
username = ''
password = ''
database = ''

headers = {'Accept' : 'text/html,application/xhtml+xml,application/xml',
        'Accept-Encoding' : 'gzip, deflate, sdch',
        'Accept-Language' : 'en-US,en;q=0.8,zh-CN;q=0.6,zh;q=0.4',
        'Connection' : 'keep-alive',
        'Host' : 'hotel.qunar.com',
        'Referer' : 'https://www.google.com/',
        'Upgrade-Insecure-Requests' : '1',
        'User-Agent' : 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.36',
        }

argv_check()
insert_flights_value()
insert_bus_value()
insert_hotel_value()
insert_customer_value()
