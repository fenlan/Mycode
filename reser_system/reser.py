'''
    ------------------------------------------------------
    Author: fenlan
    Update: 2017.5.9
    function: reservation system
    run: python reser.py host username password table
    ------------------------------------------------------
'''


import sys
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
        print('please run--> python reser.py host username password table')
        print('-------------------------------------------------------------')
        exit()

def account_check():
    global Cust_Name
    print('---------------------------------------------------------')
    Cust_Name = input('Your name is :')
    print('---------------------------------------------------------')
    cursor.execute("SELECT * From customers WHERE Cust_Name = %s", [Cust_Name])
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
    def query_flight_date():
        date = []
        value = []
        information = []
        def show_flight_date():
            print('---------------------------------------------------------')
            cursor.execute("SELECT Source_date FROM flight")
            Source_date = cursor.fetchall()

            for row in Source_date:
                if str(row[0]) not in date:
                    date.append(str(row[0]))
            for row in range(len(date)):
                print(row,'.',date[row])
            print('[if want to back to menu please input <back>]')
            print('---------------------------------------------------------')

        def show_date_flight():
            number = input('Choose one day to query: ')
            if number == 'back':
                menu()
            elif int(number) < len(date) :
                number = int(number)
                value.append(date[number])
                cursor.execute("SELECT * FROM flight WHERE Source_date = %s", value) # 'value' must use list
                information = cursor.fetchall()
                print('---------------------------------------------------------')
                for row in information:
                    print(row[0], ' ', row[3], ' ', row[5], ' ', row[7], ' ', row[8])
                print('[if want to back to menu please input <back>]')
                print('---------------------------------------------------------')
            else :
                out_of_range()

        def query_flight_destination():
            i = 0
            dest = input('Choose one destination :')
            if dest == 'back':
                menu()
            else :
                value.append(dest)
                print(value)
                cursor.execute("SELECT * FROM flight WHERE Source_date = %s AND Destination = %s", value)
                information = cursor.fetchall()
                print('---------------------------------------------------------')
                for row in information:
                    print(i, '.', row[0], ' ', row[3], ' ', row[5], ' ', row[7], ' ', row[8])
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
                value = [information[flight][0]]
                print('Your will book the flight ', information[flight][0], end=' .')
                confirm = input('Are you sure?(y/n)  ')
                if confirm == 'y':
                    cursor.execute("UPDATE reservations SET AirlineID = %s WHERE Cust_Name = 'fenlan'", value)
                    db.commit()
                    print('your have booked flight, and your flight ID is :', information[flight][0])
                else :
                    menu()
            else :
                out_of_range()

        show_flight_date()
        show_date_flight()
        information = query_flight_destination()
        choose_flight(information)

    query_flight_date()

def query_bus():
        def query_bus_date():
            date = []
            value = []
            information = []
            def show_bus_date():
                print('---------------------------------------------------------')
                cursor.execute("SELECT Source_date FROM bus")
                Source_date = cursor.fetchall()

                for row in Source_date:
                    if str(row[0]) not in date:
                        date.append(str(row[0]))
                for row in range(len(date)):
                    print(row,'.',date[row])
                print('[if want to back to menu please input <back>]')
                print('---------------------------------------------------------')

            def show_date_bus():
                number = input('Choose one day to query: ')
                if number == 'back':
                    menu()
                elif int(number) < len(date) :
                    number = int(number)
                    value.append(date[number])
                    cursor.execute("SELECT * FROM bus WHERE Source_date = %s", value) # 'value' must use list
                    information = cursor.fetchall()
                    print('---------------------------------------------------------')
                    for row in information:
                        print(row[0], ' ', row[3], ' ', row[5], ' ', row[7], ' ', row[8])
                    print('[if want to back to menu please input <back>]')
                    print('---------------------------------------------------------')
                else :
                    out_of_range()

            def query_bus_destination():
                i = 0
                dest = input('Choose one destination :')
                if dest == 'back':
                    menu()
                else :
                    value.append(dest)
                    print(value)
                    cursor.execute("SELECT * FROM bus WHERE Source_date = %s AND Destination = %s", value)
                    information = cursor.fetchall()
                    print('---------------------------------------------------------')
                    for row in information:
                        print(i, '.', row[0], ' ', row[3], ' ', row[5], ' ', row[7], ' ', row[8])
                        i = i+1
                    print('[if want to back to menu please input <back>]')
                    print('---------------------------------------------------------')
                    return information

            def choose_bus(information):
                bus = input('Choose one bus :')
                if bus == 'back':
                    menu()
                elif int(bus) < len(information) :
                    bus = int(bus)
                    value = [information[bus][0]]
                    print('Your will book the bus ', information[bus][0], end=' .')
                    confirm = input('Are you sure?(y/n)  ')
                    if confirm == 'y':
                        cursor.execute("UPDATE reservations SET BusID = %s WHERE Cust_Name = 'fenlan'", value)
                        db.commit()
                        print('your have booked bus, and your bus ID is :', information[bus][0])
                    else :
                        menu()
                else :
                    out_of_range()

            show_bus_date()
            show_date_bus()
            information = query_bus_destination()
            choose_bus(information)

        query_bus_date()

