#! /usr/bin/python3

import threading
import time
import os

def boxOffice(threadID):
    global tickets
    global lock
    while True:
        lock.acquire()
        if tickets != 0:
            tickets = tickets - 1
            print("BOX:", threadID, ", leaving:", tickets)
            time.sleep(0.1)
        else:
            print("Thread_id", threadID, "No more tickets")
            os._exit(0)
        lock.release()
        time.sleep(0.1)

tickets = 30
lock=threading.Lock()

for k in range(5):
    new_thread = threading.Thread(target=boxOffice, args=(k,))
    new_thread.start()
