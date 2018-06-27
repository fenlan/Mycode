#! /usr/bin/python3

import threading
import time
import os

class Bank:
    def __init__(self, balance):
        
        self.balance = balance
    def Withdraw(self, a):
        lock.acquire()
        if a > self.balance:
            print("Don't have enough money!!!")
            os._exit(0)
        else:
            self.balance -= a
            print("Took away ", str(a), " leaving：", str(self.balance))
        lock.release()
    def Deposit(self, a):
        lock.acquire()
        self.balance += a
        print("Get in ", str(a), " leaving：", str(self.balance))
        lock.release()

class Counter(threading.Thread):
    def run(self):
        global b
        b.Withdraw(100)
        time.sleep(0.1)
        b.Withdraw(150)

class ATM(threading.Thread):
    def run(self):
        global b
        b.Withdraw(300)
        b.Withdraw(700)

b = Bank(1000.0)
zhangsan = Counter()
lock = threading.Lock()
lisi = ATM()
zhangsan.start()
lisi.start()