def query_hotel():
    def query_hotel_date():
        date = []
        value = []
        hotel = []
        information = []
        def query_hotel_name():
            print('---------------------------------------------------------')
            cursor.execute("SELECT Hotel_name FROM hotels")
            Hotel_name = cursor.fetchall()

            for row in Hotel_name:
                if str(row[0]) not in hotel:
                    hotel.append(str(row[0]))
            for row in range(len(hotel)):
                print(row,'.',hotel[row])
            print('[if want to back to menu please input <back>]')
            print('---------------------------------------------------------')

        def show_hotel_date():
            Hotel_num = input('Choose one hotel to query :')
            if Hotel_num == 'back':
                menu()
            elif int(Hotel_num) < len(hotel) :
                Hotel_num = int(Hotel_num)
                value.append(hotel[Hotel_num])
                print('---------------------------------------------------------')
                cursor.execute("SELECT CheckIn_date FROM hotels WHERE Hotel_name = %s", value)
                Source_date = cursor.fetchall()

                for row in Source_date:
                    if str(row[0]) not in date:
                        date.append(str(row[0]))
                for row in range(len(date)):
                    print(row,'.',date[row])
                print('[if want to back to menu please input <back>]')
                print('---------------------------------------------------------')
            else :
                out_of_range()

        def show_date_hotel():
            number = input('Choose one day to query: ')
            if number == 'back':
                menu()
            elif int(number) < len(date) :
                number = int(number)
                value.append(date[number])
                cursor.execute("SELECT * FROM hotels WHERE Hotel_name = %s AND CheckIn_date = %s AND Room_Status = 0", value) # 'value' must use list
                information = cursor.fetchall()
                print('---------------------------------------------------------')
                for row in information:
                    print(row[0], ' ', row[1], ' ', row[2], ' ', row[3], ' ', row[9])
                print('[if want to back to menu please input <back>]')
                print('---------------------------------------------------------')
            else :
                out_of_range()

        def choose_hotel():
            RoomID = input('Choose a room: ')
            if RoomID == 'back':
                menu()
            else :
                value.append(RoomID)
                cursor.execute("SELECT * FROM hotels WHERE Hotel_name = %s AND CheckIn_date = %s AND RoomID = %s AND Room_Status = 0", value)
                result = cursor.fetchall()
                if len(result) == 1:
                    print('Your will book the room ', result[0][3], end=' .')
                    confirm = input('Are you sure?(y/n)  ')
                    if confirm == 'y':
                        cursor.execute("UPDATE reservations SET HotelID = %s WHERE Cust_Name = 'fenlan'", [result[0][0]])
                        db.commit()
                        print('your have booked hotel, and your room ID is :', result[0][3])
                    else :
                        menu()
                else :
                    out_of_range()

        query_hotel_name()
        show_hotel_date()
        show_date_hotel()
        choose_hotel()

    query_hotel_date()

def query_account():
    cursor.execute("SELECT * FROM customers WHERE Cust_Name = %s", [Cust_Name])
    account = cursor.fetchone()
    print('---------------------------------------------------------')
    print('Your name :', account[0])
    print('Your age  :', account[1])
    if account[2]:
        print('Your sex  : male')
    else :
        print('Your sex  : female')
    print('---------------------------------------------------------')

def query_reservation():
    cursor.execute("SELECT * FROM reservations WHERE Cust_Name = %s", [Cust_Name])
    account = cursor.fetchone()
    if account[1] or account[2] or account[3]:
        print('---------------------------------------------------------')
        if account[1]:
            cursor.execute("SELECT Source,Destination,Source_date,Source_Time,Arr_date,Arr_Time,Price FROM flight WHERE AirlineID = %s",[account[1]])
            flight = cursor.fetchone()
            print('flight: ', flight[0],' ', flight[1],' ', flight[2],' ', flight[3], end=' ')
            print(flight[4], ' ', flight[5], ' ', flight[6])
        if account[3]:
            cursor.execute("SELECT Source,Destination,Source_date,Source_Time,Arr_date,Arr_Time,Price FROM bus WHERE BusID = %s",[account[3]])
            bus = cursor.fetchone()
            print('bus  : ', bus[0],' ', bus[1],' ', bus[2],' ', bus[3], end=' ')
            print(bus[4], ' ', bus[5], ' ', bus[6])
        if account[2]:
            cursor.execute("SELECT Hotel_name,Location,RoomID,CheckIn_date,Price FROM hotels WHERE HotelID = %s",[account[2]])
            hotel = cursor.fetchone()
            print('hotel: ', hotel[0],' ', hotel[1],' ', hotel[2],' ', hotel[3],' ', hotel[4])
    else :
        print('You have not book anything!')

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
table = ''

argv_check()
db = MySQLdb.connect(host, username, password, table)
cursor = db.cursor()
account_check()

while True :
    menu()

db.close()
