import os
import sys
import urllib.request
from bs4 import BeautifulSoup

url = "http://flights.ctrip.com/schedule/sia.ckg.html?P+"
html = urllib.request.urlopen(url).read()
soup = BeautifulSoup(html,"lxml")
td = soup.find("tbody",id="flt1")

for i in td.find_all('tr'):
    #print(i.contents[1].contents[1].contents[1].contents[0])    #get flight_name
    #print(i.contents[3].contents[1].contents[0])                #get flight_source_time
    #print(i.contents[7].contents[1].contents[0])                #get flight_arr_time
    print(i.contents[13].contents[1].contents[1])                #get price
