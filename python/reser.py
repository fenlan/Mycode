'''
    ------------------------------------------------------
    Author: fenlan
    Update: 2017.5.9
    function: reservation system
    run: python reser.py host username password database
    ------------------------------------------------------
'''


import sys
import MySQLdb
from datetime import *

def argv_check():
    if len(sys.argv) == 5:
        global host, username, password, database
        host = sys.argv[1]
        username = sys.argv[2]
        password = sys.argv[3]
        database = sys.argv[4]
    else :
        print('-------------------------------------------------------------')
        print('please run--> python reser.py host username password database')
        print('-------------------------------------------------------------')
        exit()

def account_check():
    global Cust_Name
    print('---------------------------------------------------------')
    Cust_Name = input('Your name is :')
    print('---------------------------------------------------------')
    cursor.execute("SELECT * From customers WHERE custName = %s", [Cust_Name])
    customers = cursor.fetchall()
    if customers :
        pass
    else :
        print('Your are not the user of this reservation system!')
        db.close()
        exit()

def welcome_information():
    print('---------------------------------------------------------')
    print('          Welcome to reservation system')
    print('---------------------------------------------------------')
    print('0.query the information of flight')
    print('1.query the information of bus')
    print('2.query the information of hotel')
    print('3.query your account')
    print('4.query your reservation')
    print('[if want to exit please input <exit>]')
    print('---------------------------------------------------------')

def query_flight():
    def query_flight_data():
        flight_Num = []
        value = []
        information = []
        def show_flight():
            print('---------------------------------------------------------')
            cursor.execute("SELECT * FROM flights")
            flights = cursor.fetchall()
            for row in flights:
                flight_Num.append(str(row[0]))
                print(row)

            print('[if want to back to menu please input <back>]')
            print('---------------------------------------------------------')

        def query_flight_destination():
            i = 0
            dest = input('Choose one destination :')
            if dest == 'back':
                menu()
            else :
                value = [dest]
                print(value)
                cursor.execute("SELECT * FROM flights WHERE ArivCity = %s", value)
                information = cursor.fetchall()
                print('---------------------------------------------------------')
                for row in information:
                    print(i, '.', row[0], ' ', row[2], ' ', row[3], ' ', row[4], ' ', row[5])
                    i = i+1
                print('[if want to back to menu please input <back>]')
                print('---------------------------------------------------------')
                return information

        def choose_flight(information):
            flight = input('Choose one flight :')
            if flight == 'back':
                menu()
            elif int(flight) < len(information) :
                flight = int(flight)
                value.append(Cust_Name)
                value.append(information[flight][0])
                print('Your will book the flight ', information[flight][0], end=' .')
                confirm = input('Are you sure?(y/n)  ')
                if confirm == 'y':
                    cursor.execute("SELECT resvKey FROM reservations WHERE custName = %s AND resvKey = %s", value)
                    res = cursor.fetchone()
                    if res:
                        print("\nyou have booked this flight!")
                        print("Please look up your reservations information.\n")
                    else:
                        cursor.execute("INSERT INTO reservations VALUES (%s,'1',%s)", value)
                        cursor.execute("UPDATE flights SET numAvail = numAvail - 1 WHERE flightNum = %s", [information[flight][0]])
                        db.commit()
                        print('your have booked flight, and your flight ID is :', information[flight][0])
                else :
                    menu()
            else :
                out_of_range()

        show_flight()
        information = query_flight_destination()
        choose_flight(information)

    query_flight_data()

def query_bus():
    def query_bus_data():
        location = []
        value = []
        def show_bus():
            print('---------------------------------------------------------')
            i = 0
            cursor.execute("SELECT * FROM bus")
            buses = cursor.fetchall()
            for row in buses:
                location.append(str(row[0]))
                print(i, '.', row[0],' numAvail:', row[2], ' Price:', row[3])
                i = i + 1

            print('[if want to back to menu please input <back>]')
            print('---------------------------------------------------------')

        def choose_bus():
            bus = input('Choose one bus :')
            if bus == 'back':
                menu()
            elif int(bus) < len(location) :
                bus = int(bus)
                value.append(Cust_Name)
                value.append(location[bus])
                print('Your will book the bus ', location[bus], end=' .')
                confirm = input('Are you sure?(y/n)  ')
                if confirm == 'y':
                    cursor.execute("SELECT resvKey FROM reservations WHERE custName = %s AND resvKey = %s", value)
                    res = cursor.fetchone()
                    if res:
                        print("\nyou have booked this bus!")
                        print("Please look up your reservations information.\n")
                    else:
                        cursor.execute("INSERT INTO reservations VALUES (%s,'2',%s)", value)
                        cursor.execute("UPDATE bus SET numAvail = numAvail - 1 WHERE location = %s", [location[bus]])
                        db.commit()
                        print('your have booked bus, and your bus location is :', location[bus])
                else :
                    menu()
            else :
                out_of_range()

        show_bus()
        choose_bus()

    query_bus_data()

def query_hotel():
    def query_hotel_data():
        location = []
        value = []
        def show_hotel():
            print('---------------------------------------------------------')
            i = 0
            cursor.execute("SELECT * FROM hotels")
            hotels = cursor.fetchall()
            for row in hotels:
                location.append(str(row[0]))
                print(i, '.', row[0],' numAvail:', row[2], ' Price:', row[3])
                i = i + 1

            print('[if want to back to menu please input <back>]')
            print('---------------------------------------------------------')

        def choose_hotel():
            hotel = input('Choose one bus :')
            if hotel == 'back':
                menu()
            elif int(hotel) < len(location) :
                hotel = int(hotel)
                value.append(Cust_Name)
                value.append(location[hotel])
                print('Your will book the hotel ', location[hotel], end=' .')
                confirm = input('Are you sure?(y/n)  ')
                if confirm == 'y':
                    cursor.execute("SELECT resvKey FROM reservations WHERE custName = %s AND resvKey = %s", value)
                    res = cursor.fetchone()
                    if res:
                        print("\nyou have booked this hotel!")
                        print("Please look up your reservations information.\n")
                    else:
                        cursor.execute("INSERT INTO reservations VALUES (%s,'3',%s)", value)
                        cursor.execute("UPDATE hotels SET numAvail = numAvail - 1 WHERE location = %s", [location[hotel]])
                        db.commit()
                        print('your have booked hotel, and your hotel location is :', location[hotel])
                else :
                    menu()
            else :
                out_of_range()

        show_hotel()
        choose_hotel()

    query_hotel_data()

def query_account():
    cursor.execute("SELECT * FROM customers WHERE CustName = %s", [Cust_Name])
    account = cursor.fetchone()
    print('---------------------------------------------------------')
    print()
    print('Your ID :', account[0])
    print('Your name  :', account[1])
    print()
    print('---------------------------------------------------------')

def query_reservation():
    cursor.execute("SELECT * FROM reservations WHERE CustName = %s", [Cust_Name])
    account = cursor.fetchall()
    print()
    for row in account:
        if row[1] == 1:
            print('flight:', row[2])
        elif row[1] == 2:
            print('bus:', row[2])
        elif row[1] == 3:
            print('hotel:', row[2])
    print()

def menu():
    welcome_information()
    query_number = input('Choose a number: ')
    if query_number == 'exit':
        print('bye-bye')
        db.close()
        exit()
    elif int(query_number) < len(options) :
        options[query_number]()
    else :
        out_of_range()

def out_of_range():
    print('*********************************************************')
    print('*                   out of range!                       *')
    print('*********************************************************')
    menu()

options = {'0' : query_flight,
    '1' : query_bus,
    '2' : query_hotel,
    '3' : query_account,
    '4' : query_reservation,
}
Cust_Name = ''
host = ''
username = ''
password = ''
database = ''

argv_check()
db = MySQLdb.connect(host, username, password, database, charset='utf8')
cursor = db.cursor()
account_check()

while True :
    menu()

db.close()
